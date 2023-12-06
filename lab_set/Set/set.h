// Copyright 2023 (c) Dudchenko Olesya Victorovna

#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "../bitField/bit_field.h"

class TSet {
private:
    size_t maxPower;                       // ������������ �������� ���������
    TBitField bitField;                    // ������� ���� ��� �������� ���������
public:
    TSet(int mp) : bitField(mp), maxPower(mp) {}
    TSet(const TSet& s) : bitField(s.bitField), maxPower(s.maxPower) {}
    TSet(const TBitField& bf) : bitField(bf), maxPower(bf.size()) {}                  // �������������� ���� � �������� ����

    size_t GetMaxPower() const noexcept { return maxPower; }

    void InsElem(size_t Elem);            // �������� ������� � ���������
    void DelElem(size_t Elem);            // ������� ������� �� ���������
    bool IsMember(size_t Elem) const;     // ��������� ������� �������� � ���������

    TSet operator+ (const int Elem);       // ����������� � ���������
    TSet operator- (const int Elem);       // �������� � ���������
    TSet operator+ (const TSet& s);        // �����������
    TSet operator* (const TSet& s);        // �����������
    TSet operator~ ();                     // ����������

    bool operator== (const TSet& s) const;
    bool operator!= (const TSet& s) const;
    TSet& operator=(const TSet& s);

    friend std::istream& operator>>(std::istream& in, TSet& bf);
    friend std::ostream& operator<<(std::ostream& out, const TSet& bf);
};

#endif  // INCLUDE_SET_H_