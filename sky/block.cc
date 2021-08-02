#include "block.h"
#include <memory>

Block::Block(Posn llc, int rot) : llc {llc}, rot { rot } {};


void Iblock::rot_cw() {
    std::cout << "IBlock rot_cw() does nothing" << std::endl;
}
void Iblock::rot_ccw() {
    std::cout << "IBlock rot_ccw() does nothing" << std::endl;
}

int main() {
    // Block b1 { Posn{3, 2}, 1 };
    // b1.llc.print();
    // std::cout << b1.rot << " is rot" << std::endl;
    // b1.rot_cw();
    // b1.rot_ccw();

    Iblock i1 { Posn {4, 3}, 2 };
    i1.print();
    i1.rot_cw();
    i1.rot_ccw();

    std::unique_ptr<Iblock> uni_i1 = std::unique_ptr<Iblock>(new Iblock{Posn{5, 7}, 4});
    uni_i1->print();
    uni_i1->rot_cw();
    uni_i1->rot_ccw();

}