#include "MathVector.h"

#include <cmath>
#include "MathVector.h"
#include <iostream>
using namespace std;

namespace mathvector {

    template <typename T>
    MathVector<T>::MathVector() {
        setSize(0);
        coords = std::shared_ptr<T>((T*)nullptr, free);
    }

    template <typename T>
    MathVector<T>::MathVector(const std::vector<T> &data) {
        setSize(data.size());
        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        for (std::size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = data[i];
        }
    }

    template <typename T>
    MathVector<T>::MathVector(T *data, size_t size) {
        setSize(size);
        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        for (std::size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = data[i];
        }
    }

    template <typename T>
    MathVector<T>::MathVector(std::initializer_list<T> data) {
        this->setSize(data.size());

        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        std::size_t i = 0;
        for (auto& el : data) {
            coords.get()[i] = el;
            ++i;
        }
    }

    template <typename T>
    MathVector<T>::MathVector(const MathVector<T> &vec) {
        setSize(vec.getSize());

        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        for (std::size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = vec[i];
        }
    }

    template <typename T>
    MathVector<T>::MathVector(MathVector<T> &&vec) {
        setSize(vec.getSize());

        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        for (std::size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = vec[i];
        }

        vec.coords = nullptr;
        vec.setSize(0);
    }

    template <typename T>
    MathVector<T>::MathVector(std::size_t initial_size) {
        setSize(initial_size);

        coords = std::shared_ptr<T>((T*)malloc(getSize() * sizeof(T)), free);
        time_t t_time = time(NULL);

        if (coords.get() == nullptr) {
            throw MemoryError(t_time, __FILE__, typeid(*this).name(), __LINE__, "Memory not load");
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = 0;
        }

    }

    template <typename T>
    MathVector<T>::~MathVector()  {
        this->setSize(0);
    }



    template <typename T>
    T MathVector<T>::length() const {
        T sum = 0;
        for (std::size_t i = 0; i < getSize(); i++) {
            sum += coords.get()[i] * coords.get()[i];
        }

        return sqrt(sum);
    }

    template <typename T>
    MathVector<T> MathVector<T>::norm() const {
        MathVector<T> tmp(*this);

        T ln = length();
        for (size_t i = 0; i < getSize(); i++) {
            tmp[i] = coords.get()[i] / ln;
        }

        return tmp;
    }

    template <typename T>
    MathVector<T>& MathVector<T>::normalize() {
        T ln = length();
        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] /= ln;
        }

        return *this;
    }

    template <typename T>
    MathVector<T> MathVector<T>::multiplication(const MathVector<T> &vec) const {

        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        MathVector<T> tmp(*this);

        for (std::size_t i = 0; i < getSize(); i++) {
            tmp[i] *= vec[i];
        }

        return tmp;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator&(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        MathVector<T> tmp(*this);

        for (std::size_t i = 0; i < getSize(); i++) {
            tmp[i] *= vec[i];
        }

        return tmp;
    }
    template <typename T>
    T MathVector<T>::operator*(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        T sum = 0;
        for (size_t i = 0; i < getSize(); i++) {
            sum += coords.get()[i] * vec[i];
        }

        return sum;
    }

    template <typename T>
    T MathVector<T>::angle(const MathVector<T> &vec) const {
        T angle = 1;

        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (std::size_t i = 0; i < getSize(); i++) {
            angle += coords.get()[i] * vec[i];
        }

        return angle / (length() * vec.length());
    }

    template <typename T>
    bool MathVector<T>::ort(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        T sum = 0;
        for (std::size_t i = 0; i < getSize(); i++) {
            sum += coords.get()[i] * vec[i];
        }

        return sum == 0;
    }

    template <typename T>
    bool MathVector<T>::collinearity(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        if (getSize() >= 1) {
            T k = coords.get()[0] / vec[0];
            for (std::size_t i = 0; i < getSize(); i++) {
                if (k != coords.get()[i] / vec[i]) {
                    return false;
                }
            }
        }

        return true;
    }


    template <typename T>
    T &MathVector<T>::operator[](std::size_t i) {
        if (i < 0 || i >= getSize()) {
            throw BoundariesError();
        }

        return coords.get()[i];
    }

    template <typename T>
    const T &MathVector<T>::operator[](std::size_t i) const {
        if (i < 0 || i >= getSize()) {
            throw BoundariesError();
        }

        return coords.get()[i];
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator=(const MathVector<T> &vec) {

        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = vec[i];
        }

        return *this;
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator=(MathVector<T> &&vec) {

        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] = vec[i];
        }

        vec.resize(0);
        vec.coords = nullptr;

        return *this;
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator=(std::initializer_list<T> values) {
        if (getSize() != values.size()) {
            throw SizeError();
        }

        size_t i = 0;
        for (auto &el : values) {
            coords.get()[i] = el;
            ++i;
        }

        return *this;
    }


    template <typename T>
    MathVector<T> &MathVector<T>::operator+=(const MathVector<T> &vec) {
        if (size != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] += vec[i];
        }

        return *this;
    }

    template <typename T>
    MathVector<T> MathVector<T>::addTo(const MathVector<T> &vec) {
        if (size != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] += vec[i];
        }

        return *this;
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator-=(const MathVector<T> &vec) {
        if (size != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] -= vec[i];
        }

        return *this;
    }
    template <typename T>
    MathVector<T> MathVector<T>::subFrom(const MathVector<T> &vec) {
        if (size != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] -= vec[i];
        }

        return *this;
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator*=(T var) {
        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] *= var;
        }

        return *this;
    }
    template <typename T>
    MathVector<T> MathVector<T>::multiplyTo(T var){
        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] *= var;
        }

        return *this;
    }

    template <typename T>
    MathVector<T> &MathVector<T>::operator/=(T var) {
        if (var == 0) {
            throw DivisionByZeroError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] /= var;
        }

        return *this;
    }

    template <typename T>
    MathVector<T> MathVector<T>::devideFrom(T var) {
        if (var == 0) {
            throw DivisionByZeroError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            coords.get()[i] /= var;
        }

        return *this;
    }


    template <typename T>
    bool MathVector<T>::operator==(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            if (coords.get()[i] != vec[i]) {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    bool MathVector<T>::equals(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            if (coords.get()[i] != vec[i]) {
                return false;
            }
        }

        return true;
    }

    template <typename T>
    bool MathVector<T>::operator!=(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            if (coords.get()[i] != vec[i]) {
                return true;
            }
        }

        return false;
    }
    template <typename T>
    bool MathVector<T>::notEquals(const MathVector<T> &vec) const {
        if (getSize() != vec.getSize()) {
            throw SizeError();
        }

        for (size_t i = 0; i < getSize(); i++) {
            if (coords.get()[i] != vec[i]) {
                return true;
            }
        }

        return false;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator*(T var) const {
        MathVector<T> res(*this);

        return res *= var;
    }
    template <typename T>
    MathVector<T> MathVector<T>::multiply(T *var) {
        MathVector<T> res(*this);

        return res *= var;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator/(T var) const {
        MathVector<T> res(*this);

        return res /= var;
    }

    template <typename T>
    MathVector<T> MathVector<T>::devide(T *var) {
        MathVector<T> res(*this);

        return res /= var;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator+(const MathVector<T> &vec) const {
        MathVector<T> res(*this);

        return res += vec;
    }
    template <typename T>
    MathVector<T> MathVector<T>::add(const MathVector<T> &vec) const {
        MathVector<T> res(*this);

        return res += vec;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator-(const MathVector<T> &vec) const {

    }
    template <typename T>
    MathVector<T> MathVector<T>::sub(const MathVector<T> &vec) const {

    }

    template <typename T>
    MathVector<T> MathVector<T>::operator+() const {
        MathVector<T> res(*this);

        return res *= 1;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator-() const {
        MathVector<T> res(*this);

        return res *= -1;
    }

    template <typename T>
    Iterator<T> MathVector<T>::begin() {
        return Iterator<T>(coords);
    }

    template <typename T>
    Iterator<T> MathVector<T>::end() {
        return Iterator<T>(coords, size);
    }

    template <typename T>
    IteratorConst<T> MathVector<T>::begin() const {
        return IteratorConst<T>(coords);
    }

    template <typename T>
    IteratorConst<T> MathVector<T>::end() const {
        return IteratorConst<T>(coords, size);
    }
}
