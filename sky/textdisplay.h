#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <vector>
#include <iostream>
#include "posn.h"
#include "block.h"
#include "board.h"
#include "game.h"

class TextDisplay: public Observer {
    public:
    Game * game;
    std::vector<std::vector<char>> board1;
    std::vector<std::vector<char>> board2;
    bool isBlind1 = false;
    bool isBlind2 = false;

    TextDisplay(Game *g);
    void notify(Cell &fromWhom) override;
    void print();

};

#endif
