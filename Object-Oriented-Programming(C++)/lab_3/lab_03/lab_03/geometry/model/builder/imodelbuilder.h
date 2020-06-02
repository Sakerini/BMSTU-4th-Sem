#ifndef LAB_03_IMODELBUILDER_H
#define LAB_03_IMODELBUILDER_H

#include <geometry/model/imodel.h>
#include <geometry/model/model3d.h>

class IModelBuilder {
protected:
    std::shared_ptr<Model3d> product;
public:
    virtual void Reset() = 0;
    virtual void setPoints(unsigned nPoints, Reader reader) = 0;
    virtual void setEdges(unsigned nEdges, Reader reader) = 0;
    virtual Model3d* getResult() = 0;

};

#endif //LAB_03_IMODELBUILDER_H
