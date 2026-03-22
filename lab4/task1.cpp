#include <cstring>
#include <iostream>

int main() {
    char a[64] = "qwerty";
    char b[64] = "123456";
    char c[128] = {};

    std::cout << "strlen(a)=" << std::strlen(a) << ", strlen(b)=" << std::strlen(b) << '\n';
    std::strcpy(c, a);
    std::cout << "strcpy(c, a): " << c << '\n';
    std::strcat(c, b);
    std::cout << "strcat(c, b): " << c << '\n';
    std::cout << "strcmp(a, b): " << std::strcmp(a, b) << '\n';
    return 0;
}

