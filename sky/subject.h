#ifndef SUBJECT_H
#define SUBJECT_H

class Observer;

class Subject {
    protected:
    Observer * observer;
    public:
    void attach(Observer *o);
    // void detach(Observer *o) {
    //     delete o;//TODO: not sure about this
    // }
    virtual void notifyObserver() = 0;
    // void notifyObservers(Cell &s);
};

#endif
