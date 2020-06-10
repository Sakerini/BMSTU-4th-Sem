#include <algorithm>
#include "sceneobjectcomposite.h"

SceneObjectComposite::SceneObjectComposite() {

}

SceneObjectComposite::~SceneObjectComposite() {

}

void SceneObjectComposite::add(std::shared_ptr<SceneObject> sceneObject){
    bool in = false;
    for (auto obj : _objects)
        if (obj == sceneObject)
            in = true;

    if (!in)
        _objects.push_back(sceneObject);
}

void SceneObjectComposite::remove(std::shared_ptr<SceneObject> sceneObject){
    _objects.erase(std::remove(_objects.begin(), _objects.end(), sceneObject), _objects.end());
}

std::vector<std::shared_ptr<SceneObject>>::iterator SceneObjectComposite::begin() {
    return _objects.begin();
}

std::vector<std::shared_ptr<SceneObject>>::iterator SceneObjectComposite::end() {
    return _objects.end();
}

void SceneObjectComposite::rotate(const IPoint& center, double alpha, double beta, double gamma) {
    for (auto obj : _objects)
        obj->rotate(center, alpha, beta, gamma);
}

void SceneObjectComposite::rotate(double alpha, double beta, double gamma) {
    for (auto obj : _objects)
        obj->rotate(alpha, beta, gamma);
}

void SceneObjectComposite::transfer(double dx, double dy, double dz) {
    for (auto obj : _objects)
        obj->transfer(dx, dy, dz);
}

void SceneObjectComposite::scale(const IPoint& center, double k) {
    for (auto obj : _objects)
        obj->scale(center, k);
}

void SceneObjectComposite::scale(double k) {
    for (auto obj : _objects)
        obj->scale(k);
}

