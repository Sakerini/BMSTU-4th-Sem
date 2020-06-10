#include <io/readerimplementator_stdio.h>
#include <exception/error.h>
#include <iostream>
#include <factory/model3dfactory.h>
#include <io/reader.h>
#include "model3d.h"

Model3d::Model3d()
: IModel(),
_loaded(false),
factory(Model3dFactory::getInstance()){

}

void Model3d::clean() {
    delete _position;

    for (auto point : points) {
        delete point;
    }
    points.clear();

    for (auto edge : edges) {
        delete edge;
    }
    edges.clear();

    _loaded = false;
}

Model3d::~Model3d() {
    clean();
}

Model3d* Model3d::clone() const {
    return new Model3d(*this);
}

void Model3d::rotate(double alpha, double beta, double gamma) {
    if (!_loaded)
        throw ModelNotLoaded(__FILE__, __LINE__, __FUNCTION__);

    for (auto point : points)
        point->rotate(*_position, alpha, beta, gamma);
}

void Model3d::rotate(const IPoint &center, double alpha, double beta, double gamma){
    if (!_loaded)
        throw ModelNotLoaded(__FILE__, __LINE__, __FUNCTION__);

    for (auto point : points)
        point->rotate(center, alpha, beta, gamma);

    this->_position->rotate(center, alpha, beta, gamma);
}

void Model3d::updateCenter() {
    auto min = factory->createPoint(points[0]->getX(), points[0]->getY(), points[0]->getZ());
    auto max = factory->createPoint(points[0]->getX(), points[0]->getY(), points[0]->getZ());

    for (auto point : points) {

        if (min->getX() > point->getX())
            min->setX(point->getX());

        if (min->getY() > point->getY())
            min->setY(point->getY());

        if (min->getZ() > point->getZ())
            min->setZ(point->getZ());

        if (max->getX() < point->getX())
            max->setX(point->getX());

        if (max->getY() < point->getY())
            max->setY(point->getY());

        if (max->getZ() < point->getZ())
            max->setZ(point->getZ());
    }

    min->setX(min->getX() + (max->getX() - min->getX()) / 2);
    min->setY(min->getY() + (max->getY() - min->getY()) / 2);
    min->setZ(min->getZ() + (max->getZ() - min->getZ()) / 2);

    delete max;
    delete _position;
    _position = min;
}

void Model3d::scale(double k) {
    if (!_loaded)
        throw ModelNotLoaded(__FILE__, __LINE__, __FUNCTION__);

    for (auto point : points)
        point->scale(*_position, k);
}

void Model3d::scale(const IPoint &center, double k){
    if (!_loaded)
        throw ModelNotLoaded(__FILE__, __LINE__, __FUNCTION__);

    for (auto point : points)
        point->scale(center, k);

    this->_position->scale(center, k);
}

void Model3d::transfer(double dx, double dy, double dz) {
    if (!_loaded)
        throw ModelNotLoaded(__FILE__, __LINE__, __FUNCTION__);

    for (auto point : points)
        point->transfer(dx, dy, dz);
}

std::vector<IPoint *> &Model3d::getPoints() {
    return points;
}

std::vector<IEdge *> &Model3d::getEdges() {
    return edges;
}

void Model3d::setPoints(const std::vector<IPoint *> &points) {
    Model3d::points = points;
}

void Model3d::setEdges(const std::vector<IEdge *> &edges) {
    Model3d::edges = edges;
}

void Model3d::setLoaded(bool loaded) {
    _loaded = loaded;
}
