#include "FTokenizer.h"

FTokenizer::FTokenizer(char* fname) {
    fin.open(fname);
    _more = true;


    if(!get_new_block())
        _more = false;
}

Token FTokenizer::next_token() {
    Token t = Token();

    if(_stk.done()) {
        if(!get_new_block())
            _more = false;
    }
    else
        _stk >> t;

    if(_stk.done())
        if(!get_new_block())
            _more = false;

    return t;
}

bool FTokenizer::more() {
    return !done();
}

bool FTokenizer::done() {
    return _stk.done() && fin.eof();
}


FTokenizer& operator>>(FTokenizer& s, Token& t) {
    if(s._more)
        t = s.next_token();
    return s;
}

bool FTokenizer::get_new_block() {
    char block[MAX_BLOCK];

    if(!fin.eof()) {
        fin.read(block, MAX_BLOCK);
        int bytes_read = fin.gcount();
        block[bytes_read] = '\0';
        _stk.set_string(block);
        return true;
    }
    else {
        fin.close();
        return false;
    }
}
