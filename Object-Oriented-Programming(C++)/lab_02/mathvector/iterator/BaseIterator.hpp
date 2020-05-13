#include "BaseIterator.h"
#include "../exception/Error.h"

namespace mathvector {

    template <typename T>
    BaseIterator<T>::BaseIterator(const BaseIterator<T> &iter)
    : position(iter.position) {
        ptr = iter.ptr.lock();
    }

    template <typename T>
    BaseIterator<T>::BaseIterator(std::shared_ptr<T> p) {
        ptr = p;
    }

    template <typename T>
    BaseIterator<T>::~BaseIterator() {

    }

    template <typename T>
    BaseIterator<T>& BaseIterator<T>::operator=(const BaseIterator<T> &iter) {
        ptr = iter.ptr;
        position = iter.position;

        return *this;
    }

    template <typename T>
    BaseIterator<T>& BaseIterator<T>::operator++() {
        position++;
        return *this;
    }

    template <typename T>
    BaseIterator<T> BaseIterator<T>::operator++(int) {
        BaseIterator<T> res(*this);
        operator++();
        return res;
    }

    template <typename T>
    BaseIterator<T>& BaseIterator<T>::operator--() {
        position--;
        return *this;
    }

    template <typename T>
    BaseIterator<T> BaseIterator<T>::operator--(int) {
        BaseIterator<T> res(*this);
        operator--();
        return res;
    }

    template <typename T>
    bool BaseIterator<T>::operator==(const BaseIterator& iter) {
        auto thisPtr = ptr.lock();
        auto iterPtr = iter.ptr.lock();

        time_t t_time = time(NULL);

        if (!(thisPtr && iterPtr)) {
            throw WeakPointerError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Weak pointer error");
        }

        return thisPtr.get() == iterPtr.get() && position == iter.position;
    }

    template <typename T>
    bool BaseIterator<T>::operator!=(const BaseIterator& iter) {
        return !(*this == iter);
    }
}
