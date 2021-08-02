#include "block.h"
#include <memory>

Block::Block(int rot) : rot { rot } {};

void Block::moveLeft() { 
    llc.left();
    // for (int i = 0; i < points.size(); i++) {
    //TODO: move all four points here
    // }
}

void Block::moveRight() { llc.right(); }

void Block::moveDown() { llc.down(); }


void Iblock::rot_cw() {
    std::cout << "IBlock rot_cw() does nothing" << std::endl;
}
void Iblock::rot_ccw() {
    std::cout << "IBlock rot_ccw() does nothing" << std::endl;
}

int main() {
    Iblock i1 { 2 };
    i1.print();
    i1.rot_cw();
    i1.rot_ccw();

    i1.moveLeft();
    i1.print();

    i1.moveRight();
    i1.print();

    i1.moveDown();
    i1.print();

    // std::unique_ptr<Iblock> uni_i1 = std::unique_ptr<Iblock>(new Iblock{Posn{5, 7}, 4});
    // uni_i1->print();
    // uni_i1->rot_cw();
    // uni_i1->rot_ccw();

}