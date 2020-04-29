#include "exceptionhandling/Error.h"
#include "io/StreamReader.h"
#include <stdio.h>

STREAM* openStream(const char *path) {
    if (path == nullptr || path == "")
        return nullptr;

    puts(path);

    return fopen(path, "r");
}

err_t checkStream(STREAM *stream) {
    if (stream == nullptr)
        return ERROR_FOPEN;
    return ERROR_OK;
}

void closeStream(STREAM *stream) {
    if (stream == nullptr)
        return;

    fclose(stream);
}

err_t scanEdge(edge_t *edge, STREAM *stream) {
    if (stream == nullptr) {
        handleErr(ERROR_ARG, __FILE__, (int)__LINE__, "Unusable stream");
        return ERROR_ARG;
    }

    int buff1;
    int buff2;

    int rc = fscanf(stream, "[%i-%i]\n", &buff1, &buff2);
    if (rc == 2 && buff1 > -1 && buff2 > -1) {
        edge->startPointId = (unsigned)buff1;
        edge->endPointId =  (unsigned)buff2;
        return ERROR_OK;
    }

    handleErr(ERROR_INPUT, __FILE__, (int)__LINE__, "Can not read data!");
    return ERROR_INPUT;
}
err_t loadEdges(edge_t ** edges_array, unsigned edgesN, STREAM *stream) {
    err_t rc = ERROR_OK;
    for (int i = 0; rc == ERROR_OK && i < edgesN; i++) {
        rc = scanEdge(edges_array[i], stream);
    }

    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not read point");
    }

    return rc;
}

err_t scanPoint(point_t *point, STREAM *stream) {
    if (stream == nullptr) {
        handleErr(ERROR_ARG, __FILE__, (int)__LINE__, "Unusable stream");
        return ERROR_ARG;
    }

    int rc = fscanf(stream, "[%lf;%lf;%lf]\n", &point->x, &point->y, &point->z);
    if (rc == 3)
        return ERROR_OK;

    handleErr(ERROR_INPUT, __FILE__, (int)__LINE__, "Can not read data!");
    return ERROR_INPUT;
}

err_t loadPoints(point_t** points_array, unsigned pointN, STREAM *stream) {
    err_t rc = ERROR_OK;

    for (int i = 0; rc == ERROR_OK && i < pointN; i++) {
        rc = scanPoint(points_array[i], stream);
    }

    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not read point");
    }

    return rc;
}

err_t scanN(unsigned &nPoints, unsigned &nEdges, STREAM *stream) {
    if (stream == nullptr) {
        handleErr(ERROR_ARG, __FILE__, (int)__LINE__, "Unusable stream");
        return ERROR_ARG;
    }

    int buff1;
    int buff2;

    int rc = fscanf(stream, "%i %i\n", &buff1, &buff2);
    if (rc == 2 && buff1 > 0 && buff2 > 0) {
        nPoints = (unsigned)buff1;
        nEdges =  (unsigned)buff2;
        return ERROR_OK;
    }

    handleErr(ERROR_INPUT, __FILE__, (int)__LINE__, "Can not read data!");
    return ERROR_INPUT;
}
