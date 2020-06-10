#ifndef LAB_03_SUBJECT_H
#define LAB_03_SUBJECT_H


#include <vector>
#include "patterns/observer/observer.h"

class Subject {
public:
    Subject() {};
    virtual ~Subject() {};
    virtual void attach(Observer *observer);
    virtual void detach(Observer *observer);
    virtual void notify();

private:
    std::vector<Observer*> _observers;
};


#endif
