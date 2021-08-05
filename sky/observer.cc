#include "observer.h"
#include <iostream>

void Observer::notify(Cell &s) {
	std::cout << "Corresponding TextDisplay observer is notified!" << std::endl;
}
