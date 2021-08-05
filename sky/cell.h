#ifndef CELL_H
#define CELL_H
#include "subject.h"
#include "observer.h"

class Cell : public Subject {
    public:
    int row;//TODO: row increases from up to down?
    int column;
    int boardNo;
    char type = 'E';// E means empty
    bool filled = false;
    
    Cell(int row, int column, int boardNo);
    // ~Cell();
    char getType();
    bool isFilled();
    void notifyObserver() override;
    // friend class TextDisplay;
};

#endif
