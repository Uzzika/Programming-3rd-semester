//Copyright (c) 2023 Dudchenko Olesya

#include "../TVector/TVector.h"

#define INCLUDE_MATRIX_H_
#include <iostream>
const int MAX_MATRIX_SIZE = 10000;

template <class T>
class TMatrix : private TVector<TVector<T>> {
    using TVector<TVector<T>>::pMem;
    using TVector<TVector<T>>::sz;
public:
    TMatrix(size_t s = 1) : TVector<TVector<T>>(s)
    {
        if (sz <= 0 || sz > MAX_MATRIX_SIZE) { throw std::logic_error("Out of range."); }
        for (size_t i = 0; i < sz; i++) {
            pMem[i] = TVector<T>(sz);
        }
    }
    // почему можно сделать так? объяснить.
    using TVector<TVector<T>>::operator[];
    using TVector<TVector<T>>::size;

    // сравнение
    bool operator==(const TMatrix& m) const noexcept
    {
        if (sz != m.sz) { throw std::logic_error("Sizes are not equal."); }
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                if (pMem[i][j] != m.pMem[i][j]) { return 0; }
            }
        }
        return 1;
    }
    bool operator!=(const TMatrix& m) const noexcept { return !(*this == m); }

    // матрично-скалярные операции
    TMatrix operator*(const T& val)
    {
        TMatrix M(*this);
        for (int i = 0; i < sz; i++) {
            pMem[i] = pMem[i] * val;
        }
        return M;
    }

    // матрично-векторные операции
    TVector<T> operator*(const TVector<T>& v)
    {
        if (sz != v.sz) { throw std::logic_error("Sizes are not equal"); }
        TVector<T> V(sz);
        for (size_t i = 0; i < sz; i++) {
            V[i] = pMem[i] * v.pMem[i];
        }
    }

    // матрично-матричные операции
    TMatrix operator+(const TMatrix& m)
    {
        if (sz != m.sz) { throw std::logic_error("Sizes are not equal."); }
        return TVector<TVector>operator+(m);
    }

    TMatrix operator-(const TMatrix& m)
    {
        if (sz != m.sz) { throw std::logic_error("Sizes are not equal."); }
        return TVector<TVector>operator-(m);
    }

    TMatrix operator*(const TMatrix& m)
    {
        if (sz != m.sz) { throw std::logic_error("Sizes are not equal."); }
        TMatrix<T> matrix(sz);
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                T s = 0;
                for (size_t k = 0; k < sz; k++) {
                    s += pMem[i][k] * m[k][j];
                }
                matrix[i][j] = s;
            }
        }
        return matrix;
    }

    // ввод/вывод
    friend std::istream& operator>>(std::istream& istr, TMatrix& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TMatrix& v);
};

template <class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& v) {
    for (int i = 0; i < v.sz; i++) {
        for (int j = 0; j < v.sz; j++) {
            istr >> v[i][j];
        }
    }
    return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& v) {
    for (int i = 0; i < v.sz; i++) {
        for (int j = 0; j < v.sz; j++) {
            ostr << v[i][j];
        }
    }
    return ostr;
}