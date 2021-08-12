#include <iostream>
#include "level.h"
#include "game.h"
#include "textDisplay.h"
#include <vector>
#include <memory>

int main() {
    Game g1{};
    TextDisplay td{&g1};
    g1.newGame();


    Level0 level0 {};
    g1.players[0]->currBlock = level0.createBlock();
    g1.players[0]->nextBlock = level0.createBlock();
    g1.players[1]->currBlock = level0.createBlock();
    g1.players[1]->nextBlock = level0.createBlock();

    td.print();

    int i = 0;
    while (i < 3) {
        while (g1.players[0]->is_playing) {
            // player 0 is playing
            g1.players[0]->right();
            g1.players[0]->rot_ccw();
            g1.players[0]->down();
            td.print();
            g1.players[0]->drop();
        }
        // td.print();
        g1.players[1]->is_playing = true;
        while (g1.players[1]->is_playing) {
            // player 1 is playing
            g1.players[1]->right();
            g1.players[1]->right();
            g1.players[1]->right();
            g1.players[1]->right();
            td.print();
            g1.players[1]->drop();
        }
        // td.print();
        g1.players[0]->is_playing = true;
        i += 1;

        // if anyone won, the game loop breaks
    }
    
    

    td.print();


    // g1.players[0]->right();
    // g1.players[0]->down();
    // g1.players[0]->down();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // td.print();

    // g1.players[0]->rot_cw();
    // td.print();
    // g1.players[0]->rot_cw();
    // td.print();
    
    // g1.players[1]->rot_ccw();
    // td.print();
    // g1.players[1]->rot_ccw();
    // td.print();


    // g1.players[0]->currBlock = new Jblock{};// for testing purpose
    // g1.players[0]->nextBlock = new Lblock{};
    // g1.players[1]->currBlock = new Oblock{};
    // g1.players[1]->nextBlock = new Jblock{};
    // td.print();
}
/*
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[0]->right();
    // g1.players[0]->down();
    // g1.players[1]->down();
    // g1.players[1]->right();
    // g1.players[1]->right();
    // g1.players[1]->right();

    
    // td.print();
    g1.players[0]->rot_ccw();
    td.print();
    g1.players[0]->rot_ccw();
    td.print();
    g1.players[0]->rot_ccw();
    td.print();
    g1.players[0]->rot_ccw();
    td.print();

    // g1.players[0]->rot_cw();
    // td.print();

    // g1.players[0]->rot_cw();
    // td.print();



    g1.players[1]->rot_ccw();
    td.print();
    g1.players[1]->rot_ccw();
    td.print();
    g1.players[1]->rot_ccw();
    td.print();
    g1.players[1]->rot_ccw();
    td.print();
    // g1.players[1]->rot_cw();
    // td.print();
    // g1.players[1]->rot_cw();
    // td.print();
    g1.players[0]->drop();
    g1.players[1]->drop();
    td.print();
    delete g1.players[0]->currBlock; //to avoid memory leak
    delete g1.players[0]->nextBlock;
    delete g1.players[1]->currBlock;
    delete g1.players[1]->nextBlock;
}
*/