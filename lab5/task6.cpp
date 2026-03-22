#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 5) {
        std::cout << "Использование: ./task6 <enc|dec> <input> <output> <key>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string input_name = argv[2];
    std::string output_name = argv[3];
    std::string key = argv[4];
    if (key.empty()) {
        std::cout << "Ключ не может быть пустым\n";
        return 1;
    }

    std::ifstream in(input_name, std::ios::binary);
    std::ofstream out(output_name, std::ios::binary);
    if (!in || !out) {
        std::cout << "Ошибка открытия файла\n";
        return 1;
    }

    // Для XOR режимы enc/dec идентичны, оставляем параметр для явного сценария.
    if (mode != "enc" && mode != "dec") {
        std::cout << "mode должен быть enc или dec\n";
        return 1;
    }

    char ch;
    std::size_t i = 0;
    while (in.get(ch)) {
        ch = static_cast<char>(ch ^ key[i % key.size()]);
        out.put(ch);
        ++i;
    }

    std::cout << "Готово: " << output_name << '\n';
    return 0;
}

