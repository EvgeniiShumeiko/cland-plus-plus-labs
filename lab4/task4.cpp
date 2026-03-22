#include <cstdlib>
#include <cstring>
#include <iostream>

int main() {
    constexpr std::size_t count = 100;
    char* from_malloc = static_cast<char*>(std::malloc(count));
    char* from_calloc = static_cast<char*>(std::calloc(count, sizeof(char)));

    if (!from_malloc || !from_calloc) {
        std::cout << "Ошибка выделения памяти\n";
        std::free(from_malloc);
        std::free(from_calloc);
        return 1;
    }

    std::strcpy(from_malloc, "malloc не инициализирует память");
    std::strcpy(from_calloc, "calloc обнуляет выделенную память");

    std::cout << from_malloc << '\n' << from_calloc << '\n';
    std::cout << "Различие: calloc(size, n) = malloc(size*n) + заполнение нулями.\n";

    std::free(from_malloc);
    std::free(from_calloc);
    return 0;
}

