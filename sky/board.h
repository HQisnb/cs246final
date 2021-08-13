#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "block.h"
#include "cell.h"
#include "level.h"

class Board {
    public:
    int boardNo;
    int idx = 0;
    int score = 0;
    int topScore = 0;
    int levelNo = 0; //TODO: is the default level set to 0?
    std::string file;
    bool is_playing ;//true means this player is playing. false means the other player is playing
    const int rows = 15 + 3;
    const int cols = 11;
    bool random = false; // random is the random switch, default to false which is off.
    char specialAction = 'N'; // default N means None, can be replaced with B/H/F
    bool gameOver = false; // game is still going, neither won nor over.
    std::unique_ptr<Block> currBlock;
    std::unique_ptr<Block> nextBlock;
    std::vector<std::vector<Cell>> theBoard;
    Level0 level0;// to be modified to BaseLevel *
    std::vector<std::unique_ptr<Block>> theBlock;
    
    // std::vector<BaseLevel *> level;

    Board(int n, std::string file);
    void levelUp();
    void levelDown();
    void left();
    void right();
    void down();
    void drop();
    void rot_cw();// newly added
    void rot_ccw(); // newly added
    bool isMoveValid(char c);
    bool checkTemp(std::vector<Posn> temp);// checking if rotation is valid
    // void randomSwitch();
    void rowDelete();
    void mutateBlock();
    void init(); // initialize currBlock and nextBlock
    // void blind();
    // void heavy();
    // void force();
    // void restart();
    // void isGameOver(); 

    bool inVec(std::vector<int> vct, int a);
    int NumType();
    void rowInit(int row);
    void copyRowAndChange(int row1);
    void upperCellDown(int row);
    void scoreAndChange(int originLevel);

};

#endif
