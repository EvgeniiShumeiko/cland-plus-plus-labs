#include <cstdlib>
#include <iostream>
#include "str_utils.h"

int main() {
    char* str1 = static_cast<char*>(std::malloc(100));
    char* str2 = static_cast<char*>(std::malloc(100));
    char* buf = static_cast<char*>(std::malloc(200));
    if (!str1 || !str2 || !buf) {
        std::cout << "Ошибка выделения памяти\n";
        std::free(str1); std::free(str2); std::free(buf);
        return 1;
    }

    kopir(str1, "dynamic_string_one");
    kopir(str2, "_two");
    kopir(buf, str1);
    konkat(buf, str2);

    std::cout << "str1=" << str1 << ", len=" << dlina2(str1) << '\n';
    std::cout << "str2=" << str2 << ", len=" << dlina2(str2) << '\n';
    std::cout << "concat=" << buf << '\n';
    std::cout << "sravn(str1, str2)=" << sravn(str1, str2) << '\n';

    std::free(str1);
    std::free(str2);
    std::free(buf);
    return 0;
}

