#ifndef GAME_H
#define GAME_H
#include "board.h"
#include <vector>
#include <memory>

class Game {
    public:
    std::vector<std::unique_ptr<Board>> players;// smart pointer used anywhere else?
    int topScore = 0;

    void newGame();
    int hiScore() { return topScore;}
    friend class TextDisplay;
};

#endif

