#ifndef FTOKENIZER_H
#define FTOKENIZER_H
#include <fstream>
#include "STokenizer.h"


class FTokenizer {
    public:
        FTokenizer(char* fname);
        Token next_token();
        bool more();
        bool done();
        friend FTokenizer& operator>>(FTokenizer& s, Token& t);

    private:
        bool get_new_block();   //gets new block from the file
        std::ifstream fin;
        STokenizer _stk;        //STokenizer to tokenize current block
        bool _more;             //False if the last token on the lastt block
                                // has been processed and now we are at the end
                                // of the last block


};

#endif // FTOKENIZER_H
