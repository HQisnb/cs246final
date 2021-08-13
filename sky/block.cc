#include "block.h"
#include <memory>
#include <algorithm>

Block::Block() {};
Block::~Block() {
    // std::cout << "Block destructor called" << std::endl;
}

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

void Block::blockPointsSort() {
    sort(points.begin(), points.end(), smallerThan);
}


int Block::minX() {
    int minX = points[0].x;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].x < minX) {
            minX = points[i].x;
        }
    }
    return minX;
}

int Block::maxX() {
    int maxX = points[0].x;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].x > maxX) {
            maxX = points[i].x;
        }
    }
    return maxX;
}

int Block::maxY() {
    int maxY = points[0].y;
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i].y > maxY) {
            maxY = points[i].y;
        }
    }
    return maxY;
}


// Iblock Implementation
Iblock::~Iblock() {
    // std::cout << "Iblock destructor called" << std::endl;
}

std::vector<Posn> Iblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[1].x -= 1;
        temp[2].x -= 2;
        temp[3].x -= 3;
        temp[1].y -= 1;
        temp[2].y -= 2;
        temp[3].y -= 3;
    } else if (curStatus == 1) {
        temp[0].x += 1;
        temp[1].x += 2;
        temp[2].x += 3;
        temp[0].y += 3;
        temp[1].y += 2;
        temp[2].y += 1;
    } else if (curStatus == 2) {
        temp[1].x -= 1;
        temp[2].x -= 2;
        temp[3].x -= 3;
        temp[1].y -= 1;
        temp[2].y -= 2;
        temp[3].y -= 3;
    } else {
        temp[0].x += 1;
        temp[1].x += 2;
        temp[2].x += 3;
        temp[0].y += 3;
        temp[1].y += 2;
        temp[2].y += 1;
    }
    
    return temp;
}

std::vector<Posn> Iblock::rot_ccw() {
    return rot_cw();
}

char Iblock::getType() { return type; }


// Jblock Implementation
Jblock::~Jblock() {
    // std::cout << "Jblock destructor called" << std::endl;
}

std::vector<Posn> Jblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[2].x -= 1;
        temp[3].x -= 1;
        temp[2].y -= 2;
        temp[3].y -= 2;
    } else if (curStatus == 1) {
        temp[0].y += 1;
        temp[1].y += 1;
        temp[2].x += 2;
        temp[3].x += 2;
    } else if (curStatus == 2) {
        temp[0].y += 1;
        temp[1].y += 1;
        temp[2].x -= 1;
        temp[3].x -= 1;
        temp[2].y -= 1;
        temp[3].y -= 1;
    } else {
        temp[2].x += 1;
        temp[3].x += 1;
        temp[0].y += 1;
        temp[1].y += 1;
        temp[0].x -= 1;
        temp[1].x -= 1;
    }
    return temp;
}

std::vector<Posn> Jblock::rot_ccw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[0].x += 1;
        temp[3].y -= 2;
        temp[3].x -= 1;
    } else if (curStatus == 1) {
        temp[1].y += 2;
        temp[0].x += 2;
        temp[0].y += 2;
    } else if (curStatus == 2) {
        temp[0].y -= 1;
        temp[1].y -= 1;
        temp[2].x -= 2;
        temp[3].x -= 2;
    } else {
        temp[2].y -= 1;
        temp[3].y -= 1;
        temp[0].x += 1;
        temp[0].y += 1;
        temp[1].x += 1;
        temp[1].y += 1;
    }
    return temp;
}

char Jblock::getType() { return type; }


// Lblock Implementation
Lblock::~Lblock() {
    // std::cout << "Lblock destructor called" << std::endl;
}

std::vector<Posn> Lblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[0].y -= 1;
        temp[3].y -= 1;
        temp[0].x -= 2;
        temp[3].x -= 2;
    } else if (curStatus == 1) {
        temp[0].y += 1;
        temp[3].y -= 1;
        temp[0].x += 2;
    } else if (curStatus == 2) {
        temp[0].y -= 1;
        temp[2].x -= 1;
        temp[2].y -= 1;
        temp[3].x += 1;
    } else {
        temp[0].y += 2;
        temp[2].x += 1;
        temp[1].x += 1;
        temp[1].y += 2;
    }
    return temp;
}

std::vector<Posn> Lblock::rot_ccw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[1].y -= 2;
        temp[2].y -= 2;
        temp[0].x -= 1;
        temp[3].x -= 1;
        std::cout << "I am here 0" << std::endl;
    } else if (curStatus == 1) {
        temp[0].x += 2;
        temp[0].y += 2;
        temp[1].x += 2;
        std::cout << "I am here 1" << std::endl;
    } else if (curStatus == 2) {
        temp[1].y += 1;
        temp[2].x -= 2;
        temp[2].y -= 1;
        std::cout << "I am here 2" << std::endl;
    } else {
        temp[0].y += 2;
        temp[1].x -= 1;
        temp[1].y += 1;
        temp[3].x += 1;
        temp[3].y -= 1;
        std::cout << "I am here 3" << std::endl;
    }
    return temp;
}

char Lblock::getType() { return type; }


// Oblock Implementation
Oblock::~Oblock() {
    // std::cout << "Oblock destructor called" << std::endl;
}

std::vector<Posn> Oblock::rot_cw() {
    return points;
}

std::vector<Posn> Oblock::rot_ccw() {
    return rot_cw();
}

char Oblock::getType() { return type; }


// Sblock Implementation
Sblock::~Sblock() {
    // std::cout << "Sblock destructor called" << std::endl;
}

std::vector<Posn> Sblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[1].x -= 2;
        temp[1].y -= 1;
        temp[2].y -= 1;
    } else if (curStatus == 1) {
        temp[0].x += 2;
        temp[0].y += 1;
        temp[1].y += 1;
    } else if (curStatus == 2) {
        temp[1].x -= 2;
        temp[1].y -= 1;
        temp[2].y -= 1;
    } else {
        temp[0].x += 2;
        temp[0].y += 1;
        temp[1].y += 1;
    }
    return temp;
}

std::vector<Posn> Sblock::rot_ccw() {
    return rot_cw();
}

char Sblock::getType() { return type; }

// Zblock Implementation
Zblock::~Zblock() {
    // std::cout << "Zblock destructor called" << std::endl;
}

std::vector<Posn> Zblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[2].x -= 1;
        temp[3].x -= 1;
        temp[3].y -= 2;
    } else if (curStatus == 1) {
        temp[0].x += 1;
        temp[0].y += 2;
        temp[3].x += 1;
    } else if (curStatus == 2) {
        temp[2].x -= 1;
        temp[3].x -= 1;
        temp[3].y -= 2;
    } else {
        temp[0].x += 1;
        temp[0].y += 2;
        temp[3].x += 1;
    }
    return temp;
}

std::vector<Posn> Zblock::rot_ccw() {
    return rot_cw();
}

char Zblock::getType() { return type; }


// Tblock Implementation
Tblock::~Tblock() {
    // std::cout << "Tblock destructor called" << std::endl;
}

std::vector<Posn> Tblock::rot_cw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[2].x -= 1;
        temp[2].y -= 1;
    } else if (curStatus == 1) {
        temp[0].x += 1;
        temp[0].y += 2;
        temp[1].y += 1;
    } else if (curStatus == 2) {
        temp[2].x -= 1;
        temp[2].y -= 1;
        temp[3].x -= 2;
        temp[3].y -= 2;
    } else {
        temp[3].x += 1;
        temp[0].x += 2;
        temp[0].y += 1;
    }
    return temp;
}

std::vector<Posn> Tblock::rot_ccw() {
    std::vector<Posn> temp;
    temp.clear();
    for (int a = 0; a < 4; a++) {
        temp.emplace_back(points[a]);
    }
    if (curStatus == 0) {
        temp[3].x -= 1;
        temp[2].x -= 2;
        temp[2].y -= 1;
    } else if (curStatus == 1) {
        temp[0].x += 1;
        temp[0].y += 1;
    } else if (curStatus == 2) {
        temp[1].y -= 1;
        temp[3].x -= 1;
        temp[3].y -= 2;
    } else {
        temp[0].x += 2;
        temp[0].y += 2;
        temp[1].x += 1;
        temp[1].y += 1;
    }
    return temp;
}

char Tblock::getType() { return type; }
