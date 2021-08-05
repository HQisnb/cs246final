#include "game.h"
#include "textdisplay.h"



void Game::newGame() {
    players.clear();
    std::unique_ptr<Board> b1 = std::unique_ptr<Board>(new Board{1});
    std::unique_ptr<Board> b2 = std::unique_ptr<Board>(new Board{2});
    players.push_back(std::move(b1));
    players.push_back(std::move(b2));
}


int main() {
    Game g1{};
    TextDisplay td{&g1};
    g1.newGame();

    g1.players[0]->currBlock = new Iblock{1};
    g1.players[0]->nextBlock = new Iblock{2};
    g1.players[1]->currBlock = new Iblock{3};
    g1.players[1]->nextBlock = new Iblock{4};
    td.print();
}
