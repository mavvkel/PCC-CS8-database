#include "make_table_functions.h"
#include "STokenizer.h"

STokenizer::STokenizer()
{
    memset(_buffer, 0, sizeof(_buffer));
    _pos = 0;
    make_table(_table);
}

STokenizer::STokenizer(char str[]) {
    strcpy(_buffer, str);
    _pos = 0;
    make_table(_table);
}

STokenizer::STokenizer(string str) {

    strcpy(_buffer, str.c_str());
    _pos = 0;
    make_table(_table);
}

bool STokenizer::more() {
    return static_cast<unsigned>(_pos) < strlen(_buffer);
}

bool STokenizer::done() {
    return static_cast<unsigned>(_pos) >= strlen(_buffer);
}

STokenizer& operator>>(STokenizer& s, Token& t) {
    int t_type = UNKNWN;
    string token;
    if(isalpha(s._buffer[s._pos]))
        t_type = ALPHA;
    else if (isdigit(s._buffer[s._pos]))
        t_type = NUM;
    else if (ispunct(s._buffer[s._pos]))
        t_type = PUNCT;
    else if (isspace(s._buffer[s._pos]))
        t_type = SPACE;
    else
        t_type = UNKNWN;


    if(s.get_token(token))
        t = Token(token, t_type);

    return s;
}

void STokenizer::set_string(char *str) {
    strcpy(_buffer, str);
    _pos = 0;
}

void STokenizer::make_table(int _table[][MAX_COLUMNS]) {
    for (unsigned i = 0; i < MAX_ROWS; i++)
        for(unsigned j = 0; j < MAX_COLUMNS; j++)
            _table[i][j] = -1;

    _table[0][0] = fail;       // start-state is a fail state

    // ====================== ALPHA ================================
    mark_cells(0, _table, 'A', 'Z', 1);     // setting AB..YZ to state 1
    mark_cells(0, _table, 'a', 'z', 1);     // setting ab..yz to state 1
    mark_cells(1, _table, 'A', 'Z', 1);     // setting AB..YZ to state 1
    mark_cells(1, _table, 'a', 'z', 1);     // setting ab..yz to state 1
    _table[1][0] = success;

    // ====================== PUNCT ================================
    mark_cells(0, _table, '!', '/', 2);     // setting !".../ to state 2
    mark_cells(0, _table, ':', '@', 2);     // setting :;..?@ to state 2
    mark_cells(0, _table, '[', '`', 2);    // setting [\.._' to state 2
    mark_cells(0, _table, '{', '~', 2);    // setting {\}~ to state 2
    mark_cells(2, _table, '!', '/', 2);     // setting !".../ to state 2
    mark_cells(2, _table, ':', '@', 2);     // setting :;..?@ to state 2
    mark_cells(2, _table, '[', '`', 2);    // setting [\.._' to state 2
    mark_cells(2, _table, '{', '~', 2);    // setting {\}~ to state 2
    _table[2][0] = success;

    // ====================== WHITE SPACE ===========================
    _table[0][static_cast<int>(' ')] = 3;   // setting up white space chars to
    _table[0][static_cast<int>('\t')] = 3;  // state 3 for initial state
    _table[0][static_cast<int>('\r')] = 3;
    _table[0][static_cast<int>('\n')] = 3;
    _table[0][static_cast<int>('\v')] = 3;
    _table[0][static_cast<int>('\f')] = 3;
    _table[3][static_cast<int>(' ')] = 3;   // -||- for the 3rd state
    _table[3][static_cast<int>('\t')] = 3;
    _table[3][static_cast<int>('\r')] = 3;
    _table[3][static_cast<int>('\n')] = 3;
    _table[3][static_cast<int>('\v')] = 3;
    _table[3][static_cast<int>('\f')] = 3;
    _table[3][0] = success;

    // ====================== NUMBERS ===============================
    mark_cells(0, _table, '0', '9', 4);     // setting initial char recognition
    mark_cells(4, _table, '0', '9', 4);     // setting a loop on 4th state
    _table[4][static_cast<int>('.')] = 5;   // input of a decimal
    mark_cells(5, _table, '0', '9', 6);     // setting a loop on 4th state
    mark_cells(6, _table, '0', '9', 6);     // setting a loop on 4th state
    _table[4][0] = success;
    _table[5][0] = fail;
    _table[6][0] = success;
}

bool STokenizer::get_token(string &token) {
    token.clear();
    bool token_found = false;
    string tmp(_buffer);

    unsigned last_successfull_position = _pos;
    unsigned current_pos = _pos;
    int current_state = 0;


    while(current_state != -1 && _buffer[current_pos] != '\0') {
        current_state = _table[current_state][static_cast<int>(
                    _buffer[current_pos])];


        if(current_state != -1) {
            if(_buffer[current_pos] >= 0 && _table[current_state][0] != fail)
            last_successfull_position = current_pos;
            token = tmp.substr(_pos, last_successfull_position - _pos + 1);
            token_found = true;
            current_pos++;
            if(_buffer[current_pos] < 0)
                break;
        }

        if(_buffer[last_successfull_position] < 0)
            current_state = -1;
    }

    _pos = ++last_successfull_position;
    return token_found;
}
