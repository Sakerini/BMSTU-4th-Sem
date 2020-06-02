#include <factory/model3dfactory.h>
#include <exception/error.h>
#include <ui/drawer.h>
#include "maincontroller.h"
#include "mainwindow.h"
#include <command/command.h>
#include <controller/drawimplementater.h>
#include <controller/executor.h>
#include <controller/groupimplementater.h>
#include <controller/loadimplementater.h>
#include <controller/motionimplementer.h>

MainController::MainController() {
    auto *factory = Model3dFactory::getInstance();

    _dataManager.addCommand(MainWindow::ROTATE, std::shared_ptr<RotateCommand>(factory->createRotateCommand()));
    _dataManager.addCommand(MainWindow::SCALE, std::shared_ptr<ScaleCommand>(factory->createScaleCommand()));
    _dataManager.addCommand(MainWindow::TRANSFER, std::shared_ptr<TransferCommand>(factory->createTransferCommand()));

    auto motionImplementer = std::shared_ptr<MotionImplementer>(factory->createMotionImplementer());
    auto motionExecutor = std::shared_ptr<Executor>(factory->createExecutor(motionImplementer));

    _dataManager.addExecutor(MainWindow::ROTATE, motionExecutor);
    _dataManager.addExecutor(MainWindow::TRANSFER, motionExecutor);
    _dataManager.addExecutor(MainWindow::SCALE, motionExecutor);

    auto loadImplementer = std::shared_ptr<ICommandExecuteImplementer>(factory->createLoadImplementer());
    auto loadExecutor = std::shared_ptr<Executor>(factory->createExecutor(loadImplementer));
    _dataManager.addExecutor(MainWindow::LOAD_MODEL, loadExecutor);

    auto drawImplementer = std::shared_ptr<ICommandExecuteImplementer>(factory->createDrawImplementer());
    auto drawExecutor = std::shared_ptr<Executor>(factory->createExecutor(drawImplementer));
    _dataManager.addExecutor(MainWindow::DRAW, drawExecutor);

    auto groupImplementer = std::shared_ptr<ICommandExecuteImplementer>(factory->createGroupImplementer());
    auto groupExecutor = std::shared_ptr<Executor>(factory->createExecutor(groupImplementer));
    _dataManager.addExecutor(MainWindow::GROUP, groupExecutor);

    _dataManager.addCamera(0, std::shared_ptr<Camera>(factory->createCamera()));
    _dataManager.setActiveCamera(0);

    auto drawer= std::shared_ptr<Drawer>(factory->createDrawer());
    auto drawerMediator = std::shared_ptr<DrawerMediator>(factory->createDrawerMediator());
    drawerMediator->setParticipant(drawer);

    _dataManager.setDrawerMediator(drawerMediator);
}

MainController::~MainController() {
}

void MainController::update(Subject *subject) {
    _subject = (MainWindow *) subject;
    MainWindow::State subjState = _subject->getState();

    auto executor = _dataManager.getExecutor(subjState.cmd);
    executor->execute(_dataManager, subjState.arg, subjState.cmd);
    //ToDo vmesto datamanager peredavat abstarct datamanager
}
