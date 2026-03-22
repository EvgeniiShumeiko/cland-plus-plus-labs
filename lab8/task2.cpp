#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("stream_sample.txt");
    if (!in) {
        std::cout << "Нет файла stream_sample.txt\n";
        return 1;
    }

    std::size_t lines = 0;
    std::size_t words = 0;
    std::string line;
    while (std::getline(in, line)) {
        ++lines;
        std::size_t i = 0;
        while (i < line.size()) {
            while (i < line.size() && std::isspace(static_cast<unsigned char>(line[i]))) ++i;
            if (i < line.size()) ++words;
            while (i < line.size() && !std::isspace(static_cast<unsigned char>(line[i]))) ++i;
        }
    }

    std::ofstream out("stream_stats.txt");
    out << "lines=" << lines << '\n' << "words=" << words << '\n';
    std::cout << "Статистика записана в stream_stats.txt\n";
    return 0;
}

