#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string file_name;
    std::string needle;
    std::cout << "Введите имя файла: ";
    std::cin >> file_name;
    std::cout << "Введите подстроку: ";
    std::cin >> needle;

    std::ifstream in(file_name);
    std::ofstream out("task3_result.txt");
    if (!in || !out) {
        std::cout << "Ошибка открытия файлов\n";
        return 1;
    }

    std::string line;
    std::size_t line_no = 0;
    std::size_t hits = 0;
    while (std::getline(in, line)) {
        ++line_no;
        if (line.find(needle) != std::string::npos) {
            out << "Line " << line_no << ": " << line << '\n';
            ++hits;
        }
    }

    out << "Total hits: " << hits << '\n';
    std::cout << "Результат записан в task3_result.txt\n";
    return 0;
}

