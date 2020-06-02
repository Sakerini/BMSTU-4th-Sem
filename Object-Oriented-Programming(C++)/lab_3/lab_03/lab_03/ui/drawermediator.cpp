#include "drawermediator.h"

void DrawerMediator::setParticipant(std::shared_ptr<IParticipant> participant) {
    _participant = std::move(participant);
}

void DrawerMediator::broadcastMessage(QGraphicsScene *scene, std::shared_ptr<IModel> &model,
                                      std::shared_ptr<Camera> &camera){
    _participant->receiveMessage(scene, model, camera);
}
