#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Введите имя файла: ";
    std::cin >> name;

    std::ifstream in(name, std::ios::binary);
    if (!in) {
        std::cout << "Файл не открыт\n";
        return 1;
    }

    std::size_t empty_count = 0;
    std::size_t non_empty_count = 0;
    char ch;
    while (in.get(ch)) {
        if (std::isspace(static_cast<unsigned char>(ch)) || std::iscntrl(static_cast<unsigned char>(ch))) {
            ++empty_count;
        } else {
            ++non_empty_count;
        }
    }

    std::cout << "Пустых/служебных символов: " << empty_count << '\n';
    std::cout << "Непустых символов: " << non_empty_count << '\n';
    return 0;
}

