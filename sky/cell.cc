#include "cell.h"
#include <iostream>


Cell::Cell(int row, int column, int boardNo) : row{row}, column{column}, boardNo{boardNo} {}
// Cell::~Cell() {}
char Cell::getType() { return type; }
bool Cell::isFilled() { return filled; }
void Cell::notifyObserver() {
    std::cout << "subject Cell is notifying observers" << std::endl;
    observer->notify(*this);
}



// int main() {
//     Cell c1 {4, 5, 0};
//     std::cout << c1.getType() << std::endl;
//     std::cout << c1.isFilled() << std::endl;
//     std::cout << c1.boardNo << std::endl;
//     c1.notifyObserver();
// }