#include "board.h"
#include "cell.h"
#include <iostream>


void Board::init(int n) {
    boardNo = n;
    for (int y = 1; y <= rows; y++) {//x goes from left to right, y goes from up to down
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

bool Board::isMoveValid(char c) {//TODO: NEED FURTHER CODE // create a temp block to realize strong guarantee
    if (c == 'l') {
        if (currBlock->minX() == 1) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x - 1;
            int temp_y = (rows + 1 - currBlock->points[i].y);// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'r') {
        if (currBlock->maxX() == 11) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x + 1;
            int temp_y = (rows + 1 - currBlock->points[i].y);// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'd') {
        if (currBlock->minY() == 1) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x;
            int temp_y = (rows + 1 - currBlock->points[i].y) + 1;// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
}

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
    is_playing = false;
}

