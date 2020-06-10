#include "edge.h"

Edge::Edge(unsigned startId, unsigned endId)
: startPointId(startId),
endPointId(endId) {

}

Edge::~Edge(){

}

unsigned Edge::getStartPointId() const {
    return startPointId;
}

unsigned Edge::getEndtPointId() const {
    return endPointId;
}
