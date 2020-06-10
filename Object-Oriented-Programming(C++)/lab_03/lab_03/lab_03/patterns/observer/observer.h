#ifndef LAB_03_OBSERVER_H
#define LAB_03_OBSERVER_H

class Subject;

class Observer {
public:
    Observer() {};
    virtual ~Observer() {};
    virtual void update(Subject *subject) = 0;
};


#endif
