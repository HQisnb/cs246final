#include "subject.h"

void Subject::attach(Observer *o) {
        observer = o;
}

// void Subject::notifyObservers() {
//         std::cout << "subject is notifying observers" << std::endl;
//         observer->notify(Cell &s);
// }