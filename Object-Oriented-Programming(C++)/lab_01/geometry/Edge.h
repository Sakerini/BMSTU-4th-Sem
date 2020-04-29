#ifndef LAB_01_EDGE_H
#define LAB_01_EDGE_H

typedef struct {
    unsigned startPointId;
    unsigned endPointId;
} edge_t;

edge_t* newEdge();
edge_t* newEdge(unsigned startInd, unsigned endInd);
void getInd(unsigned& startInd, unsigned& endInd, const edge_t* edge);
void destroyEdge(const edge_t* edge);

#endif //LAB_01_EDGE_H
