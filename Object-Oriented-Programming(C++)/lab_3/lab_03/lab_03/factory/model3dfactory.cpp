#include <command/command.h>
#include <geometry/model/model3d.h>
#include "model3dfactory.h"
#include <controller/maincontroller.h>
#include <ui/scene/sceneobjectcomposite.h>
#include <controller/icommandexecuteimplementer.h>
#include <controller/drawimplementater.h>
#include <controller/motionimplementer.h>
#include <controller/loadimplementater.h>
#include <controller/groupimplementater.h>
#include <controller/executor.h>

Model3dFactory* Model3dFactory::instance = nullptr;

Model3dFactory* Model3dFactory::getInstance() {
    if (!instance) {
        instance = new Model3dFactory();
        return instance;
    }

    return instance;
}

Model3dFactory::Model3dFactory() {}

ScaleCommand* Model3dFactory::createScaleCommand() {
    return new ScaleCommand();
}

ScaleCommand* Model3dFactory::createScaleCommand(std::shared_ptr<SceneObjectComposite> composite) {
    return new ScaleCommand(composite);
}

RotateCommand* Model3dFactory::createRotateCommand() {
    return new RotateCommand();
}

RotateCommand* Model3dFactory::createRotateCommand(std::shared_ptr<SceneObjectComposite> composite) {
    return new RotateCommand(composite);
}

TransferCommand* Model3dFactory::createTransferCommand() {
    return new TransferCommand();
}

TransferCommand* Model3dFactory::createTransferCommand(std::shared_ptr<SceneObjectComposite> composite) {
    return new TransferCommand(composite);
}

Model3d* Model3dFactory::createModel() {
    return new Model3d();
}

MainController* Model3dFactory::createMainController() {
    return new MainController();
}

DrawImplementer* Model3dFactory::createDrawImplementer() {
    return new DrawImplementer();
}

MotionImplementer* Model3dFactory::createMotionImplementer() {
    return new MotionImplementer();
}

GroupImplementer* Model3dFactory::createGroupImplementer() {
    return new GroupImplementer();
}

LoadModelImplementer* Model3dFactory::createLoadImplementer() {
    return new LoadModelImplementer();
}

Executor* Model3dFactory::createExecutor(std::shared_ptr<ICommandExecuteImplementer> implementer){
    return new Executor(std::move(implementer));
}

Point* Model3dFactory::createPoint(double x, double y, double z) {
    return new Point(x, y, z);
}

Point* Model3dFactory::createPoint(const IPoint *point){
    return new Point(point->getX(), point->getY(), point->getZ());
}

Edge* Model3dFactory::createEdge(unsigned startPointId, unsigned endPointId) {
    return new Edge(startPointId, endPointId);
}

SceneObjectComposite* Model3dFactory::createSceneObjectComposite() {
    return new SceneObjectComposite();
}

Camera* Model3dFactory::createCamera() {
    return new Camera();
}

Camera* Model3dFactory::createCamera(std::shared_ptr<IPoint> viewPoint, double alpha, double beta, double gamma) {
    return new Camera(std::move(viewPoint), alpha, beta, gamma);
}

Camera* Model3dFactory::createCamera(double xViewPoint, double yViewPoint, double zViewPoint,
                                     double alpha, double beta, double gamma) {
    return new Camera(xViewPoint, yViewPoint, zViewPoint, alpha, beta, gamma);
}

Drawer* Model3dFactory::createDrawer() {
    return new Drawer();
}

DrawerMediator* Model3dFactory::createDrawerMediator() {
    return new DrawerMediator();
}
