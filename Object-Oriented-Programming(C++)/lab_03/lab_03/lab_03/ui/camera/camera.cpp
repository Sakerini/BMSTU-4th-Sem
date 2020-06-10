#include <factory/iabstractfactory.h>
#include <factory/model3dfactory.h>
#include "camera.h"
#include <geometry/point.h>

Camera::Camera()
: _alpha(0),
  _beta(0),
  _gamma(0) {
    _viewPoint.reset(Model3dFactory::getInstance()->createPoint(0, 0, 0));
}

Camera::Camera(double xViewPoint, double yViewPoint, double zViewPoint, double alpha, double beta, double gamma)
: _alpha(alpha),
  _beta(beta),
  _gamma(gamma) {
    _viewPoint.reset(Model3dFactory::getInstance()->createPoint(xViewPoint, yViewPoint, zViewPoint));
}

Camera::Camera(std::shared_ptr<IPoint> viewPoint, double alpha, double beta, double gamma)
: _viewPoint(std::move(viewPoint)),
  _alpha(alpha),
  _beta(beta),
  _gamma(gamma) {

}

Camera::~Camera() {
}

std::shared_ptr<IPoint>& Camera::getViewPoint() {
    return _viewPoint;
}

void Camera::setViewPoint(std::shared_ptr<IPoint> viewPoint) {
    _viewPoint = std::move(viewPoint);
}

void Camera::setViewPoint(double x, double y, double z) {
    _viewPoint.reset(Model3dFactory::getInstance()->createPoint(x, y, z));
}

double Camera::getAlpha() {
    return _alpha;
}

void Camera::setAlpha(double alpha) {
    _alpha = alpha;
}

void Camera::setBeta(double beta) {
    _beta = beta;
}

double Camera::getBeta() {
    return _beta;
}

void Camera::setGamma(double gamma) {
    _gamma = gamma;
}

double Camera::getGamma() {
    return _gamma;
}

void Camera::rotate(const IPoint& center, double alpha, double beta, double gamma) {
    _viewPoint->rotate(center, alpha, beta, gamma);
}

void Camera::rotate(double alpha, double beta, double gamma) {
    // TODO _viewPoint->rotate(, alpha, beta, gamma);
}

void Camera::transfer(double dx, double dy, double dz) {
    _viewPoint->transfer(dx, dy, dz);
}

void Camera::scale(const IPoint& center, double k) {
    // Maybe this is bad idea))
    _viewPoint->scale(center, k);
}

void Camera::scale(double k) {
    // Same as above((
    // TODO

}
