#ifndef LAB_01_MODEL3D_H
#define LAB_01_MODEL3D_H

#include "geometry/Point.h"
#include "geometry/Edge.h"
#include "io/StreamReader.h"
#include "exceptionhandling/Error.h"

struct model_t{
    point_t* center = nullptr;

    point_t** points = nullptr;
    edge_t** edges = nullptr;

    unsigned nPoints = 0;
    unsigned nEdges = 0;
};


model_t initModel();
err_t loadModel(model_t& model, STREAM *stream);
void destroyModel(model_t &model);
err_t rotateModel(model_t &model, double xAngle, double yAngle, double zAngle);
err_t transferModel(model_t &model, double dx, double dy, double dz);
err_t scaleModel(model_t &model, double k);
void printPoint(const point_t* point);
void print(const model_t& model);
err_t checkModel(const model_t& model, int line);

#endif //LAB_01_MODEL3D_H
