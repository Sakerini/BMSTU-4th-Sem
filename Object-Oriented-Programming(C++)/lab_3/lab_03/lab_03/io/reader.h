#ifndef LAB_03_READER_H
#define LAB_03_READER_H


#include "ireader.h"
#include "ireaderimplementator.h"

class Reader final : public IReader {
public:
    explicit Reader(IReaderImplementator &implementator);
    virtual ~Reader();

    bool getN(unsigned &nPoints, unsigned &nEdges) override;
    bool getNextEdge(IEdge *&edge) override;
    bool getNextPoint(IPoint *&point) override;

private:
    IReaderImplementator& _implementator;
};


#endif
