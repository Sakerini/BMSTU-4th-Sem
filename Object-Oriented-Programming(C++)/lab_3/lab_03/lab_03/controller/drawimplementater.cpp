#include <ui/drawer.h>
#include "drawimplementater.h"

void DrawImplementer::execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) {
    auto mediator = dm.getDrawerMediator();
    auto camera = dm.getActiveCamera();
    auto models = dm.getModels();
    for (auto model : models) {

        mediator->broadcastMessage(arg.draw_act, model.second, camera);
    }
}