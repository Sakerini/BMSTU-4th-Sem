#ifndef LAB_03_GROUPIMPLEMENTATER_H
#define LAB_03_GROUPIMPLEMENTATER_H

#include "icommandexecuteimplementer.h"

class GroupImplementer : public ICommandExecuteImplementer {
public:
    GroupImplementer() {};
    void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) override;
};


#endif
