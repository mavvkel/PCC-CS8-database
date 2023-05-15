#ifndef MAKE_TABLE_FUNCTIONS_H
#define MAKE_TABLE_FUNCTIONS_H
#include "Constants.h"

void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to,
                int state) {
    for(int i = from; i <= to; i++)
        _table[row][i] = state;
}

#endif // MAKE_TABLE_FUNCTIONS_H
