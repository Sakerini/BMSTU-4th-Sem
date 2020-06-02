#ifndef LAB_03_MODEL3DFACTORY_H
#define LAB_03_MODEL3DFACTORY_H

#include <ui/drawer.h>
#include <ui/drawermediator.h>
#include "iabstractfactory.h"

class Point;
class Executor;
class ScaleCommand;
class RotateCommand;
class TransferCommand;
class SceneObjectComposite;
class Model3d;
class LoadModelImplementer;
class GroupImplementer;
class DrawImplementer;
class MotionImplementer;
class ViewerDataManager;
class Camera;
class ICommandExecuteImplementer;

// With singleton
class Model3dFactory final : public IAbstractFactory {
public:
    static Model3dFactory* getInstance();

    ScaleCommand* createScaleCommand() override;
    ScaleCommand* createScaleCommand(std::shared_ptr<SceneObjectComposite> composite) override;

    RotateCommand* createRotateCommand() override;
    RotateCommand* createRotateCommand(std::shared_ptr<SceneObjectComposite> composite) override;

    TransferCommand* createTransferCommand() override;
    TransferCommand* createTransferCommand(std::shared_ptr<SceneObjectComposite> composite) override;

    Model3d* createModel() override;
    MainController* createMainController() override;

    // For Bridge
    DrawImplementer* createDrawImplementer();
    MotionImplementer* createMotionImplementer();
    GroupImplementer* createGroupImplementer();
    LoadModelImplementer* createLoadImplementer();
    Executor* createExecutor(std::shared_ptr<ICommandExecuteImplementer> implementer);

    Point* createPoint(double x, double y, double z) override;
    Point* createPoint(const IPoint *point) override;
    Edge* createEdge(unsigned startPointId, unsigned endPointId) override;
    SceneObjectComposite* createSceneObjectComposite();
    Camera* createCamera();
    Camera* createCamera(double xVewPoint, double yViewPoint, double zViewPoint, double alpha, double beta, double gamma);
    Camera* createCamera(std::shared_ptr<IPoint> viewPoint, double alpha, double beta, double gamma);

    Drawer* createDrawer();
    DrawerMediator* createDrawerMediator();

private:
    Model3dFactory();
    static Model3dFactory* instance;
};


#endif
