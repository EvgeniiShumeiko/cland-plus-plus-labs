#include <iostream>
#include "str_utils.h"

int main() {
    char lines[4][64] = {"alpha", "beta", "gamma", "delta"};

    for (int i = 0; i < 4; ++i) {
        std::cout << "lines[" << i << "]=" << lines[i] << ", len=" << dlina1(lines[i]) << '\n';
    }

    std::cout << "Сравнение lines[0] и lines[1]: " << sravn(lines[0], lines[1]) << '\n';
    konkat(lines[0], "_suffix");
    std::cout << "После конкатенации lines[0]: " << lines[0] << '\n';
    return 0;
}

