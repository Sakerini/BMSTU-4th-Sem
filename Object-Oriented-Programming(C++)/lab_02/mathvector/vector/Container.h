#ifndef LAB_02_CONTAINER_H
#define LAB_02_CONTAINER_H

#include <cstddef>

namespace mathvector {

    class Container {
    public:
        bool isEmpty() const;
        std::size_t getSize() const;
        virtual void resize(size_t newSize);
        virtual void abstract() = 0;

    protected:
        std::size_t size;

        virtual void setSize(std::size_t newSize);
    };

}

#include "Container.hpp"

#endif //LAB_02_CONTAINER_H
