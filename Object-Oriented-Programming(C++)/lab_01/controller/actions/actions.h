#ifndef LAB_01_ACTIONS_H
#define LAB_01_ACTIONS_H

#include <QGraphicsScene>

#include "geometry/models/Model3d.h"
#include "exceptionhandling/Error.h"
#include "controller/MainController.h"

err_t actLoadModel(model_t& model, const char *fpath);
err_t actRotate(model_t &model, const rotate &rot);
err_t actTransfer(model_t &model, const transfer &tr);
err_t actScale(model_t &model, const scale &sc);
err_t actDrawModel(const model_t &model, QGraphicsScene *scene);
void actDestroy(model_t &model);

#endif //LAB_01_ACTIONS_H
