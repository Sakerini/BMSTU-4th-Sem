#ifndef LAB_03_ICOMMANDEXECUTEIMPLEMENTER_H
#define LAB_03_ICOMMANDEXECUTEIMPLEMENTER_H


#include <datamanager/viewerdatamanager.h>
#include <command/iappcommand.h>

class ICommandExecuteImplementer {
public:
    virtual void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) = 0;
};


#endif