#include "exceptionhandling/Error.h"
#include "Drawer.h"

static void drawLine(QGraphicsScene *scene, const point_t *p1, const point_t *p2);
static void drawEdge(QGraphicsScene *scene, const model_t &model, const edge_t *edge);

err_t drawModel(QGraphicsScene *scene, const model_t &model) {
    err_t rc = ERROR_OK;
    if (!scene) {
        rc = ERROR_ARG;
        handleErr(ERROR_ARG, __FILE__, __LINE__, "Scene nullptr exception");
        return rc;
    }
    if ((rc = checkModel(model, __LINE__)) != ERROR_OK) {
        return rc;
    }

    scene->clear();

    for (int i = 0; i < model.nEdges; i++) {
        drawEdge(scene, model, model.edges[i]);
    }

    return rc;
}

static void drawLine(QGraphicsScene *scene, const point_t *p1, const point_t *p2) {
    scene->addLine(p1->x, p1->y, p2->x, p2->y);
}

static void drawEdge(QGraphicsScene *scene, const model_t &model, const edge_t *edge) {
    unsigned i, j;
    getInd(i, j, edge); // TODO vozvr v nachale
    drawLine(scene, model.points[i - 1], model.points[j - 1]);
}
