#ifndef LAB_03_EXECUTOR_H
#define LAB_03_EXECUTOR_H


#include <mainwindow.h>
#include "icommandexecute.h"
#include "icommandexecuteimplementer.h"

class Executor : public ICommandExecutor {
public:
    explicit Executor(std::shared_ptr<ICommandExecuteImplementer> implementer);
    void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) override;

private:
    std::shared_ptr<ICommandExecuteImplementer> _implementer { nullptr };
};


#endif
