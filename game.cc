#include <vector>
class Board;

class Game {
    std::vector<Board> players;
    int topScore = 0;

    void newGame() {}
    int hiScore() { return topScore;}
    friend class TextDisplay;
};
