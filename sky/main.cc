#include "level.h"
#include "game.h"
#include "textDisplay.h"
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <string>


int main() {
    Game g1{};
    TextDisplay td{&g1};
    g1.newGame();

    int times = 0;
    std::string cmd;

    // std::cin >> times;

    // std::string str {};
    



    Level0 level0 {};
    g1.players[0]->currBlock = level0.createBlock();
    g1.players[0]->nextBlock = level0.createBlock();
    g1.players[1]->currBlock = level0.createBlock();
    g1.players[1]->nextBlock = level0.createBlock();

    td.print();

    int i = 0;
    while (i < 13) {
        while (g1.players[0]->is_playing) {
            // player 0 is playing
            // g1.players[0]->right();
            // g1.players[0]->rot_ccw();
            // g1.players[0]->down();
            // g1.players[0]->drop();
            std::cin >> cmd;
            if (cmd == "left") {
                g1.players[0]->left();
                } else if (cmd == "right") {
                    g1.players[0]->right();
                } else if (cmd == "down") {
                    g1.players[0]->down();
                } else if (cmd == "drop") {
                    g1.players[0]->drop();
                }
            td.print();
        }
        // td.print();
        g1.players[1]->is_playing = true;
        while (g1.players[1]->is_playing) {
            // player 1 is playing
            // g1.players[1]->right();
            // g1.players[1]->right();
            // g1.players[1]->right();
            // g1.players[1]->right();
            g1.players[1]->drop();
        }
        td.print();
        g1.players[0]->is_playing = true;
        i += 1;
       // if anyone won, the game loop breaks
    }
}
