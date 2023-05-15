#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "Constants.h"
using std::string;
using std::ostream;

class Token {
    public:
        Token();
        Token(string str, int type);
        int type();
        string string_type();
        string token_str();
        friend ostream& operator<<(ostream& outs, const Token &t);

    private:
        string _token;
        int _type;
};

#endif // TOKEN_H
