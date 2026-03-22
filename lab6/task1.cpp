#include <iostream>
#include "Stroka.h"

int main() {
    Stroka s1("qwert");
    Stroka s2("asdfg");
    Stroka s3(s1);
    Stroka s4 = s1 + s2;

    std::cout << "s1="; s1.vyvod(); std::cout << '\n';
    std::cout << "s2="; s2.vyvod(); std::cout << '\n';
    std::cout << "s3(copy of s1)="; s3.vyvod(); std::cout << '\n';
    std::cout << "s4=s1+s2="; s4.vyvod(); std::cout << '\n';
    std::cout << "dlina(s4)=" << s4.dlina() << '\n';
    std::cout << "s1==s3 ? " << (s1 == s3 ? "true" : "false") << '\n';
    return 0;
}

