#ifndef LAB_03_MODEL3D_H
#define LAB_03_MODEL3D_H


#include <geometry/point.h>
#include <geometry/edge.h>
#include <vector>
#include <factory/iabstractfactory.h>
#include "imodel.h"

class Model3d final: public IModel {
public:
    Model3d();
    ~Model3d();
    Model3d* clone() const override;

    void rotate(double alpha, double beta, double gamma) override;
    void rotate(const IPoint& center, double alpha, double beta, double gamma) override;
    void scale(double k) override;
    void scale(const IPoint& center, double k) override;
    void transfer(double dx, double dy, double dz) override;
    void clean();

    std::vector<IPoint *> &getPoints() override;
    std::vector<IEdge *> &getEdges() override;

    void setPoints(const std::vector<IPoint *> &points);

    void setEdges(const std::vector<IEdge *> &edges);

    void updateCenter();

    void setLoaded(bool loaded);


private:

    IAbstractFactory *factory { nullptr };
    std::vector<IPoint*> points;
    std::vector<IEdge*> edges;
    IPoint *_position { nullptr };
    bool _loaded { false };
};


#endif
