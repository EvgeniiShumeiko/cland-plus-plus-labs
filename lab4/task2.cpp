#include <iostream>
#include "str_utils.h"

int main() {
    char str1[128] = "qwerty";
    char str2[128] = "1234567890";
    char tmp[128] = {};

    std::cout << "dlina1(str1)=" << dlina1(str1) << ", dlina1(str2)=" << dlina1(str2) << '\n';
    std::cout << "dlina2(str1)=" << dlina2(str1) << ", dlina2(str2)=" << dlina2(str2) << '\n';
    std::cout << "dlina3(str1)=" << dlina3(str1) << ", dlina3(str2)=" << dlina3(str2) << '\n';

    kopir(tmp, str1);
    std::cout << "После kopir(tmp, str1): " << tmp << '\n';

    std::cout << "sravn(str1, str2): " << sravn(str1, str2) << '\n';

    konkat(str1, str2);
    std::cout << "После konkat(str1, str2): " << str1 << '\n';
    return 0;
}

