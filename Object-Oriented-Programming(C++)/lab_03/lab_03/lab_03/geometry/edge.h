#ifndef LAB_03_EDGE_H
#define LAB_03_EDGE_H

#include "iedge.h"

class Edge final : public IEdge {
public:
    Edge(unsigned startPointId, unsigned endPointId);
    virtual ~Edge();

    unsigned getStartPointId() const override;
    unsigned getEndtPointId() const override;

private:
    unsigned startPointId { 0 };
    unsigned endPointId { 0 };
};


#endif
