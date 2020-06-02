#include <iostream>
#include "3dmodelBuilder.h"

ModelBuilder3d::ModelBuilder3d(const char *source) {
        this->source = source;
}

void ModelBuilder3d::Reset() {
    this->product = static_cast<const std::shared_ptr<Model3d>>(new Model3d);
}

void ModelBuilder3d::setPoints(unsigned nPoints, Reader reader) {

    /* Read points */
    IPoint *point = nullptr;
    std::vector<IPoint*> tmp_points;
    for (int i = 0; i < nPoints && reader.getNextPoint(point); i++)
        tmp_points.push_back(point);

    if (tmp_points.size() != nPoints) {
        for (auto p: tmp_points)
            delete p;

        throw InputError(__FILE__, __LINE__, __FUNCTION__);
    }
    product->setPoints(tmp_points);
}

void ModelBuilder3d::setEdges(unsigned int nEdges, Reader reader) {
    IEdge *edge = nullptr;
    std::vector<IEdge*> tmp_edges;
    for (int i = 0; reader.getNextEdge(edge) && i < nEdges; i++)
        tmp_edges.push_back(edge);


    if (tmp_edges.size() != nEdges) {
        for (auto e: tmp_edges)
            delete e;

        throw InputError(__FILE__, __LINE__, __FUNCTION__);
    }
    product->setEdges(tmp_edges);
}

Model3d* ModelBuilder3d::getResult() {
    Reset();
    ReaderImplementator implementator { source };
    Reader reader { implementator };
    unsigned nPoints = 0, nEdges = 0;
    if (!reader.getN(nPoints, nEdges)) {
        throw InputError(__FILE__, __LINE__, __FUNCTION__);
    }
    setPoints(nPoints, reader);
    std::cout<< nPoints << std::endl;
    setEdges(nEdges, reader);
    product->updateCenter();
    product->setLoaded(true);

    return product.get();
}

