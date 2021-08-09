#include "window.cc"
#include <sstream>

class Graph {
    protected:
    Board* b1;
    Board* b2;
    Xwindow xw;
    int sizeB = 20;
    int secondPosn = 260;
    int firstPosn = 20;
    int firstH = 50;
    int nextB = 440;
    public:
    // here is to print the graph of biquadris
    void printGraph();
};
