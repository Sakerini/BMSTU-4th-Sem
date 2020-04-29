#include "actions.h"
#include <ui/Drawer.h>

err_t actLoadModel(model_t& model, const char *fpath) {
    STREAM* stream = openStream(fpath);

    err_t rc = checkStream(stream);
    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not open stream");
        return rc;
    }

    rc = loadModel(model, stream);
    if (rc != ERROR_OK) {
        handleErr(rc, __FILE__, __LINE__, "Can not load model");
        return rc;
    }

    closeStream(stream);

    return ERROR_OK;
}

err_t actRotate(model_t &model, const rotate &rot) {
    return rotateModel(model, rot.x, rot.y, rot.z);
}

err_t actTransfer(model_t &model, const transfer &tr) {
    return transferModel(model, tr.dx, tr.dy, tr.dz);
}

err_t actScale(model_t &model, const scale &sc) {
    return scaleModel(model, sc.k);
}

err_t actDrawModel(const model_t &model, QGraphicsScene *scene) {
    return drawModel(scene, model);
}

void actDestroy(model_t &model) {
    destroyModel(model);
}
