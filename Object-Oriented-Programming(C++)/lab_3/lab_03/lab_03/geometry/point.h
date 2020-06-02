#ifndef LAB_03_POINT_H
#define LAB_03_POINT_H

#include "ipoint.h"

class Point final : public IPoint {
public:
    Point(double x, double y, double z);
    explicit Point(const Point &point);
    Point& operator=(const Point& point);
    ~Point();

    double getX() const override;
    void setX(double x) override;
    double getY() const override;
    void setY(double y) override;
    double getZ() const override;
    void setZ(double z) override;

    void rotate(const IPoint& center, double alpha, double beta, double gamma) override;
    void transfer(double dx, double dy, double dz) override ;
    void scale(const IPoint& center, double k) override;

private:
    void rotateX(const IPoint& center, double angle);
    void rotateY(const IPoint& center, double angle);
    void rotateZ(const IPoint& center, double angle);

    double x { 0 };
    double y { 0 };
    double z { 0 };
};


#endif
