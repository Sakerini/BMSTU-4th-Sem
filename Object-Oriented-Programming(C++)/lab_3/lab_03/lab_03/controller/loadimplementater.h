#ifndef LAB_03_LOADIMPLEMENTATER_H
#define LAB_03_LOADIMPLEMENTATER_H


#include "icommandexecuteimplementer.h"

class LoadModelImplementer : public ICommandExecuteImplementer {
public:
    LoadModelImplementer() {};
    void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) override;


};


#endif
