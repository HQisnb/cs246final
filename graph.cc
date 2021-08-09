#include "graphidisplay.h"
#include <iostream>

// here we assume graph can access board and cell's field

void Graph::printGraph() {
    // left side print for player1 at board1

    // convert ints to string
    stringstream ss1;
    stringstream ss2;
    stringstream ss3;
    string lv;
    string sc;
    string hs;
    ss1 << b1->level;
    ss2 << b1->score;
    ss3 << b1->topScore;
    ss1 >> lv;
    ss2 >> sc;
    ss3 >> hs;
    // start print texts for player1
    string msg1 = "Level:    " + lv;
    string msg2 = "Score:    " + sc;
    string msg3 = "Highest:  " + hs;
    string msg4 = "Next:     ";
    drawString(firstPosn, 0, msg1);
    drawString(firstPosn, 15, msg2);
    drawString(firstPosn, 30, msg3);
    drawString(firstPosn, 420, msg4);

    // draw game background for player1
    fillRectangle(firstPosn, 50, 220, 360, Xwindow::Black);

    // start drawing the board with cell
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (b1->theBoard[i][j].type == 'I')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Yellow);
            if (b1->theBoard[i][j].type == 'J')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Blue);
            if (b1->theBoard[i][j].type == 'L')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Green);
            if (b1->theBoard[i][j].type == 'S')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Red);
            if (b1->theBoard[i][j].type == 'Z')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Brown);
            if (b1->theBoard[i][j].type == 'O') 
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Orange);
            if (b1->theBoard[i][j].type == 'T')
                fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Purple);
        }
    }
    // start drawing the currblock
        for (int i = 0; i < 4; i++) {
            if (b1->currBlock == nullptr) break;
            if (b1->currBlock->type == 'I')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Yellow);
            if (b1->currBlock->type == 'J')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Blue);
            if (b1->currBlock->type == 'L')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Green);
            if (b1->currBlock->type == 'S')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Red);
            if (b1->currBlock->type == 'Z')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Brown);
            if (b1->currBlock->type == 'O')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Orange);
            if (b1->currBlock->type == 'T')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Purple);
        }
    // start drawing the nextblock;
    for (int i = 0; i < 4; i++) {
        if (b1->nextBlock == nullptr) break;
            if (b1->nextBlock->type == 'I')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Yellow);
            if (b1->nextBlock->type == 'J'
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Blue);
            if (b1->nextBlock->type == 'L')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Green);
            if (b1->nextBlock->type == 'S')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Red);
            if (b1->nextBlock->type == 'Z')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Brown);
            if (b1->nextBlock->type == 'O')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Orange);
            if (b1->nextBlock->type == 'T')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Purple);
        }

    // right side print for player2 at board2

    // convert ints to string
    stringstream ss4;
    stringstream ss5;
    stringstream ss6;
    string lv1;
    string sc1;
    string hs1;
    ss4 << b2->level;
    ss5 << b2->score;
    ss6 << b2->topScore;
    ss4 >> lv1;
    ss5 >> sc1;
    ss6 >> hs1;
    // start print texts for player2
    string msg5 = "Level:    " + lv1;
    string msg6 = "Score:    " + sc1;
    string msg7 = "Highest:  " + hs1;
    string msg8 = "Next:     ";
    drawString(secondPosn, 0, msg5);
    drawString(secondPosn, 15, msg6);
    drawString(secondPosn, 30, msg7);
    drawString(secondPosn, 420, msg8;

    // draw game background for player2
    fillRectangle(secondPosn, 50, 220, 360, Xwindow::Black);

    // start drawing the board with cell
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (b2->theBoard[i][j].type == 'I')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Yellow);
            if (b2->theBoard[i][j].type == 'J')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Blue);
            if (b2->theBoard[i][j].type == 'L')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Green);
            if (b2->theBoard[i][j].type == 'S')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Red);
            if (b2->theBoard[i][j].type == 'Z')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Brown);
            if (b2->theBoard[i][j].type == 'O') 
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Orange);
            if (b2->theBoard[i][j].type == 'T')
                fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Purple);
        }
    }
    // start drawing the currblock
        for (int i = 0; i < 4; i++) {
            if (b2->currBlock == nullptr) break;
            if (b2->currBlock->type == 'I')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Yellow);
            if (b2->currBlock->type == 'J')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Blue);
            if (b2->currBlock->type == 'L')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Green);
            if (b2->currBlock->type == 'S')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Red);
            if (b2->currBlock->type == 'Z')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Brown);
            if (b2->currBlock->type == 'O')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Orange);
            if (b2->currBlock->type == 'T')
                fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b2->currBlock->points[i].y * sizeB, 20, 20, Xwindow::Purple);
        }
    // start drawing the nextblock;
    for (int i = 0; i < 4; i++) {
        if (b2->nextBlock == nullptr) break;
            if (b1->nextBlock->type == 'I')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Yellow);
            if (b1->nextBlock->type == 'J'
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Blue);
            if (b1->nextBlock->type == 'L')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Green);
            if (b1->nextBlock->type == 'S')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Red);
            if (b1->nextBlock->type == 'Z')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Brown);
            if (b1->nextBlock->type == 'O')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Orange);
            if (b1->nextBlock->type == 'T')
                fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b2->nextBlock->points[i].y * sizeB, 20, 20, Xwindow::Purple);
        }

}


