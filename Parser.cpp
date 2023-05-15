#include "Parser.h"

Parser::Parser(string command) {
    fail_flag = false;

    // Parsing into command tokens & loading to the input queue
    STokenizer stk(command);
    Token t;
    string composite;
    while(!stk.done()) {
        t = Token();
        stk >> t;
        if(t.type() != SPACE) {
            // acommodating multiple parentheses
            if ((t.token_str().at(0) == '(' || t.token_str().at(0) == ')') &&
                t.token_str().length() > 1) {
                for(size_t i=0; i<t.token_str().length(); i++)
                    input_q.push(t.token_str().substr(i, 1));
            }
            // "" marks
            else if(t.token_str().at(0) == '\"') {
                for(size_t i=1; i<t.token_str().length(); i++)  // opening "_
                    composite += t.token_str().substr(i, 1);
                //stk >> t;
                bool end_concat = false;
                while (!stk.done() && !end_concat) {
                    stk >> t;
                    if(t.type() == PUNCT) {     // closing ." ",
                        for(size_t i=0; i<t.token_str().length(); i++) {
                            string punct = t.token_str().substr(i, 1);
                            if(punct != "\"")
                                composite += punct;
                            else {
                                input_q.push(composite);
                                composite.clear();
                                for(size_t j=i+1; j<t.token_str().length(); j++)
                                    input_q.push(t.token_str().substr(j, 1));
                                i = t.token_str().length();
                                end_concat = true;
                            }
                        }
                    }
                    else
                        composite += t.token_str();
                }
                if(!composite.empty()) {
                    input_q.push(composite);
                    composite.clear();
                }
            }
            else
                input_q.push(t.token_str());
        }
    }///cout << input_q << '\n'; // DEBUG


    build_adjacency_matrix();
    build_keyword_map();
    string fail_token;
    fail_flag = !build_parse_tree(fail_token);

    if(fail_flag) {
        cout << "\nCommand \'" << command << "\' not found\n";
        string ws(9 + command.find(fail_token, 0), ' ');
        if(command != "")
            cout << ws << "^\n";
    }
}


// === HELPER FUNCTIONS ======================================================
void Parser::build_keyword_map() {
    keywords.insert("select", SELECT);
    keywords.insert("from", FROM);
    keywords.insert("where", WHERE);
    keywords.insert("*", STAR);
    keywords.insert(",", COMMA);
    keywords.insert("and", CONNECTOR);
    keywords.insert("or", CONNECTOR);
    keywords.insert("&&", CONNECTOR);
    keywords.insert("||", CONNECTOR);
    keywords.insert("(", PAREN);
    keywords.insert(")", PAREN);
    keywords.insert("\"", QUOT);
    keywords.insert("make", BUILD);
    keywords.insert("create", BUILD);
    keywords.insert("table", TABLE);
    keywords.insert("fields", FIELDS);
    keywords.insert("insert", INSERT);
    keywords.insert("values", VALUES);
    keywords.insert("into", INTO);
    keywords.insert("batch", BATCH);
    //...
}

void Parser::build_adjacency_matrix() {
    for (unsigned i = 0; i < ROWS; i++)
        for(unsigned j = 0; j < COLUMNS; j++)
            adj_matrix[i][j] = -1;

    adj_matrix[0][STATE_BOOL] = fail;        // start-state is a fail state

    for(int i=0; i<ROWS; i++)
        adj_matrix[i][STATE_BOOL] = fail;

    adj_matrix[4][STATE_BOOL] = success;     // 4th state is a success state
    adj_matrix[8][STATE_BOOL] = success;     // 8th state is a success state
    adj_matrix[16][STATE_BOOL] = success;    // 16th state is a success state
    adj_matrix[22][STATE_BOOL] = success;    // 22nd state is a success state
    adj_matrix[25][STATE_BOOL] = success;    // 25th state success

    adj_matrix[0][SELECT] = 1;      adj_matrix[0][BUILD] = 12;
    adj_matrix[0][INSERT] = 18;     adj_matrix[0][BATCH] = 24;

    // SELECT COMMAND SEQUENCE
    adj_matrix[1][SYMBOL] = 2;      adj_matrix[1][STAR] = 9;
    adj_matrix[2][FROM] = 3;        adj_matrix[2][COMMA] = 10;
    adj_matrix[3][SYMBOL] = 4;
    adj_matrix[4][WHERE] = 5;
    adj_matrix[5][SYMBOL] = 6;      adj_matrix[5][PAREN] = 5;
    adj_matrix[6][SYMBOL] = 7;      adj_matrix[6][PAREN] = 6;
    adj_matrix[7][SYMBOL] = 8;      adj_matrix[7][PAREN] = 7;
    adj_matrix[8][CONNECTOR] = 11;  adj_matrix[8][PAREN] = 8;
    adj_matrix[9][FROM] = 3;
    adj_matrix[10][SYMBOL] = 2;
    adj_matrix[11][SYMBOL] = 6;     adj_matrix[11][PAREN] = 11;

    // MAKE/CREATE COMMAND SEQUENCE
    adj_matrix[12][TABLE] = 13;
    adj_matrix[13][SYMBOL] = 14;
    adj_matrix[14][FIELDS] = 15;
    adj_matrix[15][SYMBOL] = 16;
    adj_matrix[16][COMMA] = 17;
    adj_matrix[17][SYMBOL] = 16;

    //INSERT COMMAND SEQUENCE
    adj_matrix[18][INTO] = 19;
    adj_matrix[19][SYMBOL] = 20;
    adj_matrix[20][VALUES] = 21;
    adj_matrix[21][SYMBOL] = 22;
    adj_matrix[22][COMMA] = 23;
    adj_matrix[23][SYMBOL] = 22;

    //BATCH COMMAND SEQUENCE
    adj_matrix[24][SYMBOL] = 25;
}

int Parser::get_column(string token) {
    return (keywords.contains(token)) ? keywords[token] : SYMBOL;
}

bool Parser::build_parse_tree(string& fail_token) {
    string command_token;
    int current_state = 0;


    while (!input_q.empty() && !fail_flag) {
        command_token = input_q.pop();
        current_state = adj_matrix[current_state][get_column(command_token)];

        switch (current_state) {
        case -1:
            ptree.clear();
            fail_token = command_token;
            return false;
        case 1:
        case 12:
        case 18:
        case 24:
            ptree.insert("Command", command_token);
            break;
        case 2:
        case 9:                                             // ASTERISK
        case 16:
        case 22:
            ptree.insert("Fields", command_token);
            break;
        case 4:
        case 14:
        case 20:
            ptree.insert("Table", command_token);
            break;
        case 5:
            if(command_token == ")" || command_token == "(")    // PARENTHESES
                ptree.insert("Condition", command_token);
            break;
        case 6:
            ptree.insert("Condition", command_token);
            break;
        case 7:
            ptree.insert("Condition", command_token);
            break;
        case 8:
            ptree.insert("Condition", command_token);
            break;
        case 11:
            ptree.insert("Condition", command_token);   // AND / OR
            break;
        case 25:
            ptree.insert("File", command_token);        // BATCH FILE
            break;

        default:
            break;
        }
    }

    if(adj_matrix[current_state][STATE_BOOL] == success)
        return true;
    else {
        ptree.clear();
        fail_token = command_token;
        return false;
    }
}
