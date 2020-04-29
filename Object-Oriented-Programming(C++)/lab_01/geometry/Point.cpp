#include <cmath>
#include "Point.h"

static err_t rotateX(point_t *point, double angle);
static err_t rotateY(point_t *point, double angle);
static err_t rotateZ(point_t *point, double angle);

point_t* newPoint() {
    auto *point = new point_t;

    point->x = 0;
    point->y = 0;
    point->z = 0;

    return point;
}

point_t* newPoint(double x, double y, double z) {

    auto *point = new point_t;

    point->x = x;
    point->y = y;
    point->z = z;

    return point;
}

void transferPoint(point_t *point, const point_t * const center) {
    point->x -= center->x;
    point->y -= center->y;
    point->z -= center->z;
}

void returnPoint(point_t *point, const point_t * const center) {
    point->x += center->x;
    point->y += center->y;
    point->z += center->z;
}

err_t rotatePoint(point_t *point, const point_t *center, double alpha, double beta, double gamma) {
    err_t rc = ERROR_OK;
    if (!center) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "center nullptr exception");
        return rc;
    }
    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    transferPoint(point, center);

    rotateX(point, alpha);
    rotateY(point, beta);
    rotateZ(point, gamma);

    returnPoint(point, center);

    return rc;
}

static err_t rotateX(point_t *point, double angle) {
    err_t rc = ERROR_OK;

    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    double sinus = sin(angle);
    double cosinus = cos(angle);

    double newY = point->y * cosinus - point->z * sinus;
    double newZ = point->y * sinus + point->z * cosinus;

    point->y = newY;
    point->z = newZ;

    return rc;
}

static err_t rotateY(point_t *point, double angle) {
    err_t rc = ERROR_OK;
    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    double sinus = sin(angle);
    double cosinus = cos(angle);

    double newX = point->x * cosinus + point->z * sinus;
    double newZ = -point->x * sinus + point->z * cosinus;

    point->x = newX;
    point->z = newZ;

    return rc;
}

static err_t rotateZ(point_t *point, double angle) {
    err_t rc = ERROR_OK;
    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    double sinus = sin(angle);
    double cosinus = cos(angle);

    double newX = point->x * cosinus - point->y * sinus;
    double newY = point->x * sinus + point->y  * cosinus;

    point->x = newX;
    point->y = newY;

    return rc;
}

err_t transferPoint(point_t *point, double dx, double dy, double dz) {
    err_t rc = ERROR_OK;
    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    point->x += dx;
    point->y += dy;
    point->z += dz;

    return rc;
}

err_t scalePoint(point_t *point, const point_t *center, double k) {
    err_t rc = ERROR_OK;
    if (!center) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "center nullptr exception");
        return rc;
    }
    if (!point) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, __LINE__, "point nullptr exception");
        return rc;
    }

    point->x = (point->x - center->x) * k + center->x;
    point->y = (point->y - center->y) * k + center->y;
    point->z = (point->z - center->z) * k + center->z;

    return rc;
}

void destroyPoint(const point_t* point) {
    if (point) {
        delete point;
    }
}
