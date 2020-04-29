#include "exceptionhandling/Error.h"
#include "Edge.h"

edge_t* newEdge() {
    auto* edge = new edge_t;

    edge->startPointId = 0;
    edge->endPointId = 0;

    return edge;
}

edge_t* newEdge(unsigned startInd, unsigned endInd) {
    auto* edge = new edge_t;

    edge->startPointId = startInd;
    edge->endPointId = endInd;

    return edge;
}

void getInd(unsigned& startInd, unsigned& endInd, const edge_t* edge) {
    if (!edge) {
        handleErr(ERROR_ARG, __FILE__, __LINE__, "edge nullptr exception");
        return;
    }

    startInd = edge->startPointId;
    endInd = edge->endPointId;
}

void destroyEdge(const edge_t* edge) {
    if (edge) {
        delete edge;
    }
}

