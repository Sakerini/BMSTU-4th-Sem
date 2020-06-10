#ifndef LAB_03_MAINCONTROLLER_H
#define LAB_03_MAINCONTROLLER_H


#include <mainwindow.h>
#include <geometry/model/imodel.h>
#include <command/command.h>
#include <datamanager/viewerdatamanager.h>
#include "patterns/observer/subject.h"

class MainController : public Observer {
    friend union IAppCommand::Argument;
public:
    MainController();
    virtual ~MainController();
    void update(Subject *subject) override;

private:
    MainWindow *_subject { nullptr };
    ViewerDataManager _dataManager;

};


#endif
