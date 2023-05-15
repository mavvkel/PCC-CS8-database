#include "Token.h"

Token::Token() {
    _token = "";
    _type = EMPTY;
}

Token::Token(string str, int type) {
    _token = str;
    _type = type;
}

int Token::type() {
    return _type;
}

string Token::string_type() {
    switch (_type) {
    case ALPHA:
        return "ALPHA";
    case NUM:
        return "NUM";
    case PUNCT:
        return "PUNCT";
    case SPACE:
        return "W SPACE";
    case EMPTY:
        return "EMPTY";
    default:
        return "UKNOWN";
    }
}

string Token::token_str() {
    return _token;
}

ostream& operator<<(ostream& outs, const Token &t) {
    outs << "|" << t._token << "|";
    return outs;
}
