#ifndef LAB_03_IPARTICIPANT_H
#define LAB_03_IPARTICIPANT_H


#include <string>
#include <geometry/model/imodel.h>
#include <ui/camera/camera.h>

class IParticipant {
public:
    virtual ~IParticipant() {};
    virtual void receiveMessage(QGraphicsScene *scene, std::shared_ptr<IModel>& modele, std::shared_ptr<Camera>& camera) = 0;
};


#endif