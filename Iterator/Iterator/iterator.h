#pragma once

#include <iostream>

template <class T> class TVector;
template <class T> std::ostream& operator<<(std::ostream& ostr, const TVector<T>& vec);


template<class T>
//итераторы ввода (input iterators),
class InIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    T* ptr;
    InIterator(T* p) : ptr(p) { }
public:
    InIterator(const InIterator& it) : ptr(it.ptr) { }

    bool operator ==(const InIterator& it) {
        return ptr == it.ptr;
    }
    bool operator!=(const InIterator& it) {
        return ptr != it.ptr;
    }
    T& operator*() {
        return *ptr;
    }
    InIterator& operator ++() {
        ++ptr;
        return *this;
    }
};

template<class T>
//итераторы вывода (output iterators)
class OutIterator : public std::iterator<std::output_iterator_tag, T> {
private:
    T* ptr;
    OutIterator(T* p) : ptr(p) { };
public:
    OutIterator(const OutIterator& it) : ptr(it.ptr) { };
    bool operator ==(const OutIterator& it) const {
        return ptr == it.ptr;
    }
    bool operator!=(const OutIterator& it) const {
        return ptr != it.ptr;
    }
    const T& operator*() const {
        return *ptr;
    }
    OutIterator& operator ++() const {
        ++ptr;
        return *this;
    }
    OutIterator operator++(int) {
        OutIterator copy{ *this };
        ++ptr;
        return copy;
    }
};

template<class T>
//однонаправленные итераторы (forward iterators)
class ForIterator : public std::iterator<std::forward_iterator_tag, T> {
private:
    T* ptr;
    ForIterator(T* p) : ptr(p) { };
public:
    ForIterator(const ForIterator& it) : ptr(it.ptr) { };
    bool operator ==(const ForIterator& it) const {
        return ptr == it.ptr;
    }
    bool operator!=(const ForIterator& it) const {
        return ptr != it.ptr;
    }
    ForIterator& operator ++() const {
        ++ptr;
        return *this;
    }
    ForIterator operator++(int) {
        ForIterator copy{ *this };
        ++ptr;
        return copy;
    }
    ForIterator& operator+(int a) {
        ptr += a;
        return *this;
    }

};

template<class T>
//двунаправленные итераторы (bidirectional iterators)
class BdIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    T* ptr;
    BdIterator(T* p) : ptr(p) {  };
public:
    BdIterator(const BdIterator& it) : ptr(it.ptr) {  };
    bool operator ==(const BdIterator& it) const {
        return ptr == it.ptr;
    }
    bool operator!=(const BdIterator& it) const {
        return ptr != it.ptr;
    }
    BdIterator& operator ++() const {
        ++ptr;
        return *this;
    }
    BdIterator operator++(int) {
        BdIterator copy{ *this };
        ++ptr;
        return copy;
    }
    BdIterator& operator+(int a) {
        ptr += a;
        return *this;
    }
    BdIterator& operator --() const {
        --ptr;
        return *this;
    }
    BdIterator operator--(int) {
        BdIterator copy{ *this };
        --ptr;
        return copy;
    }
    BdIterator& operator-(int a) {
        ptr -= a;
        return *this;
    }
};

template<class T>
//итераторы произвольного доступа (random access iterators).
class RaIterator : public std::iterator<std::random_access_iterator_tag, T> { };

template <class T>
class TVector {
private:
    T* pMem;
    size_t size;
    typedef InIterator<T> iterator;
    typedef InIterator<const T> const_iterator;
public:
    TVector(size_t _size) : size(_size) {
        pMem = new T[_size];
        for (int i = 0; i < size; i++) {
            pMem[i] = i + 1;
        }
    }
    TVector(const TVector& vec) : size(vec.size) {
        for (int i = 0; i < vec.size; i++) {
            pMem[i] = vec.pMem[i];
        }
    }
    ~TVector() {
        delete[] pMem;
        pMem = nullptr;
    }


    T* begin() {
        return &pMem[0];
    }
    T* end() {
        return (&pMem[size - 1]) + 1;
    }

    void TFill(T fill) {
        for (auto it = this->begin(); it != this->end(); ++it) {
            *it = fill;
        }
    }
    void TFill_n(T fill, int n) {
        if (n > 0 && n <= size) {
            auto itend = this->begin() + n;
            for (auto it = this->begin(); it != itend; ++it) {
                *it = fill;
            }
        }
    }
    void TReplace(T replaced, T to_replace) {
        for (auto it = this->begin(); it != this->end(); ++it) {
            if (*it == replaced)
                *it = to_replace;
        }
    }
    void TReplace_n(T replaced, T to_replace, int n) {
        if (n > 0 && n <= size) {
            auto itend = this->begin() + n;
            for (auto it = this->begin(); it != itend; ++it) {
                if (*it == replaced)
                    *it = to_replace;
            }
        }
    }


    friend std::ostream& operator<< <T>(std::ostream& ostr, const  TVector<T>& vec);
};
template <class T>
std::ostream& operator<<(std::ostream& ostr, const  TVector<T>& vec) {
    for (int i = 0; i < vec.size; i++) {
        ostr << vec[i] << " ";
    }
    return ostr;
}