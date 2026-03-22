#include <iostream>
#include "Stroka.h"

int main() {
    Stroka user;
    std::cout << "Введите строку: ";
    user.vvod();
    std::cout << "Вы ввели: ";
    user.vyvod();
    std::cout << "\nДлина: " << user.dlina() << '\n';
    return 0;
}

