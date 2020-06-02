#ifndef LAB_04_SCENEOBJECT_H
#define LAB_04_SCENEOBJECT_H


#include <geometry/ipoint.h>
#include <memory>

class SceneObject {
public:
    SceneObject();
    //explicit SceneObject(const SceneObject &obj);
    virtual ~SceneObject() {};

    virtual void rotate(const IPoint& center, double alpha, double beta, double gamma) = 0;
    virtual void rotate(double alpha, double beta, double gamma) = 0;

    virtual void transfer(double dx, double dy, double dz) = 0;

    virtual void scale(const IPoint& center, double k) = 0;
    virtual void scale(double k) = 0;
};


#endif
