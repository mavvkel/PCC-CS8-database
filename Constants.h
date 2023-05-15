#ifndef CONSTANTS_H
#define CONSTANTS_H

// === TOKENIZER =============================================================
enum TOKEN_TYPES {ALPHA, NUM, PUNCT, SPACE, UNKNWN, EMPTY};

enum STATES {fail, success};

const unsigned MAX_COLUMNS = 128;
const unsigned MAX_ROWS = 30;
const unsigned MAX_BUFFER = 200;
const unsigned MAX_BLOCK = MAX_BUFFER;


// === VectR class ===========================================================
const unsigned INIT_CAP = 8;


#endif // CONSTANTS_H
