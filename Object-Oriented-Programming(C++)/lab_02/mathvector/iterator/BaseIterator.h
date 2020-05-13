#ifndef LAB_02_BASEITERATOR_H
#define LAB_02_BASEITERATOR_H

#include <memory>

namespace mathvector {

    template <typename T>
    class BaseIterator {
    public:
        BaseIterator(const BaseIterator<T> &iter);
        BaseIterator(std::shared_ptr<T> p);
        virtual ~BaseIterator();
        BaseIterator<T>& operator=(const BaseIterator<T> &iter);
        BaseIterator<T>& operator++();
        BaseIterator<T> operator++(int);
        BaseIterator<T>& operator--();
        BaseIterator<T> operator--(int);


        bool operator==(const BaseIterator& iter);
        bool operator!=(const BaseIterator& iter);

    protected:
        std::weak_ptr<T> ptr;
        size_t position;
    };

}

#include "BaseIterator.hpp"

#endif //LAB_02_BASEITERATOR_H
