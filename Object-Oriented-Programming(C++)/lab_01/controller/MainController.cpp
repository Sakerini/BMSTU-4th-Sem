#include "actions/actions.h"
#include "MainController.h"

err_t process(const action act, const argument arg) {
    err_t rc = ERROR_OK;
    static model_t model = initModel();

    switch (act) {

        case LOAD:
            rc = actLoadModel(model, arg.load_act);
            break;
        case ROTATE:
            rc = actRotate(model, arg.rotate_act);
            break;
        case TRANSFER:
            rc = actTransfer(model, arg.transfer_act);
            break;
        case SCALE:
            rc = actScale(model, arg.scale_act);
            break;
        case DRAW:
            rc = actDrawModel(model, arg.draw_act);
            break;
        case DESTROY:
            actDestroy(model);
            break;
        /*default:
            rc = ERROR_UNHANDLED_ACTION;
            handleErr(rc, __FILE__, __LINE__, "Unhandled action");
            */
    }

    if (rc == ERROR_ARG && (checkModel(model, __LINE__) != ERROR_OK)) {
        rc = ERROR_MODEL_EMPTY;
        handleErr(rc, __FILE__, __LINE__, "Incorrect model");
    }

    return rc;
}