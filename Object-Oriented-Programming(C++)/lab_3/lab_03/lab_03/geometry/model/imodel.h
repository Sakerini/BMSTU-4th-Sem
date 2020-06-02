#ifndef LAB_03_IMODEL_H
#define LAB_03_IMODEL_H


#include <vector>
#include <geometry/ipoint.h>
#include <geometry/iedge.h>
#include <ui/scene/sceneobject.h>

class IModel : public SceneObject {
public:
    IModel() : SceneObject() {};
    virtual ~IModel() {};
    virtual IModel* clone() const = 0;

    virtual std::vector<IPoint *> &getPoints() = 0;
    virtual std::vector<IEdge *> &getEdges() = 0;
};

#endif
