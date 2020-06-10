#ifndef LAB_03_READERIMPLEMENTATOR_STDIO_H
#define LAB_03_READERIMPLEMENTATOR_STDIO_H


#include <geometry/edge.h>
#include <geometry/point.h>
#include <cstdio>
#include <factory/iabstractfactory.h>
#include "ireaderimplementator.h"


class ReaderImplementator : public IReaderImplementator {
public:
    explicit ReaderImplementator(const char *path);
    virtual ~ReaderImplementator();

    bool getN(unsigned &nPoints, unsigned &nEdges) override;
    bool getNextEdge(IEdge *&edge) override;
    bool getNextPoint(IPoint *&point) override;

private:
    FILE *f { nullptr };
    IAbstractFactory *factory { nullptr };
};


#endif
