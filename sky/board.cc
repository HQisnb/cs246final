#include "board.h"
#include <iostream>


void Board::init(int n) {
    boardNo = n;
    for (int y = 1; y <= rows; y++) {
        for (int x = 1; x <= cols; x++) {
            theBoard.emplace_back(y, x, boardNo);
        }
    }
}

void Board::levelUp() {
    if (level == 4) { return; }
    level += 1; 
}

void Board::levelDown() {
    if (level == 0) { return; }
    level -= 1;
}

bool isMoveValid(char c) { return true; }//TODO: NEED FURTHER CODE
// create a temp block to realize strong guarantee

void Board::left() {
    if (!isMoveValid('l')) { return; } // unable to move, cmd is invalid
    currBlock->moveLeft();
}

void Board::right() {
    if (!isMoveValid('r')) { return; } // unable to move, cmd is invalid
    currBlock->moveRight();
}

void Board::down() {
    if (!isMoveValid('d')) { return; } // unable to move, cmd is invalid
    currBlock->moveRight();
}

void Board::drop() {
    while (isMoveValid('d')) {
        currBlock->moveDown();
    }
    at_turn = false;
}

