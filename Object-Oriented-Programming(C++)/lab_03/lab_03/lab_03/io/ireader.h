#ifndef LAB_03_IREADER_H
#define LAB_03_IREADER_H


#include <geometry/iedge.h>
#include <geometry/ipoint.h>

class IReader {
public:
    virtual bool getN(unsigned &nPoints, unsigned &nEdges) = 0;
    virtual bool getNextEdge(IEdge *&edge) = 0;
    virtual bool getNextPoint(IPoint *&point) = 0;
};


#endif
