#include "board.h"
/*
void Board::removeCell(int x, int y) {
    int allBlock = theBlock.size();
    for (int i = 0; i < allBlock; i++) {
        int ptlen = theBlock[i]->points.size();
        for (int j = 0; j < ptlen;) {
            if (theBlock[i]->points[j].x == x && theBlock[i]->points[j].y == y) {
                theBlock[i]->points.erase(theBlock[i]->points.begin() + j);
            } else {
                j++;
            }
        }
    }
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

void Board::scoreAndChange(int originLevel) {
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
    if (curAdd == 0) return;
    curAdd = (curAdd + levelNo) * (curAdd + levelNo);
    // here we start to change the board
    // princeple: clear bottom to up, clear, down all upper......
    // remove points from the block vector
    int originLen = theBlock.size();
    for (int i = 0; i < filledNum; i++) {
        for (int j = 1; j <= 11; j++) {
            removeCell(j, whichRow[i]);
        }
    }
    // here we remove all blocks with empty points vector
    int length1 = originLen;
    for (int i = 0; i < originLen;) {
        if (theBlock[i]->points.size() == 0) {
            theBlock.erase(theBlock.begin() + i);
            originLen -= 1;
        } else {
            i++;
        }
    }
    // here we calculate the total score added;
    int afterLen = theBlock.size();
    std::cout << length1 << " is length1" << std::endl;
    std::cout << afterLen << " is afterLen" << std::endl;
    
    if (length1 - afterLen != 0) {
        curAdd = curAdd + (originLevel + length1 - afterLen) * (originLevel + length1 - afterLen);
    }
    score += curAdd;

    // here we start to change the theBoard!!!
    for (int i = 0; i < filledNum; i++) {
        // rowInit(whichRow[i]);//
        upperCellDown(whichRow[i]);
    }
    if (score > topScore) {
        topScore = score;
    }
}*/
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
// here is what I changed

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

void Board::scoreAndChange(int originLevel) {
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
    if (curAdd == 0) return;
    curAdd = (curAdd + levelNo) * (curAdd + levelNo);
    // here we start to change the board
    /*
    // princeple: clear bottom to up, clear, down all upper......
    // remove points from the block vector
    int originLen = theBlock.size();
    for (int i = 0; i < filledNum; i++) {
        for (int j = 1; j <= 11; j++) {
            removeCell(j, whichRow[i]);
        }
    }
    // here we remove all blocks with empty points vector
    int length1 = originLen;
    for (int i = 0; i < originLen;) {
        if (theBlock[i]->points.size() == 0) {
            theBlock.erase(theBlock.begin() + i);
            originLen -= 1;
        } else {
            i++;
        }
    }  */
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
    std::cout << length1 << " is length1" << std::endl;
    std::cout << afterLen << " is afterLen" << std::endl;
    
    if (score > topScore) {
        topScore = score;
    }
}

