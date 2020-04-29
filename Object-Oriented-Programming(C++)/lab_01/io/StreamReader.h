#ifndef LAB_01_FILE_H
#define LAB_01_FILE_H

#include <cstdio>
#include "exceptionhandling/Error.h"
#include "geometry/Point.h"
#include "geometry/Edge.h"

#define STREAM FILE

STREAM* openStream(const char *path);
err_t checkStream(STREAM *stream);
void closeStream(STREAM *stream);

err_t scanEdge(edge_t *edge, STREAM *stream);
err_t scanPoint(point_t *point, STREAM *stream);
err_t scanN(unsigned &nPoints, unsigned &nEdges, STREAM *stream);
err_t loadPoints(point_t ** point_array, unsigned pointN, STREAM *stream);
err_t loadEdges(edge_t ** edges_array, unsigned edgesN, STREAM *stream);


#endif
