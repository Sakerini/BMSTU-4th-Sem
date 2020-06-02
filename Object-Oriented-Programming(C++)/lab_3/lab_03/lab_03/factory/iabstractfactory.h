#ifndef LAB_03_IABSTRACTFACTORY_H
#define LAB_03_IABSTRACTFACTORY_H


#include <memory>
#include <geometry/ipoint.h>

class ScaleCommand;
class RotateCommand;
class TransferCommand;
class Model3d;
class Point;
class Edge;
class SceneObjectComposite;

class MainController;

class IAbstractFactory {
public:
    virtual ~IAbstractFactory() {};
    virtual ScaleCommand* createScaleCommand() = 0;
    virtual ScaleCommand* createScaleCommand(std::shared_ptr<SceneObjectComposite> composite) = 0;
    virtual RotateCommand* createRotateCommand() = 0;
    virtual RotateCommand* createRotateCommand(std::shared_ptr<SceneObjectComposite> composite) = 0;
    virtual TransferCommand* createTransferCommand() = 0;
    virtual TransferCommand* createTransferCommand(std::shared_ptr<SceneObjectComposite> composite) = 0;

    virtual Model3d* createModel() = 0;
    virtual MainController* createMainController() = 0;

    virtual Point* createPoint(double x, double y, double z) = 0;
    virtual Point* createPoint(const IPoint *point) = 0;
    virtual Edge* createEdge(unsigned startPointId, unsigned endPointId) = 0;
};


#endif
