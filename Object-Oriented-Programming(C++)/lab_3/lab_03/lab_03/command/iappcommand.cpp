#include <geometry/model/imodel.h>
#include "iappcommand.h"

IAppCommand::IAppCommand(std::shared_ptr<SceneObjectComposite> &composite) : _composite(composite) {}

void IAppCommand::setComposite(std::shared_ptr<SceneObjectComposite> &composite){
    _composite = composite;
}

