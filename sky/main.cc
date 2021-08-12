#include <iostream>
#include "level.h"
#include "game.h"
#include "textdisplay.h"
#include <vector>
#include <memory>
/*
int main() {
    Game g1{};
    TextDisplay td{&g1};
    g1.newGame();

    Level0 level0 {};
    g1.players[0]->currBlock = level0.createBlock();
    
}

*/
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

    while (true) {
        
    }
    
    g1.players[0]->atTurn();

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