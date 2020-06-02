#ifndef LAB_03_IPOINT_H
#define LAB_03_IPOINT_H

class IPoint {
public:
    virtual ~IPoint() {};
    virtual double getX() const = 0;
    virtual void setX(double x) = 0;

    virtual double getY() const = 0;
    virtual void setY(double y) = 0;

    virtual double getZ() const = 0;
    virtual void setZ(double z) = 0;

    virtual void rotate(const IPoint &center, double alpha, double beta, double gamma) = 0;
    virtual void transfer(double dx, double dy, double dz) = 0;
    virtual void scale(const IPoint &center, double k) = 0;
};


#endif
