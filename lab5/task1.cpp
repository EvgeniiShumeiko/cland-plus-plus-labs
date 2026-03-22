#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Введите имя файла для просмотра: ";
    std::cin >> name;

    std::ifstream in(name);
    if (!in) {
        std::cout << "Файл не открыт: " << name << '\n';
        return 1;
    }

    std::cout << "--- Содержимое файла ---\n";
    std::string line;
    while (std::getline(in, line)) {
        std::cout << line << '\n';
    }
    return 0;
}

