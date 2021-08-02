#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Block;
class Cell;

class Board {
    public:
    const int rows = 15 + 3;
    const int cols = 11;
    int level = 0; //TODO: is the default level set to 0?
    bool random = false; // random is the random switch, default to false which is off.
    char specialAction = 'N'; // default N means None, can be replaced with B/H/F
    bool gameStatus = false; // game is still going, neither won nor over.
    Block * currBlock;
    Block * nextBlock;
    std::vector<Cell*> theBoard;
    std::vector<Block*> theBlock;

    void init();
    void levelUp();
    void levelDown();
    void left();
    void right();
    void down();
    void drop();
    bool isMoveValid();
    void randomSwitch();
    void rowDelete();
    void mutateBlock();
    // void blind();
    // void heavy();
    // void force();
    // void restart();
    // void isGameOver();

};