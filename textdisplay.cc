#include <vector>
#include <iostream>
#include "board.cc"
#include "posn.h"
#include "block.h"

bool belongTo(int x, int y, std::vector<Posn> lst) {
    for (int i = 0; i < 4; i++) {
        if (x == lst[i].x && y == lst[i].y) {
            return true;
        }
    }
    return false;
}

class TextDisplay: public Observer, public Game {
    std::vector<std::vector<char>> board1;
    std::vector<std::vector<char>> board2;
    bool isBlind1 = false;
    bool isBlind2 = false;

    TextDisplay() {
        for (int i = 0; i < 18; i++) {
            std::vector<char> row;
            for (int j = 0; j < 11; j++) {
                row.emplace_back(' ');
            }
            board1.emplace_back(' ');
        }
        for (int i = 0; i < 18; i++) {
            std::vector<char> row;
            for (int j = 0; j < 11; j++) {
                row.emplace_back(' ');
            }
            board2.emplace_back(' ');
        }
    }

    void notify(Cell& fromWhom) {
        if (fromWhom.boardNo == 1) {
            board1[fromWhom.column][fromWhom.row] = fromWhom.type;
        } else {
            board2[fromWhom.column][fromWhom.row] = fromWhom.type;
        }
    }

    void print() {
        std::cout << "level:    " << players[0].level << "       ";
        std::cout << "level:    " << players[1].level << std::endl;

        std::cout << "score:    " << players[0].score << "       ";
        std::cout << "score:    " << players[1].score << std::endl;

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
        // here we print next block
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 11; j++) {
                if (belongTo(i, j, players[0].nextBlock->points)) {
                    std::cout << players[0].nextBlock->type;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << "       ";
            for (int j = 0; j < 11; j++) {
                if (belongTo(i, j, players[1].nextBlock->points)) {
                    std::cout << players[1].nextBlock->type;
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
};

    
