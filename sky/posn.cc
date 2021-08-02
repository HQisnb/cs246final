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
    y -= 1;
}

void Posn::print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
