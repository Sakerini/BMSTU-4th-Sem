#ifndef LAB_03_ICOMMANDEXECUTE_H
#define LAB_03_ICOMMANDEXECUTE_H


#include <command/iappcommand.h>
#include <mainwindow.h>

class ViewerDataManager;

class ICommandExecutor {
public:
    virtual void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) = 0;
};


#endif
