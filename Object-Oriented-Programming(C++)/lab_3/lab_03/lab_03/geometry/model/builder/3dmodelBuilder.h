#ifndef LAB_03_3DMODELBUILDER_H
#define LAB_03_3DMODELBUILDER_H

#include <io/readerimplementator_stdio.h>
#include <io/reader.h>
#include <exception/error.h>
#include <command/iappcommand.h>
#include "imodelbuilder.h"

class ModelBuilder3d : public IModelBuilder {
private:
    const char * source;
public:
    ModelBuilder3d(const char *source);
    void Reset();
    void setPoints(unsigned nPoints, Reader reader) override;
    void setEdges(unsigned nEdges, Reader reader) override;
    Model3d* getResult() override; //Todo change to shared ptr
};
#endif
