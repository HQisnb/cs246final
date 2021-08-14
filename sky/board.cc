#include "board.h"
#include <iostream>

//// here is what should be added
// after each end of the turn, idx += 1 for idx in board;
// change the cell at the posn of block at the board with idx euqal to the current idx in board

Board::Board(int n, std::string fileName) : level0{Level0{n}}, level1{Level1{n}}, level2{Level2{n}}, level3{Level3{n}} {
    boardNo = n;
    file = fileName;
    theBoard.clear();
    theBlock.clear();

    for (int y = 1; y <= rows; y++) {//x goes from left to right, y goes from up to down
    std::vector<Cell> rowVector;
        for (int x = 1; x <= cols; x++) {
            rowVector.emplace_back(y, x, boardNo);
        }
    theBoard.emplace_back(rowVector);
    }
    
    level0.file = file;
}

void Board::levelUp() {
    if (levelNo == 4) { return; }
    levelNo += 1; 
}

void Board::levelDown() {
    if (levelNo == 0) { return; }
    levelNo -= 1;
}

bool Board::isMoveValid(char c) {
    if (c == 'l') {
        if (currBlock->minX() == 1) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x - 1;
            int temp_y = currBlock->points[i].y;
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'r') {
        if (currBlock->maxX() == 11) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x + 1;
            int temp_y = currBlock->points[i].y;
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    if (c == 'd') {
        if (currBlock->maxY() == 18) { return false; }
        for (size_t i = 0; i < currBlock->points.size(); i++) {
            int temp_x = currBlock->points[i].x;
            int temp_y = currBlock->points[i].y + 1;
            if (theBoard[temp_y - 1][temp_x - 1].isFilled()) { return false; }
        }
        return true;
    }
    return true;
}

void Board::left() {
    if (!isMoveValid('l')) { return; } // unable to move, cmd is invalid
    if (levelNo == 3) {
        currBlock->moveLeft();
        currBlock->moveDown();
    }
    currBlock->moveLeft();
}

void Board::right() {
    if (!isMoveValid('r')) { return; } // unable to move, cmd is invalid
    if (levelNo == 3) {
        currBlock->moveRight();
        currBlock->moveDown();
    }
    currBlock->moveRight();
}

void Board::down() {
    if (!isMoveValid('d')) { return; } // unable to move, cmd is invalid
    if (levelNo == 3) {
        currBlock->moveDown();
        currBlock->moveDown();
    }
    currBlock->moveDown();
}

void Board::drop(int *rowsRemoved) {
    while (isMoveValid('d')) {
        down();
    }

    for (auto i : currBlock->points) {
        (theBoard[i.y - 1][i.x - 1]).type = currBlock->getType();
        (theBoard[i.y - 1][i.x - 1]).filled = true;
    }
    is_playing = false;

    idx += 1;
    for (int i = 0; i < 4; i++) {
        theBoard[currBlock->points[i].y - 1 ][currBlock->points[i].x - 1].idx = idx;
    }

    // theBlock.push_back(std::move(currBlock));
    
    currBlock = std::move(nextBlock);
    if (levelNo == 0) {
        nextBlock = level0.createBlock();
    } else if (levelNo == 1) {
        nextBlock = level1.createBlock();
    } else if (levelNo == 2) {
        nextBlock = level2.createBlock();
    } else {
        // do nothing
    }


    //check if the game has ended
    for (int i = 0; i < 4; i++) {
        if (theBoard[currBlock->points[i].y - 1][currBlock->points[i].x - 1].isFilled()) {
            gameOver = true;
        }
    }

    //check if any row can be removed
    if (rowsRemoved == nullptr) {
        scoreAndChange(levelNo);
    } else {
        *rowsRemoved = scoreAndChange(levelNo);
    }
}

void Board::rot_cw() {
    std::vector<Posn> temp = currBlock->rot_cw();
    if (this->checkTemp(temp)) {// keep this or not?
        currBlock->points = temp;
        currBlock->blockPointsSort();
        currBlock->curStatus = (currBlock->curStatus + 1) % 4;
        if (levelNo == 3) {
        currBlock->moveDown();
        }
    }
}

void Board::rot_ccw() {
    std::vector<Posn> temp = currBlock->rot_ccw();
    if (this->checkTemp(temp)) {// keep this or not?
        currBlock->points = temp;
        currBlock->blockPointsSort();
        currBlock->curStatus = (currBlock->curStatus + 3) % 4;
        if (levelNo == 3) {
        currBlock->moveDown();
        }
    }
}


// 1. check if it is out of boundary
// 2. check if it overlays after rotation
bool Board::checkTemp(std::vector<Posn> temp) {
    for (int a = 0; a < 4; a++) {
        // want to add conditions: temp[a].x >= 1 && temp[a].x <= 11 temp[a].y <= 18;
        // if we need -1 below?
        if (theBoard[temp[a].y - 1][temp[a].x - 1].type != ' ') {
            return false;
        }
        if ((temp[a].x > 11) || (temp[a].x < 1) || (temp[a].y > 18) || (temp[a].y < 1)) {
            return false;
        }
    }
    return true;
}

void Board::init() {
    if (levelNo == 0) {
        currBlock = level0.createBlock();
        nextBlock = level0.createBlock();
    } else if (levelNo == 1) {
        currBlock = level1.createBlock();
        nextBlock = level1.createBlock();
    } else if (levelNo == 2) {
        currBlock = level2.createBlock();
        nextBlock = level2.createBlock();
    } else if (levelNo == 3) {
        currBlock = level3.createBlock();
        nextBlock = level3.createBlock();
    } else {
        std::cout << "No such level" << std::endl;
    }
}

bool Board::inVec(std::vector<int> vct, int a) {
    int len = vct.size();
    for (int i = 0; i < len; i++) {
        if (vct[i] == a) {
            return true;
        }
    }
    return false;
}

int Board::NumType() {
    std::vector<int> checked;
    checked.clear();
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (theBoard[i][j].filled != false && !inVec(checked, theBoard[i][j].idx)) {
                checked.emplace_back(theBoard[i][j].idx);
            }
        }
    }
    int len = checked.size();
    return len;
}

void Board::rowInit(int row) {
    for (int i = 0; i < 11; i++) {
        theBoard[row][i].type = ' ';
        theBoard[row][i].filled = false;
    }
}

void Board::copyRowAndChange(int row1) {
    std::vector<Cell> rowUpper;
    rowUpper.clear();
    for (int i = 0; i < 11; i++) {
        rowUpper.emplace_back(theBoard[row1-1][i]);
        rowUpper[i].row += 1;
    }
    theBoard[row1] = rowUpper;
}

void Board::upperCellDown(int row) {
    for (int i = row; i > 0; i--) {
        rowInit(i);
        copyRowAndChange(i);
    }
}

int Board::scoreAndChange(int originLevel) {
    // here is a vector that record filled row
    std::vector<int> whichRow;
    whichRow.clear();
    // here we start counting the row and fill the vector
    for (int i = 3; i < 18; i++) {
        int filled = 0;
        for (int j = 0; j < 11; j++) {
            if (theBoard[i][j].type != ' ') {
                filled += 1;
            }
        }
        if (filled == 11) {
            whichRow.emplace_back(i);
        }
    }
    // here (int idx) to show diff; also in board

    // here we can get how many and which rows are filled
    int filledNum = whichRow.size();
    int curAdd = filledNum;
    // for (int i = 0; i < filledNum; i++) {
    //     std::cout << whichRow[i] << std::endl;
    // }
    if (curAdd == 0) return 0;
    curAdd = (curAdd + levelNo) * (curAdd + levelNo);
    
    int length1 = NumType();
    // here we start to change the theBoard!!!
    for (int i = 0; i < filledNum; i++) {
        // rowInit(whichRow[i]);//
        upperCellDown(whichRow[i]);
    }
    // here we calculate the total score added;
    int afterLen = NumType();
    if (length1 - afterLen != 0) {
        curAdd = curAdd + (originLevel + length1 - afterLen) * (originLevel + length1 - afterLen);
    }
    score += curAdd;
    
    if (score > topScore) {
        topScore = score;
    }
    return filledNum;
}



