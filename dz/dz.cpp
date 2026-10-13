#include <iostream>
#include <Windows.h>

int manager_stavka[3] = { 0,0,0 };
int manager_man[3] = { 0,0,0 };
int lucsh = 0;
int lucsh_col = -1;

void manager(int col, int man) {
    for (int i = 0; i < 3; i++) {
        if (manager_stavka[i] == 0) {
            if (col < 500)
                manager_stavka[i] = 200 + col / 100 * 3 + 200;
            else if (col <= 1000)
                manager_stavka[i] = 200 + col / 100 * 5 + 200;
            else
                manager_stavka[i] = 200 + col / 100 * 8;

            manager_man[i] = man;

            if (col > lucsh_col) {
                lucsh_col = col;
                lucsh = i;
            }
            break;
        }
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    // задача 1
    const int size = 10;
    int arr[size];
    std::cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    std::cout << "\nМинимум: " << min << "\n";
    std::cout << "Максимум: " << max << "\n";

    // задача 2
    const int size1 = 10;
    int arr1[size1];
    int user;
    std::cout << "введите число: ";
    std::cin >> user;
    for (int i = 0; i < size1; i++)
        arr1[i] = rand() % 100 + 1;
    int sum = 0;
    for (int i = 0; i < size1; i++)
        if (arr1[i] < user) sum += arr1[i];
    std::cout << "Сумма чисел меньше ввода пользователя: " << sum << "\n";

    // задача 3
    const int god = 12;
    int doxod = 0, min_dox = 0, max_dox = 0;
    int spisok[god]{};
    std::cout << "Введите весь доход за год: ";
    std::cin >> doxod;
    std::cout << "Введите от какого месяца (1-12): ";
    std::cin >> min_dox;
    std::cout << "Введите до какого месяца (1-12): ";
    std::cin >> max_dox;

    for (int i = 0; i < god - 1; i++) {
        spisok[i] = (doxod > 0) ? rand() % doxod + 1 : 0;
        doxod -= spisok[i];
    }
    spisok[god - 1] = doxod; // остаток в последний месяц

    int min_month = spisok[min_dox - 1], min_mesyac = min_dox;
    int max_month = spisok[min_dox - 1], max_mesyac = min_dox;
    for (int i = min_dox; i <= max_dox; i++) {
        int v = spisok[i - 1];
        if (v < min_month) { min_month = v; min_mesyac = i; }
        if (v > max_month) { max_month = v; max_mesyac = i; }
    }
    std::cout << "Максимальный месяц: " << max_mesyac << " Доход: " << max_month << "\n"
        << "Минимальный месяц: " << min_mesyac << " Доход: " << min_month << "\n";

    // менеджеры
    int num1 = 0;
    for (int m = 1; m <= 3; m++) {
        std::cout << "\nПродажи менеджера номер " << m << ": ";
        std::cin >> num1;
        manager(num1, m);
    }
    std::cout << "\nЛучший менеджер номер: " << manager_man[lucsh]
        << " Зарплата: " << manager_stavka[lucsh] << "\n";
    return 0;
}