#ifndef POSN_H
#define POSN_H
#include <iostream>

class Posn {
	public:
	int x;
	int y;
	
	Posn(int a, int b);
	void left();
	void right();
	void down();
	void print();
};

bool smallerThan(Posn a, Posn b);

#endif