#ifndef LAB_02_VECTOR_H
#define LAB_02_VECTOR_H

#include <initializer_list>
#include <vector>
#include <memory>

#include "Container.h"
#include "../iterator/Iterator.h"

namespace mathvector {
    template <typename T>
    class MathVector: public Container{

    public:
        MathVector();
        explicit MathVector(std::size_t initial_size);
        explicit MathVector(const std::vector<T> &data);
        MathVector(T *data, size_t size);
        MathVector(std::initializer_list<T> data);
        explicit MathVector(const MathVector<T> &vec);
        MathVector(MathVector<T>&& vec);
        virtual ~MathVector();

        MathVector<T> &operator=(const MathVector<T> &vec);
        MathVector<T> &operator=(MathVector<T> &&vec);
        MathVector<T> &operator=(std::initializer_list<T> values);

        T &operator[](std::size_t i);
        const T &operator[](std::size_t i) const;



        void abstract() override {};

        T length() const;
        MathVector<T> norm() const;
        MathVector<T>& normalize();

        MathVector<T> operator&(const MathVector<T> &vec) const;
        MathVector<T> multiplication(const MathVector<T> &vec) const;
        T operator*(const MathVector<T> &vec) const;
        T angle(const MathVector<T> &vec) const;
        bool ort(const MathVector<T> &vec) const;
        bool collinearity(const MathVector<T> &vec) const;


        MathVector<T> addTo(const MathVector<T> &vec);
        MathVector<T> &operator+=(const MathVector<T> &vec);
        MathVector<T> subFrom(const MathVector<T> &vec);
        MathVector<T> &operator-=(const MathVector<T> &vec);
        MathVector<T> multiplyTo(T var);
        MathVector<T> &operator*=(T var);
        MathVector<T> devideFrom(T var);
        MathVector<T> &operator/=(T var);

        bool equals(const MathVector<T> &vec) const;
        bool operator==(const MathVector<T> &vec) const;

        bool notEquals(const MathVector<T> &vec) const;
        bool operator!=(const MathVector<T> &vec) const;

        MathVector<T> multiply(T *var);
        MathVector<T> operator*(T var) const;
        MathVector<T> devide(T *var);
        MathVector<T> operator/(T var) const;
        MathVector<T> add(const MathVector<T> &vec) const;
        MathVector<T> operator+(const MathVector<T> &vec) const;
        MathVector<T> sub(const MathVector<T> &vec) const;
        MathVector<T> operator-(const MathVector<T> &vec) const;
        MathVector<T> operator+() const;
        MathVector<T> operator-() const;

        Iterator<T> begin();
        Iterator<T> end();
        IteratorConst<T> begin() const;
        IteratorConst<T> end() const;
   private:
        std::shared_ptr<T> coords;
    };
}

#include "MathVector.hpp"

#endif //LAB_02_VECTOR_H
