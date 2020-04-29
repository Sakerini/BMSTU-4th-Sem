#include <assert.h>
#include "exceptionhandling/Error.h"
#include "geometry/Edge.h"
#include "geometry/models/Model3d.h"

#include "io/StreamReader.h"

static void allocateModel(model_t &model, unsigned nPoints, unsigned nEdges);
static point_t* findCenter(const model_t& model);
static void moveModel(model_t &to, const model_t &from);

model_t initModel() {
    model_t model;

    model.center = nullptr;
    model.points = nullptr;
    model.edges = nullptr;

    model.nPoints = 0;
    model.nEdges = 0;

    return model;
}

err_t loadModel(model_t& model, STREAM *stream) {
    err_t rc = checkStream(stream);
    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not open stream");
        return rc;
    }

    model_t tmp = initModel();

    rc = scanN(tmp.nPoints, tmp.nEdges, stream);
    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not read number of points and number of edges");
        return rc;
    }

    allocateModel(tmp, tmp.nPoints, tmp.nEdges);

    rc = loadPoints(tmp.points, tmp.nPoints, stream);
    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not read all points");
        destroyModel(tmp);
    } else {

        rc = loadEdges(tmp.edges, tmp.nEdges, stream);
        if (rc != ERROR_OK) {
            handleErr(rc, __FILE__, __LINE__, "Can not read all edges");
            destroyModel(tmp);
        } else {

            destroyModel(model);

            tmp.center = findCenter(tmp); //

            moveModel(model, tmp);
        }
    }
    return rc;
}

static void allocateModel(model_t &model, unsigned nPoints, unsigned nEdges) {
    model.points = new point_t*[nPoints];
    model.edges = new edge_t*[nEdges];
    model.nPoints = nPoints;
    model.nEdges = nEdges;
    model.center = nullptr;

    for (int i = 0; i < nPoints; i++) {
        model.points[i] = newPoint();
    }

    for (int i = 0; i < nEdges; i++) {
        model.edges[i] = newEdge();
    }
}

static point_t* findCenter(const model_t& model) {
    point_t* min = newPoint(model.points[0]->x, model.points[0]->y, model.points[0]->z);
    point_t* max = newPoint(model.points[0]->x, model.points[0]->y, model.points[0]->z);

    for (int i = 0; i < model.nPoints; i++) {
        auto point = model.points[i];

        if (min->x > point->x)
            min->x = point->x;

        if (min->y > point->y)
            min->y = point->y;

        if (min->z > point->z)
            min->z = point->z;

        if (max->x < point->x)
            max->x = point->x;

        if (max->y < point->y)
            max->y = point->y;

        if (max->z < point->z)
            max->z = point->z;
    }

    min->x = min->x + (max->x - min->x) / 2;
    min->y = min->y + (max->y - min->y) / 2;
    min->z = min->z + (max->z - min->z) / 2;

    destroyPoint(max);
    return min;
}

static void moveModel(model_t &to, const model_t &from) {
    to.center = from.center;
    to.points = from.points;
    to.edges = from.edges;
    to.nPoints = from.nPoints;
    to.nEdges = from.nEdges;
}

void destroyModel(model_t &model) {
    destroyPoint(model.center);
    model.center = nullptr;

    if (model.points) {
        for (int i = 0; i < model.nPoints; i++) {
            destroyPoint(model.points[i]);
            model.points[i] = nullptr;
        }

        delete[] model.points;
    }

    if (model.edges) {
        for (int i = 0; i < model.nEdges && model.edges; i++) {
            destroyEdge(model.edges[i]);
            model.edges[i] = nullptr;
        }

        delete[] model.edges;
    }

    model.edges = nullptr;
    model.points = nullptr;
}

err_t rotateModel(model_t &model, double xAngle, double yAngle, double zAngle) {
    err_t rc = checkModel(model, __LINE__);
    if (rc != ERROR_OK) {
        return rc;
    }

    for (int i = 0; i < model.nPoints; i++) {
        rotatePoint(model.points[i], model.center, xAngle, yAngle, zAngle);
    }

    return rc;
}

err_t transferModel(model_t &model, double dx, double dy, double dz) {
    err_t rc = checkModel(model, __LINE__);
    if (rc != ERROR_OK) {
        return rc;
    }

    for (int i = 0; i < model.nPoints; i++) {
        transferPoint(model.points[i], dx, dy, dz);
    }

    transferPoint(model.center, dx, dy, dz);

    return rc;
}

err_t scaleModel(model_t &model, double k) {
    err_t rc = checkModel(model, __LINE__);
    if (rc != ERROR_OK) {
        return rc;
    }

    for (int i = 0; i < model.nPoints; i++) {
        scalePoint(model.points[i], model.center, k);
    }

    return rc;
}

// TODO delete
void printPoint(const point_t* point) {
    std::cout << point->x << ", " << point->y << ", " << point->z << std::endl;
}

// TODO delete
void print(const model_t& model) {
    std::cout << "center: ";
    printPoint(model.center);

    std::cout << "edges: " << std::endl;
    for (int i = 0; i < model.nEdges; i++) {
        std::cout << model.edges[i]->startPointId << ", " << model.edges[i]->endPointId << std::endl;
    }

    std::cout << "points: " << std::endl;
    for (int i = 0; i < model.nPoints; i++) {
        printPoint(model.points[i]);
    }
}

err_t checkModel(const model_t& model, int line) {
    err_t rc = ERROR_OK;
    if (!model.center) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, line, "model.center nullptr exception");
    }
    if (!model.points) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, line, "model.points nullptr exception");
    }
    if (!model.edges) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, line, "model.edges nullptr exception");
    }
    if (model.nPoints <= 0) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, line, "model.nPoints <= 0");
    }
    if (model.nEdges <= 0) {
        rc = ERROR_ARG;
        handleErr(rc, __FILE__, line, "model.nEdges <= 0");
    }

    return rc;
}

