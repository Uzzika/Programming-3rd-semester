#include "../TMatrix/TMatrix.h"

#include <iostream>
#include <Windows.h>

#define USE_MATRIX

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool flag = 1;
    int size1, size2;
    TMatrix<int> matr1(size1);
    TMatrix<int> matr2(size2);
    std::string title = ("---====����====---\n\n");
    const std::string menu = " 1.������ ������ �������;\n 2.������ ������ �������;\n 3.�������� ������� ������;\n 4.�������� ������� �� ������\n 5.�������� ������� �� ������\n 6.�������� ������ ������� �� ������\n 7.������� �������\n 8.�����\n";
    const std::string in = " ��� �����: ";
    while (flag)
    {
        std::cout << title;
        std::cout << menu;
        std::cout << in;
        int x;
        std::cin >> x;
        system("cls");
        switch (x)
        {
    //    case 1:
    //    {
    //        std::cout << "������� ������ �������: ";
    //        std::cin >> size1;
    //        std::cout << "������ ����: ";
    //        std::cin >> ts;
    //        A = ts;
    //        std::cout << A;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 2:
    //    {
    //        int power;
    //        std::cout << "������� �������� ��������� B: ";
    //        std::cin >> power;
    //        TSet ts(power);
    //        std::cout << "������ ����: ";
    //        std::cin >> ts;
    //        B = ts;
    //        std::cout << A;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 3:
    //    {
    //        TSet ts(A + B);
    //        std::cout << ts;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 4:
    //    {
    //        TSet ts(A * (~B));
    //        std::cout << ts;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 5:
    //    {
    //        TSet ts(A * B);
    //        std::cout << ts;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 6:
    //    {
    //        std::cout << "���������� ��������� �: " << ~A;
    //        std::cout << "���������� ��������� B: " << ~B;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 7:
    //    {
    //        int n;
    //        std::cout << "������� N: ";
    //        std::cin >> n;
    //        eratosthenes_alghoritm(n);
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 8:
    //    {
    //        flag = 0;
    //    }
    //    }
    }
}