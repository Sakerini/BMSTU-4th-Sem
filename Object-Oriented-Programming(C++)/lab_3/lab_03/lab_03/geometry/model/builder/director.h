#ifndef LAB_03_DIRECTOR_H
#define LAB_03_DIRECTOR_H

#include <geometry/model/imodel.h>
#include "imodelbuilder.h"
#include "3dmodelBuilder.h"

class Director {
public:
    Director() {};
    Director(std::shared_ptr<ModelBuilder3d> builder) {};
    void changeBuilder(std::shared_ptr<ModelBuilder3d> builder) {
        this->builder = builder;
    };
    Model3d* make() {
        return builder->getResult();
    }
private:
    std::shared_ptr<ModelBuilder3d> builder;
};

#endif