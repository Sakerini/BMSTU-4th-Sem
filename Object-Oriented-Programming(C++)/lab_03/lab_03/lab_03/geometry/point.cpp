#include <cmath>
#include "point.h"

Point::Point(double x_, double y_, double z_)
: x(x_), y(y_), z(z_) {
}
Point::Point(const Point &point)
: x(point.getX()),
  y(point.getY()),
  z(point.getZ()) {

}

Point::~Point() {

}
Point& Point::operator=(const Point& point) {
    if (this != &point) {
        x = point.getX();
        y = point.getY();
        z = point.getZ();
    }

    return *this;
}

double Point::getX() const {
    return x;
}

void Point::setX(double x) {
    this->x = x;
}

double Point::getY() const {
    return y;
}

void Point::setY(double y) {
    this->y = y;
}

double Point::getZ() const {
    return z;
}

void Point::setZ(double z) {
    this->z = z;
}

void Point::rotate(const IPoint& center, double alpha, double beta, double gamma) {
    rotateX(center, alpha);
    rotateY(center, beta);
    rotateZ(center, gamma);
}

void Point::rotateX(const IPoint& center, double angle) {
    double newY = (this->y - center.getY()) * cos(angle) - (this->z - center.getZ()) * sin(angle) + center.getY();
    double newZ = (this->y - center.getY()) * sin(angle) + (this->z - center.getZ()) * cos(angle) + center.getZ();

    this->y = newY;
    this->z = newZ;
}

void Point::rotateY(const IPoint& center, double angle) {
    double newX =  (this->x - center.getX()) * cos(angle) + (this->z - center.getZ()) * sin(angle) + center.getX();
    double newZ = -(this->x - center.getX()) * sin(angle) + (this->z - center.getZ()) * cos(angle) + center.getZ();

    this->x = newX;
    this->z = newZ;
}

void Point::rotateZ(const IPoint& center, double angle) {

    double newX = (this->x - center.getX()) * cos(angle) - (this->y - center.getY()) * sin(angle) + center.getX();
    double newY = (this->x - center.getX()) * sin(angle) + (this->y - center.getY()) * cos(angle) + center.getY();

    this->x = newX;
    this->y = newY;
}

void Point::transfer(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

void Point::scale(const IPoint& center, double k) {
    x = (x - center.getX()) * k + center.getX();
    y = (y - center.getY()) * k + center.getY();
    z = (z - center.getZ()) * k + center.getZ();
}
