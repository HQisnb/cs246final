#include "board.h"
#include <iostream>


void Board::init(int n) {
    boardNo = n;
    for (int y = 1; y <= rows; y++) {
        for (int x = 1; x <= cols; x++) {
            theBoard.emplace_back(y, x, boardNo);
        }
    }
    //TODO:
}