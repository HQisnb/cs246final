#include <vector>
#include "cell.cc"
#include <iostream>
#include "board.cc"

class TextDisplay: public Observer, public Board {
    std::vector<std::vector<char>> board1;
    std::vector<std::vector<char>> board2;
    bool isBlind1 = false;
    bool isBlind2 = false;

    void notify(Cell& fromWhom) {

    }
    void print() {
        std::cout << "level:    " << level1 << "       ";
        std::cout << "level:    " << level2 << std::endl;

        std::cout << "score:    " << score1 << "       ";
        std::cout << "score:    " << score2 << std::endl;

        std::cout << "-----------       -----------" << std::endl;

        for (int i = 0; i < 18; i++) {
            for (int j = 0; j < 11; j++) {
                if (isBlind1 == true && j > 2 && j < 9 && i > 2 && i < 12) {
                    std::cout << "?";
                } else {
                    std::cout << board1[i][j];
                }
            }
            std::cout << "       ";
            for (int j = 0; j < 11; j++) {
                if (isBlind2 == true && j > 2 && j < 9 && i > 2 && i < 12) {
                    std::cout << "?";
                } else {
                    std::cout << board2[i][j];
                }
            }
            std::cout << std::endl;
        }
        std::cout << "-----------       -----------" << std::endl;
        
        std::cout << "Next:             Next:      " << std::endl;
        // here we should add next block print after done level
    }
};
