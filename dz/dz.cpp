#include <iostream>
#include <Windows.h>

int manager_stavka[4]{ 0,0,0,0 };
int manager_man[4]{ 0,0,0,0 };
int lucsh = 0;

int manager(int col, int man) {
    
    for (size_t i = 0; i < 4; i++)
    {
        if (manager_stavka[i] = 0) {
            if (col < 500) {
                manager_stavka[i] = 200 + col / 100 * 3 + 200;
                manager_man[i] = man;
                if (col > lucsh) {
                    lucsh = i;
                    manager_stavka[3] = 200 + col / 100 * 8 + 200;
                }
            }
            else if (1000 > col > 500) {
                manager_stavka[i] = 200 + col / 100 * 5 + 200;
                manager_man[i] = man;
                if (col > lucsh) {
                    lucsh = i;
                    manager_stavka[3] = 200 + col / 100 * 8 + 200;
                }
            }
            else if (col > 1000) {
                manager_stavka[i] = 200 + col / 100 * 8;
                manager_man[i] = man;
                if (col > lucsh) {
                    lucsh = i;
                    manager_stavka[3] = 200 + col / 100 * 8 + 200;
                }
            }
        }
    }

    return 0;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    //задача 1
    const int size = 10;
    int arr[size];
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::cout << "Минимум: " << min << "\n";
    std::cout << "Максимум: " << max << "\n";
    //задача 2
    const int size1 = 10;
    int arr1[size1];
    int user ;
    std::cout << "введите число: ";
    std::cin >> user;

    for (int i = 0; i < size;i++) {
        arr1[i] = rand() % 100 + 1;
    }
    int sum = 0;

    for (int i = 0; i < size1; i++) {
        if (arr1[i] < user) {
            sum += arr1[i];
        }
    }
    std::cout << "Сумма чисел меньше ввода пользователя: " << sum;


    //задача 3
    const int god = 12;
    int doxod , min , max, max_mesyac, min_mesyac;
    int max_month = 0, int min_month = 0;
    int spisok[god]{};
    std::cout << "Введите весь доход за месяц: ";
    std::cin >> doxod;
    std::cout << "Введите от какого месяца хотите посчитать доход: ";
    std::cin >> min;
    std::cout << "Введите до какого месяца хотите посчитать доход: ";
    std::cin >> max;
    for (int i = 0; i < god; i++)
    {
        spisok[i] = rand() % doxod + 1;
        doxod -= spisok[i];
    }

    for (int i = min; i < max; i++) {
        if (spisok[i] <= min_month) {
            min_month = spisok[i];
            min_mesyac = i;
        }
    }
    for (int i = min; i < max; i++) {
        if (spisok[i] >= max_month) {
            max_month = spisok[i];
            max_mesyac = i;
        }
    }
    std::cout << "\nМаксимальный месяц: " << max_mesyac << " Доход: " << max_month << "\n"
        << "Минимальный месяц: " << min_mesyac << "Доход: " << min_month << "\n";


    int num1 = 0;

    std::cout << "\nМенеджер номер Один: ";
    std::cin >> num1;
    manager(num1, 1);
    std::cout << "\nМенеджер номер Два: ";
    std::cin >> num1;
    manager(num1, 2);
    std::cout << "\nМенеджер номер Три: ";
    std::cin >> num1;
    manager(num1, 3);

    std::cout << "\nЛучший менеджер номер: " << lucsh + 1 << " Зарплата: " << manager_stavka[lucsh];
    return 0;
}