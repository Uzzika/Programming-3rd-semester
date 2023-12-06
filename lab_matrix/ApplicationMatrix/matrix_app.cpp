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
    std::string title = ("---====МЕНЮ====---\n\n");
    const std::string menu = " 1.Задать первую матрицу;\n 2.Задать вторую матрицу;\n 3.Сравнить размеры матриц;\n 4.Умножить матрицу на скаляр\n 5.Умножить матрицу на вектор\n 6.Умножить первую матрицу на вторую\n 7.Вывести матрицы\n 8.Выход\n";
    const std::string in = " Ваш выбор: ";
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
    //        std::cout << "Введите размер матрицы: ";
    //        std::cin >> size1;
    //        std::cout << "Задать поле: ";
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
    //        std::cout << "Введите мощность множества B: ";
    //        std::cin >> power;
    //        TSet ts(power);
    //        std::cout << "Задать поле: ";
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
    //        std::cout << "Дополнение множества А: " << ~A;
    //        std::cout << "Дополнение множества B: " << ~B;
    //        system("pause");
    //        system("cls");
    //        break;
    //    }
    //    case 7:
    //    {
    //        int n;
    //        std::cout << "Введите N: ";
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