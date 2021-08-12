#include "game.h"

void Game::newGame() {
    players.clear();
    std::unique_ptr<Board> b1 = std::unique_ptr<Board>(new Board{1});
    std::unique_ptr<Board> b2 = std::unique_ptr<Board>(new Board{2});
    players.push_back(std::move(b1));
    players.push_back(std::move(b2));
    players[0]->is_playing = true;
    players[1]->is_playing = false;
}

void Game::updateTopScore() {
    int temp = 0;
    if (players[0]->topScore > players[1]->topScore) {
        temp = players[0]->topScore;
    } else {
        temp = players[1]->topScore;
    }
    if (temp > topScore) { topScore = temp; }
}


