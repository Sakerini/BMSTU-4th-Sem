#include "executor.h"

Executor::Executor(std::shared_ptr<ICommandExecuteImplementer> implementer) : _implementer(std::move(implementer)) { }

void Executor::execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) {
    _implementer->execute(dm, arg, cmd);
}
