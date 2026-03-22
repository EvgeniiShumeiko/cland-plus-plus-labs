#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream in("pages_input.txt");
    std::ofstream out("pages_output.txt");
    if (!in || !out) {
        std::cout << "Нужен файл pages_input.txt\n";
        return 1;
    }

    std::string page;
    while (std::getline(in, page, '\f')) {
        std::istringstream iss(page);
        std::string page_number_line;
        if (!std::getline(iss, page_number_line)) continue;

        // Убираем пробелы и дефис: " - 34 -" -> "34"
        std::string page_number;
        for (char c : page_number_line) {
            if (std::isdigit(static_cast<unsigned char>(c))) page_number.push_back(c);
        }

        std::string rest((std::istreambuf_iterator<char>(iss)), std::istreambuf_iterator<char>());
        out << rest;
        if (!rest.empty() && rest.back() != '\n') out << '\n';
        out << page_number << '\n' << '\f';
    }

    std::cout << "Готово: pages_output.txt\n";
    return 0;
}

