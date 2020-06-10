#include "motionimplementer.h"

void MotionImplementer::execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) {
    //Todo create commands with abstractFactory
    auto command = dm.getCommand(cmd);
    command->setComposite(dm.getComposite(arg.motion.id));
    command->execute(arg);
}