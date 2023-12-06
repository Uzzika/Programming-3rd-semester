// Copyright 2023 (c) Dudchenko Olesya Victorovna

#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "../bitField/bit_field.h"

class TSet {
private:
    size_t maxPower;                       // максимальная мощность множества
    TBitField bitField;                    // битовое поле для хранения множества
public:
    TSet(int mp) : bitField(mp), maxPower(mp) {}
    TSet(const TSet& s) : bitField(s.bitField), maxPower(s.maxPower) {}
    TSet(const TBitField& bf) : bitField(bf), maxPower(bf.size()) {}                  // преобразование типа к битовому полю

    size_t GetMaxPower() const noexcept { return maxPower; }

    void InsElem(size_t Elem);            // включить элемент в множество
    void DelElem(size_t Elem);            // удалить элемент из множества
    bool IsMember(size_t Elem) const;     // проверить наличие элемента в множестве

    TSet operator+ (const int Elem);       // объединение с элементом
    TSet operator- (const int Elem);       // разность с элементом
    TSet operator+ (const TSet& s);        // объединение
    TSet operator* (const TSet& s);        // пересечение
    TSet operator~ ();                     // дополнение

    bool operator== (const TSet& s) const;
    bool operator!= (const TSet& s) const;
    TSet& operator=(const TSet& s);

    friend std::istream& operator>>(std::istream& in, TSet& bf);
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf);
};

#endif  // INCLUDE_SET_H_