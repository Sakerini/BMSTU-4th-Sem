#include "reader.h"

Reader::Reader(IReaderImplementator &implementator)
: _implementator(implementator) {


}

Reader::~Reader() {

}

bool Reader::getN(unsigned &nPoints, unsigned &nEdges) {
    return _implementator.getN(nPoints, nEdges);
}

bool Reader::getNextEdge(IEdge *&edge) {
    return _implementator.getNextEdge(edge);
}

bool Reader::getNextPoint(IPoint *&point) {
    return _implementator.getNextPoint(point);
}
