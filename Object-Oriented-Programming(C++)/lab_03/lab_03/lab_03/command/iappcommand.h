#ifndef LAB_03_IAPPCOMMAND_H
#define LAB_03_IAPPCOMMAND_H

#include <QGraphicsScene>
#include <geometry/model/imodel.h>
#include <ui/scene/sceneobjectcomposite.h>
#include <memory>
#include <vector>


class IAppCommand {
public:
    union Argument {
        struct scale {
            double k;
        };

        struct rotate {
            double alpha;
            double beta;
            double gamma;
        };

        struct transfer {
            double dx;
            double dy;
            double dz;
        };

        union motion_data {
            rotate rotate_act;
            transfer transfer_act;
            scale scale_act;
        };

        struct motion {
            unsigned id;
            motion_data data;

        };

        struct load {
            unsigned id;
            char *file;
        };

        struct group {
            unsigned new_id;
            //std::vector<unsigned> ids;
        };

        load load_act;
        QGraphicsScene *draw_act;

        motion motion;
        group group_act;

        unsigned set_active_camera_act;

    };

    IAppCommand() {};
    explicit IAppCommand(std::shared_ptr<SceneObjectComposite> &composite);
    virtual ~IAppCommand() {};
    virtual void setComposite(std::shared_ptr<SceneObjectComposite> &composite);

    virtual void execute(Argument arg) = 0;

protected:
    std::shared_ptr<SceneObjectComposite> _composite { nullptr };
};


#endif
