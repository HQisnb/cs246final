#ifndef GRAPH_H
#define GRAPH_H

#include "window.h"
#include "board.h"
#include "textDisplay.h"
#include <sstream>

class Graph {
    public:
    Board* b1;
    Board* b2;
    Xwindow * xw;
    int sizeB = 20;
    int secondPosn = 260;
    int firstPosn = 20;
    int firstH = 50;
    int nextB = 440;
    TextDisplay* td;
    public:
    Graph(Board *b1, Board *b2, TextDisplay *td);
    // here is to print the graph of biquadris
    void printGraph();
};

#endif

