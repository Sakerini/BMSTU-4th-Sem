#ifndef LAB_02_ITERATOR_H
#define LAB_02_ITERATOR_H

#include <cstddef>
#include "BaseIterator.h"

namespace mathvector {
    template <typename T>
    class Iterator : public BaseIterator<T> {
    public:
        Iterator(const Iterator<T> &iter);
        Iterator(std::shared_ptr<T> p, size_t pos = 0);

        T &operator*();
        const T operator*() const;
        T *operator->();
        const T *operator->() const;
    };


    template <typename T>
    class IteratorConst : public BaseIterator<T> {
    public:
        IteratorConst(const Iterator<T> &iter);
        IteratorConst(std::shared_ptr<T> p, size_t pos = 0);

        const T& operator*() const;
        const T *operator->() const;
    };
};

#include "Iterator.hpp"

#endif //LAB_02_ITERATOR_H
