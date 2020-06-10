#ifndef LAB_03_IMEDIATOR_H
#define LAB_03_IMEDIATOR_H


#include <string>
#include <ui/camera/camera.h>
#include <QtWidgets/QGraphicsScene>
#include "iparticipant.h"

class IMediator {
public:
    virtual ~IMediator() {};
    virtual void setParticipant(std::shared_ptr<IParticipant> participant) = 0;
    virtual void broadcastMessage(QGraphicsScene *scene, std::shared_ptr<IModel>& model, std::shared_ptr<Camera>& camera) = 0;
};


#endif
