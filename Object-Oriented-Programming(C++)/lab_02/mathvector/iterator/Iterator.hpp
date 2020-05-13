#include "Iterator.h"
#include "../exception/Error.h"

namespace mathvector {

    template <typename T>
    Iterator<T>::Iterator(const Iterator<T> &iter) {
        this->positon = iter.positon;
    }


    template <typename T>
    Iterator<T>::Iterator(std::shared_ptr<T> p, size_t pos)
    : BaseIterator<T>(std::shared_ptr<T>(p)) {
        this->position = pos;
    }

    template <typename T>
    T &Iterator<T>::operator*() {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);

        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return *(data + this->position);
    }

    template <typename T>
    const T Iterator<T>::operator*() const {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);

        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return *(data + this->position);
    }

    template <typename T>
    T *Iterator<T>::operator->() {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);

        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return data + this->position;
    }

    template <typename T>
    const T *Iterator<T>::operator->() const {
        auto thisPtr = this->ptr.lock();
        time_t t_time = time(NULL);

        if (!thisPtr) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        T *data = thisPtr.get();

        return data + this->position;
    }

    /* ___________________________________________ IteratorConst ____________________________________________________ */
    template <typename T>
    IteratorConst<T>::IteratorConst(const Iterator<T> &iter) {
        this->position = iter.position;
        this->ptr = iter.ptr;
    }

    template <typename T>
    IteratorConst<T>::IteratorConst(std::shared_ptr<T> p, size_t pos) {
        this->ptr = p;
        this->position = pos;
    }

    /*
    template <typename T>
    const T IteratorConst<T>::operator*() const {
        auto thisPtr = this->ptr.lock();

        if (!thisPtr) {
            throw WeakPointerError();
        }

        T *data = thisPtr.get();

        return *(data + this->position);
    }

    template <typename T>
    const T *IteratorConst<T>::operator->() const {
        auto thisPtr = this->ptr.lock();

        if (!thisPtr) {
            throw WeakPointerError();
        }

        T *data = thisPtr.get();

        return data + this->position;
    }
     */
}