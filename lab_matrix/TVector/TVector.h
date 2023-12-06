#include <iostream>
const int MAX_VECTOR_SIZE = 100000000;

template<typename T>
class TVector {
protected:
    int _shift;
    size_t _size;
    T* pMem;
public:
    TVector(size_t sz = 1, int shift = 0) : _size(sz), _shift(shift) {
        if (sz == 0)
            throw std::length_error("Vector size should be greater than zero");
        if (sz > MAX_VECTOR_SIZE)
            throw std::length_error("Vector size cannot be greater than MAX_VECTOR_SIZE = ", MAX_VECTOR_SIZE);
        pMem = new T[sz]();
    }

    TVector(T* data, size_t sz, int shift) : _size(sz), _shift(shift) {
        // ��� ���� ������ ����� ����������
        assert(data != nullptr && "TVector constructor requires non-nullptr argument.");
        pMem = new T[sz];
        // ��� �������� ����� ������������ std-������� � ��������, ��� �� ������ ��� ��� ��� �����������!
        std::copy(data, data + sz, pMem);
    }

    TVector(const TVector& v) {
        _size = v._size;
        _shift = v._shift;
        pMem = v.pMem;
    }

    ~TVector() {
        delete[] pMem;
        pMem = nullptr;
    }

    T& operator[](size_t ind) {
        if (ind < 0 || ind > MAX_VECTOR_SIZE) {
            throw std::logic_error("The index cannot have this value.");
        }
        return this->pMem[ind - _shift];
    }

    bool operator==(const TVector& v)const noexcept {
        if (_size != v._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] == v[i];
        }
    }
    bool operator!=(const TVector& v) const noexcept {
        return !(*this == v);
    }

    size_t size() const noexcept {
        return _size;
    }

    TVector operator+(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] + val;
        }
    }
    TVector operator-(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] - val;
        }
    }
    TVector operator*(T val) {
        for (auto i = 0; i < _size; i++) {
            pMem[i] = pMem[i] * val;
        }
    }

    TVector operator+(const TVector& v) {
        if (_size != v._size) {
            throw std::length_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] = res[i] + v[i];
        }
    }
    TVector operator-(const TVector& v) {
        if (_size != v._size) {
            throw std::length_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] = res[i] - v[i];
        }
    }

    /*������������ noexcept
    ���������, ����� �� ������� ������������ ����������.*/

    //������������ ��� ��������, ����� �� ������� ������������ ����������. ��������, noexcept(noexcept(x.swap(y))) ���������� swap,
    //����������� �� ��� ��� � ����������� �� ���������� noexcept(x.swap(y)); 
    //�.�.����� �� swap ������������� ��� ���, ������� �� ����, x.swap(y) ���� �� �� ��������� ��� ���.

    T operator*(const TVector& v) noexcept(noexcept(T()))
    {
        T tmp;
        for (auto i = 0; i < _size; i++) {
            tmp = tmp + (*this)[i] * v[i];
        }
        return tmp;
    }

    friend void swap(TVector& lhs, TVector& rhs) noexcept;
    friend std::istream& operator>>(std::istream& istr, TVector& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TVector& v);
};

template <class T>
void swap(TVector<T>& lhs, TVector<T>& rhs) noexcept {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
}

template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& v) {
    for (size_t i = 0; i < v.sz; i++)
        istr >> v.pMem[i];
    return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v) {
    for (size_t i = 0; i < v.sz; i++)
        ostr << v.pMem[i] << ' ';
    return ostr;
}