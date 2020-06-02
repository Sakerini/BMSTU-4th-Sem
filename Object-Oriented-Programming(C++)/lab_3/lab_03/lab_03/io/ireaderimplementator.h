#ifndef LAB_03_IREADERIMPLEMENTATOR_H
#define LAB_03_IREADERIMPLEMENTATOR_H


#include <geometry/ipoint.h>
#include <geometry/iedge.h>

class IReaderImplementator {
public:
    virtual bool getN(unsigned &nPoints, unsigned &nEdges) = 0;
    virtual bool getNextEdge(IEdge *&edge) = 0;
    virtual bool getNextPoint(IPoint *&point) = 0;
};

#endif
