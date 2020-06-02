#ifndef LAB_03_MOTIONIMPLEMENTER_H
#define LAB_03_MOTIONIMPLEMENTER_H


#include "icommandexecuteimplementer.h"

class MotionImplementer : public ICommandExecuteImplementer {
public:
    MotionImplementer() {};
    void execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) override;

};


#endif
