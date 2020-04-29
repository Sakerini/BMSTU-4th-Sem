#ifndef LAB_01_MAINCONTROLLER_H
#define LAB_01_MAINCONTROLLER_H

#include <QGraphicsScene>
#include <ui/Drawer.h>

#include "geometry/models/Model3d.h"
#include "exceptionhandling/Error.h"

enum action {
    LOAD,
    SCALE,
    ROTATE,
    TRANSFER,
    DRAW,
    DESTROY
};

struct scale {
    double k;
};

struct rotate {
    double x;
    double y;
    double z;
};

struct transfer {
    double dx;
    double dy;
    double dz;
};


union argument {
    char *load_act;
    QGraphicsScene *draw_act;

    rotate rotate_act;
    scale scale_act;
    transfer transfer_act;

    void *none = nullptr;
};

err_t process(const action act, argument arg);

#endif //LAB_01_MAINCONTROLLER_H
