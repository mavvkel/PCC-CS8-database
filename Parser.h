//////////////////////////////////////////////////////////////////////////////
///
///     Parser class:
///     @abstract Parses the command and translates it to Map of strings
///             for the Table class
///
///     @param  uses Map, Queue, STokenizer and Multimap
///     @param  the size of a command is restriced by STokenizer buffer size
///             (currently 200)
///     @param  before the opening " has to be a non PUNCT token
///     @param  symbols with only PUNCT input in quotes f.e. ",." are not
///             allowed
///     @param  if Parser fails, it will display the place of the failing Token
///             in the input command
///
///     @note   uses concepts of tokenization of input, enum and typedef
///
//////////////////////////////////////////////////////////////////////////////
#ifndef PARSER_H
#define PARSER_H
#include "MultiMap.h"
#include "Map.h"
#include "queue.h"
#include "STokenizer.h"

const int ROWS = 30;
const int COLUMNS = 30;

class Parser {
        typedef MultiMap<string, string> MMstr;
    public:
        Parser(string command);

        // === ACCESSORS === //
        MMstr get_ptree() {return ptree;}           // INLINED

    private:
        MMstr ptree;
        Map<string, int> keywords;
        int adj_matrix[ROWS][COLUMNS];
        bool fail_flag;
        Queue<string> input_q;
        enum COMMAND_TOKENS {STATE_BOOL, SELECT, FROM, WHERE, SYMBOL, STAR,
                             COMMA, CONNECTOR, PAREN, QUOT, BUILD, TABLE,
                             FIELDS, INSERT, VALUES, INTO, BATCH};


        // === HELPER FUNCTIONS === //
        void build_keyword_map();
        void build_adjacency_matrix();
        int get_column(string token);
        bool build_parse_tree(string& fail_token);
};

#endif // PARSER_H
