#ifndef LAB_03_IEDGE_H
#define LAB_03_IEDGE_H


class IEdge {
public:
    virtual ~IEdge() {};
    virtual unsigned getStartPointId() const = 0;
    virtual unsigned getEndtPointId() const = 0;
};


#endif
