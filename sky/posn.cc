#include "posn.h"
#include <iostream>

Posn::Posn(int a, int b) : x{a}, y{b} {};

void Posn::left() {
    x -= 1;
}

void Posn::right() {
    x += 1;
}

void Posn::down() {
    y += 1;
}

void Posn::print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

bool smallerThan(Posn a, Posn b) {//if a is smaller than b
    if (a.y < b.y) {
        return true;
    } else if (a.y == b.y) {
        if (a.x < b.x) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
