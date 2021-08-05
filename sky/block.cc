#include "block.h"
#include <memory>
#include <algorithm>

Block::Block(int rot) : rot { rot } {};

void Block::moveLeft() { 
    llc.left();
    // for (int i = 0; i < points.size(); i++) {
    //TODO: move all four points here
    // }
    for (size_t i = 0; i < points.size(); i++) {
        points[i].left();
    }
}

void Block::moveRight() {
    llc.right();
    for (size_t i = 0; i < points.size(); i++) {
        points[i].right();
    }
}

void Block::moveDown() {
    llc.down();
    for (size_t i = 0; i < points.size(); i++) {
        points[i].down();
    }
}

void Iblock::rot_cw() {
    std::cout << "IBlock rot_cw() does nothing" << std::endl;
}
void Iblock::rot_ccw() {
    std::cout << "IBlock rot_ccw() does nothing" << std::endl;
}

void Block::blockPointsSort() {
    sort(points.begin(), points.end(), smallerThan);
}

int Block::minX() {
    int minX = points[0].x;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].x < minX) {
            minX = points[i].x
        }
    }
    return minX;
}

int Block::maxX() {
    int maxX = points[0].x;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].x > maxX) {
            maxX = points[i].x
        }
    }
    return maxX;
}

int Block::minY() {
    int minY = points[0].y;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].y < minY) {
            minY = points[i].y
        }
    }
    return minY;
}

int main() {
    Iblock i1 { 2 };
    i1.print();
    std::cout << "minX" << i1.minX();
    std::cout << "maxX" << i1.maxX();
    std::cout << "minY" << i1.minY();
    // for (auto i : i1.points) {
    //     i.print();
    // }
    // i1.points.clear();
    // for (auto i : i1.points) {
    //     i.print();
    // }
    // std::cout << __LINE__ << std::endl;
    // i1.points.emplace_back(Posn(2, 15));
    // i1.points.emplace_back(Posn(3, 14));
    // i1.points.emplace_back(Posn(1, 13));
    // i1.points.emplace_back(Posn(4, 15));
    // std::cout << __LINE__ << std::endl;

    // for (auto i : i1.points) {
    //     i.print();
    // }
    // std::cout << __LINE__ << std::endl;

    // i1.blockPointsSort();

    // for (auto i : i1.points) {
    //     i.print();
    // }
    

    // i1.moveLeft();
    // i1.print();
    // std::cout << __LINE__ << std::endl;
    // i1.moveRight();
    // i1.print();
    // std::cout << __LINE__ << std::endl;
    // i1.moveDown();
    // i1.print();

    // std::unique_ptr<Iblock> uni_i1 = std::unique_ptr<Iblock>(new Iblock{Posn{5, 7}, 4});
    // uni_i1->print();
    // uni_i1->rot_cw();
    // uni_i1->rot_ccw();

}