#ifndef LAB_03_DRAWIMPLEMENTATER_H
#define LAB_03_DRAWIMPLEMENTATER_H

#include "icommandexecuteimplementer.h"

class DrawImplementer : public ICommandExecuteImplementer {
public:
    DrawImplementer() {};
    void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) override;
};


#endif
//Drawer::drawModel(subjState.data.draw, *model);
