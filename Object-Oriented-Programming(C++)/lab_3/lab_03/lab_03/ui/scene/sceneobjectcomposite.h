#ifndef LAB_04_SCENEOBJECTCOMPOSITE_H
#define LAB_04_SCENEOBJECTCOMPOSITE_H


#include <vector>
#include "sceneobject.h"

class SceneObjectComposite final : SceneObject {
public:
    SceneObjectComposite();
    ~SceneObjectComposite();

    void add(std::shared_ptr<SceneObject> sceneObject);
    void remove(std::shared_ptr<SceneObject> sceneObject);

    void rotate(const IPoint& center, double alpha, double beta, double gamma) override;
    void rotate(double alpha, double beta, double gamma) override;

    void transfer(double dx, double dy, double dz) override;

    void scale(const IPoint& center, double k) override;
    void scale(double k) override;

    std::vector<std::shared_ptr<SceneObject>>::iterator begin();
    std::vector<std::shared_ptr<SceneObject>>::iterator end();
private:
    std::vector<std::shared_ptr<SceneObject>> _objects;
};


#endif
