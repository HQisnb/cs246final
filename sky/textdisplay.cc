#include "textdisplay.h"


bool belongTo(int i, int j, std::vector<Posn> lst) {
    for (int a = 0; a < 4; a++) {
        // std::cout << "lst[a].x is " << lst[a].x << std::endl;
        // std::cout << "lst[a].y is " << lst[a].y << std::endl;
        // std::cout << "i is " << i << std::endl;
        // std::cout << "j is " << j << std::endl;
        if ((j == lst[a].x) && (i == lst[a].y)) {
            // std::cout << "It can be true" << std::endl;
            return true;
        }
    }
    return false;
}

TextDisplay::TextDisplay(Game *g) {
    game = g;
    for (int i = 0; i < 18; i++) {
        std::vector<char> row;
        for (int j = 0; j < 11; j++) {
            row.emplace_back(' ');
        }
        board1.push_back(row);
    }
    for (int i = 0; i < 18; i++) {
        std::vector<char> row;
        for (int j = 0; j < 11; j++) {
            row.emplace_back(' ');
        }
        board2.push_back(row);
    }
}

void TextDisplay::notify(Cell& fromWhom) {
    if (fromWhom.boardNo == 1) {
        board1[fromWhom.column][fromWhom.row] = fromWhom.type;
    } else {
        board2[fromWhom.column][fromWhom.row] = fromWhom.type;
    }
}

void TextDisplay::print() {
    std::cout << "level:    " << game->players[0]->level << "       ";
    std::cout << "level:    " << game->players[1]->level << std::endl;

    std::cout << "score:    " << game->players[0]->score << "       ";
    std::cout << "score:    " << game->players[1]->score << std::endl;

    std::cout << "-----------       -----------" << std::endl;

    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 11; j++) {
            if (isBlind1 == true && j >= 3 && j <= 9 && i >= 3 && i <= 12) {
                std::cout << "?";
            } else {
                /////////////////////
                if (belongTo(i, j, game->players[0]->currBlock->points)) {
                    std::cout << game->players[0]->currBlock->getType();
                    continue;
                }
                /////////////////////
                std::cout << board1[i-1][j-1];
            }
        }
        std::cout << "       ";
        for (int j = 1; j <= 11; j++) {
            if (isBlind2 == true && j >= 3 && j <= 9 && i >= 3 && i <= 12) {
                std::cout << "?";
            } else {
                /////////////////////
                if (belongTo(i, j, game->players[1]->currBlock->points)) {
                    std::cout << game->players[1]->currBlock->getType();
                    continue;
                }
                /////////////////////
                std::cout << board2[i-1][j-1];
            }
        }
        std::cout << std::endl;
    }
    std::cout << "-----------       -----------" << std::endl;
    
    std::cout << "Next:             Next:      " << std::endl;

    // here we print next block
    for (int i = 3; i <= 4; i++) {//TODO: add some documentation to illustrate
        for (int j = 1; j <= 11; j++) {
            if (belongTo(i, j, game->players[0]->nextBlock->points)) {
                std::cout << game->players[0]->nextBlock->getType();
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "       ";
        for (int j = 1; j <= 11; j++) {
            if (belongTo(i, j, game->players[1]->nextBlock->points)) {
                std::cout << game->players[1]->nextBlock->getType();
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

