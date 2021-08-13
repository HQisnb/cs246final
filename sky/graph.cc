#include "graph.h"
#include <iostream>
#include <memory>
using namespace std;


// here we assume graph can access board and cell's field


Graph::Graph(Board *b1, Board *b2, TextDisplay *td) : b1{b1}, b2{b2}, td{td} {
    if ((b1 != nullptr) && (b2 != nullptr) && (td != nullptr)) {
        xw = new Xwindow{};
    }
}

void Graph::printGraph() {
    // left side print for player1 at board1
    // convert ints to string
    xw->fillRectangle(0, 0, 500, 500, Xwindow::White);
    stringstream ss1;
    stringstream ss2;
    stringstream ss3;
    string lv;
    string sc;
    string hs;
    ss1 << b1->levelNo;
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

    xw->drawString(firstPosn, 10, msg1);
    xw->drawString(firstPosn, 25, msg2);
    xw->drawString(firstPosn, 40, msg3);
    xw->drawString(firstPosn, 420, msg4);

    // draw game background for player1
    xw->fillRectangle(firstPosn, 50, 220, 360, Xwindow::Black);

    // start drawing the board with cell
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (td->isBlind1 == true && j > 1 && j < 9 && i > 1 && i < 12) {
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, 20, 20, Xwindow::Cyan);
                continue;
            }
            if (b1->theBoard[i][j].type == 'I')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b1->theBoard[i][j].type == 'J')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b1->theBoard[i][j].type == 'L')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b1->theBoard[i][j].type == 'S')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b1->theBoard[i][j].type == 'Z')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB,sizeB, Xwindow::Linen);
            if (b1->theBoard[i][j].type == 'O') 
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b1->theBoard[i][j].type == 'T')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b1->theBoard[i][j].type == '*')
                xw->fillRectangle(firstPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Brown);
        }
    }
    // start drawing the currblock
        for (int i = 0; i < 4; i++) {
            if (b1->currBlock == nullptr) break;
            if (b1->currBlock->getType() == 'I')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b1->currBlock->getType() == 'J')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b1->currBlock->getType() == 'L')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b1->currBlock->getType() == 'S')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b1->currBlock->getType() == 'Z')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Linen);
            if (b1->currBlock->getType() == 'O')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b1->currBlock->getType() == 'T')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b1->currBlock->getType() == '*')
                xw->fillRectangle(b1->currBlock->points[i].x * sizeB, firstH + b1->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Brown);
        }
    // start drawing the nextblock;
    for (int i = 0; i < 4; i++) {
        if (b1->nextBlock == nullptr) break;
            if (b1->nextBlock->getType() == 'I')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b1->nextBlock->getType() == 'J')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b1->nextBlock->getType() == 'L')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b1->nextBlock->getType() == 'S')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b1->nextBlock->getType() == 'Z')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Linen);
            if (b1->nextBlock->getType() == 'O')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b1->nextBlock->getType() == 'T')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b1->nextBlock->getType() == '*')
                xw->fillRectangle(b1->nextBlock->points[i].x * sizeB, nextB + b1->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Brown);
        }

    // right side print for player2 at board2

    // convert ints to string
    stringstream ss4;
    stringstream ss5;
    stringstream ss6;
    string lv1;
    string sc1;
    string hs1;
    ss4 << b2->levelNo;
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
    xw->drawString(secondPosn, 10, msg5);
    xw->drawString(secondPosn, 25, msg6);
    xw->drawString(secondPosn, 40, msg7);
    xw->drawString(secondPosn, 420, msg8);

    // draw game background for player2
    xw->fillRectangle(secondPosn, 50, 220, 360, Xwindow::Black);

    // start drawing the board with cell
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            if (td->isBlind2 == true && j > 1 && j < 9 && i > 1 && i < 12) {
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Cyan);
                continue;
            }
            if (b2->theBoard[i][j].getType() == 'I')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b2->theBoard[i][j].getType() == 'J')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b2->theBoard[i][j].getType() == 'L')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b2->theBoard[i][j].getType() == 'S')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b2->theBoard[i][j].getType() == 'Z')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Linen);
            if (b2->theBoard[i][j].getType() == 'O') 
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b2->theBoard[i][j].getType() == 'T')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b2->theBoard[i][j].getType() == '*')
                xw->fillRectangle(secondPosn + j * sizeB, firstH + i * sizeB, sizeB, sizeB, Xwindow::Brown);
        }
    }
    // start drawing the currblock
        for (int i = 0; i < 4; i++) {
            if (b2->currBlock == nullptr) break;
            if (b2->currBlock->getType() == 'I')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b2->currBlock->getType() == 'J')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b2->currBlock->getType() == 'L')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b2->currBlock->getType() == 'S')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b2->currBlock->getType() == 'Z')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Linen);
            if (b2->currBlock->getType() == 'O')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b2->currBlock->getType() == 'T')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b2->currBlock->getType() == '*')
                xw->fillRectangle(secondPosn + b2->currBlock->points[i].x * sizeB - 20, firstH + b2->currBlock->points[i].y * sizeB, sizeB, sizeB, Xwindow::Brown);   
        }
    // start drawing the nextblock;
    for (int i = 0; i < 4; i++) {
        if (b2->nextBlock == nullptr) break;
            if (b2->nextBlock->getType() == 'I')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Yellow);
            if (b2->nextBlock->getType() == 'J')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Blue);
            if (b2->nextBlock->getType() == 'L')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Green);
            if (b2->nextBlock->getType() == 'S')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Red);
            if (b2->nextBlock->getType() == 'Z')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Linen);
            if (b2->nextBlock->getType() == 'O')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Orange);
            if (b2->nextBlock->getType() == 'T')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Purple);
            if (b2->nextBlock->getType() == '*')
                xw->fillRectangle(secondPosn + b2->nextBlock->points[i].x * sizeB - 20, nextB + b2->nextBlock->points[i].y * sizeB - 2 * sizeB, sizeB, sizeB, Xwindow::Brown);
        }

}

