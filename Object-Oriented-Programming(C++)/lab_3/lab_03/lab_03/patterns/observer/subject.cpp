#include "subject.h"

void Subject::attach(Observer *observer) {
    _observers.push_back(observer);
}

void Subject::detach(Observer *observer) {
    int count = _observers.size();
    int i = 0;

    for (; i < count; i++) {
        if (_observers[i] == observer)
            break;
    }

    if (i < count)
        _observers.erase(_observers.begin() + i);
}

void Subject::notify() {
    for (int i = 0; i < _observers.size(); i++)
        _observers[i]->update(this);
}


