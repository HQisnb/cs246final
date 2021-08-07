#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "block.h"
#include "cell.h"

class Board {
    public:
    int boardNo;
    int score;
    int level = 0; //TODO: is the default level set to 0?
    bool is_playing ;//true means this player is playing. false means the other player is playing
    const int rows = 15 + 3;
    const int cols = 11;
    bool random = false; // random is the random switch, default to false which is off.
    char specialAction = 'N'; // default N means None, can be replaced with B/H/F
    bool gameStatus = false; // game is still going, neither won nor over.
    Block * currBlock;
    Block * nextBlock;
    std::vector<std::vector<Cell>> theBoard;
    // std::vector<Block*> theBlock;

    Board(int n);
    void levelUp();
    void levelDown();
    void left();
    void right();
    void down();
    void drop();
    void rot_cw();// newly added
    // void rot_ccw(); // newly added
    bool isMoveValid(char c);
    bool checkTemp(std::vector<Posn> temp);// checking if rotation is valid
    // void randomSwitch();
    void rowDelete();
    void mutateBlock();
    // void blockPointsSort();
    // void blind();
    // void heavy();
    // void force();
    // void restart();
    // void isGameOver();

};

#endif
