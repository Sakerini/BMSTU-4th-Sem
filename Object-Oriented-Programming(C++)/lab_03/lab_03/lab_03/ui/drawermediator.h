#ifndef LAB_03_DRAWERMEDIATOR_H
#define LAB_03_DRAWERMEDIATOR_H


#include "imediator.h"
#include <memory>
#include <vector>

class DrawerMediator final : public IMediator {
public:
    ~DrawerMediator() { };
    void setParticipant(std::shared_ptr<IParticipant> participant) override;
    void broadcastMessage(QGraphicsScene *scene, std::shared_ptr<IModel>& model, std::shared_ptr<Camera>& camera) override;

private:
    std::shared_ptr<IParticipant> _participant { nullptr };

};


#endif
