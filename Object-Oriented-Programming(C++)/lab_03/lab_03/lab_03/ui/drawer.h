#ifndef LAB_03_DRAWER_H
#define LAB_03_DRAWER_H

#include <QtWidgets/QGraphicsScene>
#include <geometry/model/imodel.h>
#include "iparticipant.h"

class Drawer final : public IParticipant {
private:

    void drawLine(QGraphicsScene *scene, const IPoint &p1, const IPoint &p2);
    void drawEdge(QGraphicsScene *scene, IModel &model, const IEdge *edge, Camera& camera);

public:
    Drawer() {};
    ~Drawer() {};
    void receiveMessage(QGraphicsScene *scene, std::shared_ptr<IModel>& model, std::shared_ptr<Camera>& camera) override;
};


#endif
