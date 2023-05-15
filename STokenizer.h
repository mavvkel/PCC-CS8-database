#ifndef STOKENIZER_H
#define STOKENIZER_H
#include <cstring>
#include <cctype>
#include "Token.h"

class STokenizer {
    public:
        STokenizer();
        STokenizer(char str[]);
        STokenizer(string str);

        bool more();            // there are more tokens to read
        bool done();            // there are no more tokens



        friend STokenizer& operator>>(STokenizer& s, Token& t);
                                // get the next token from the string

        void set_string(char str[]);
                                // set the new string as the input string

    private:
        void make_table(int _table[][MAX_COLUMNS]);
                                // table for the tokens recognized

        bool get_token(string& token);
                                // get the longest string (acceptable token)


        char _buffer[MAX_BUFFER];       // input string
        size_t _pos;                       // current position in the string
        int _table[MAX_ROWS][MAX_COLUMNS];

};

#endif // STOKENIZER_H
