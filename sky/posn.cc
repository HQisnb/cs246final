#include "posn.h"
#include <iostream>

Posn::Posn(int a, int b) : x{a}, y{b} {};

void Posn::print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
