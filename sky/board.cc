#include "board.h"
#include <iostream>


Board::Board(int n) {
    boardNo = n;
    theBoard.clear();

    for (int y = 1; y <= rows; y++) {//x goes from left to right, y goes from up to down
    std::vector<Cell> rowVector;
        for (int x = 1; x <= cols; x++) {
            rowVector.emplace_back(y, x, boardNo);
        }
    theBoard.push_back(rowVector);
    }
    
    level0 = Level0 {};
    // level.push_back(level0);
}

void Board::levelUp() {
    if (levelNo == 4) { return; }
    levelNo += 1; 
}

void Board::levelDown() {
    if (levelNo == 0) { return; }
    levelNo -= 1;
}

bool Board::isMoveValid(char c) {//TODO: NEED FURTHER CODE // create a temp block to realize strong guarantee
    if (c == 'l') {
        if (currBlock->minX() == 1) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x - 1;
            int temp_y = currBlock->points[i].y;// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'r') {
        if (currBlock->maxX() == 11) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x + 1;
            int temp_y = currBlock->points[i].y;// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'd') {
        if (currBlock->maxY() == 18) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x;
            int temp_y = currBlock->points[i].y + 1;// TODO: 18 + 1 - y
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    return true;//TODO: NEED FURTHER CODE
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
    currBlock->moveDown();
}

void Board::drop() {
    while (isMoveValid('d')) {
        currBlock->moveDown();
    }
    for (auto i : currBlock->points) {
        (theBoard[i.x][i.y]).type = currBlock->getType();
        // (theBoard[i.x][i.y]).notifyObserver();
        (theBoard[i.x][i.y]).filled = true;
        std::cout << "x is " << i.x << " and y is " << i.y << std::endl;
    }
    is_playing = false;
    currBlock = std::move(nextBlock);
    nextBlock = level0.createBlock();
}

void Board::rot_cw() {
    std::vector<Posn> temp = currBlock->rot_cw();
    if (this->checkTemp(temp)) {// keep this or not?
        currBlock->points = temp;
        currBlock->blockPointsSort();
        currBlock->curStatus = (currBlock->curStatus + 1) % 4;
    }
}

void Board::rot_ccw() {
    std::vector<Posn> temp = currBlock->rot_ccw();
    if (this->checkTemp(temp)) {// keep this or not?
        currBlock->points = temp;
        currBlock->blockPointsSort();
        currBlock->curStatus = (currBlock->curStatus + 3) % 4;
    }
}


// 1. check 是否出界！
// 2. check 转完会不会重叠 
bool Board::checkTemp(std::vector<Posn> temp) {
    for (int a = 0; a < 4; a++) {
        // want to add conditions: temp[a].x >= 1 && temp[a].x <= 11 temp[a].y <= 18;
        // if we need -1 below?
        if (theBoard[temp[a].x][temp[a].y].type != 'E') {
            return false;
        } 
    }
    return true;
}

void Board::atTurn() {
    
}