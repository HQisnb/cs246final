#include "textdisplay.h"


bool belongTo(int x, int y, std::vector<Posn> lst) {
    for (int i = 0; i < 4; i++) {
        if (x == lst[i].x && y == lst[i].y) {
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
            if (belongTo(i, j, game->players[0]->nextBlock->points)) {
                std::cout << "IT CAN BE TRUE" << std::endl;
                std::cout << game->players[0]->nextBlock->getType();
            } else {
                std::cout << "HERE IT IS!" << std::endl;
                std::cout << "I is " << i << " and j is " << j << std::endl;
                std::cout << game->players[0]->nextBlock->points[0].print
                std::cout << ' ';
            }
        }
        std::cout << "       ";
        for (int j = 0; j < 11; j++) {
            if (belongTo(i, j, game->players[1]->nextBlock->points)) {
                std::cout << game->players[1]->nextBlock->getType();
            } else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}



