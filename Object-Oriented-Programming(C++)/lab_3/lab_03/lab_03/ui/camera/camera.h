#ifndef LAB_03_CAMERA_H
#define LAB_03_CAMERA_H


#include <ui/scene/sceneobject.h>

class Camera final : public SceneObject {
public:
    Camera();
    Camera(double xVewPoint, double yViewPoint, double zViewPoint, double alpha, double beta, double gamma);
    Camera(std::shared_ptr<IPoint> viewPoint, double alpha, double beta, double gamma);
    ~Camera() override;

    std::shared_ptr<IPoint>& getViewPoint();
    void setViewPoint(std::shared_ptr<IPoint> viewPoint);
    void setViewPoint(double x, double y, double z);

    double getAlpha();
    void setAlpha(double alpha);

    void setBeta(double beta);
    double getBeta();

    void setGamma(double gamma);
    double getGamma();

    void rotate(const IPoint& center, double alpha, double beta, double gamma) override;
    void rotate(double alpha, double beta, double gamma) override;

    void transfer(double dx, double dy, double dz) override;

    void scale(const IPoint& center, double k) override;
    void scale(double k) override;

private:
    std::shared_ptr<IPoint> _viewPoint { nullptr };
    double _alpha { 0 };
    double _beta { 0 };
    double _gamma { 0 };

};


#endif
