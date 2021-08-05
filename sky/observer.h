#ifndef OBSERVER_H
#define OBSERVER_H
#include "cell.h"
class Cell;

class Observer {
    public:
    //testing purpose notify();
    void notify(Cell &s);
    // virtual void notify(Cell &s) = 0;  // s is the Subject that called the notify method
    // virtual ~Observer() = default;// TODO: keep this line or not?
};

#endif
