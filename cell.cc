#include <vector>
class Cell;

class Observer {
    public:
    virtual void notify(Cell &s) = 0;  // s is the Subject that called the notify method
    virtual ~Observer() = default;
};

class Subject {
    protected:
    std::vector<Observer*> observers;
    public:
    void attach(Observer *o) {
        observers.emplace_back(o);
    }
    void detach(Observer *o) {
        delete o;
    }
    virtual void notifyObservers() = 0;
};

class Cell : public Subject, public Observer {
    int row;
    int column;
    int boardNo;
    char type = ' ';
    bool filled = false;
    Cell(int row, int column, int boardNo) : row{row}, column{column}, boardNo{boardNo} {}
    ~Cell() {}
    char getType() {
        return this->type;
    }
    bool isEmpty() {
        return this->filled;
    } 
    void notifyObservers() {
        observers[0]->notify(*this);
    }
    friend class TextDisplay;
};

