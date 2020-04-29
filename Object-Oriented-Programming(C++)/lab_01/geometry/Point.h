#ifndef LAB_01_POINT_H
#define LAB_01_POINT_H

#include "exceptionhandling/Error.h"

typedef struct {
    double x;
    double y;
    double z;
} point_t;

point_t* newPoint();
point_t* newPoint(double x, double y, double z);
err_t rotatePoint(point_t *point, const point_t *center, double alpha, double beta, double gamma);
err_t transferPoint(point_t *point, double dx, double dy, double dz);
err_t scalePoint(point_t *point, const point_t *center, double k);
void destroyPoint(const point_t* point);

#endif //LAB_01_POINT_H
