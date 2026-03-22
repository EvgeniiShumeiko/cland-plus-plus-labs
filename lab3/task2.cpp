#include "sort_utils.h"

int main() {
    std::vector<int> src = {17, 4, 9, -3, 8, 2, 10, 1};
    auto b = src;
    auto q = src;

    bubble_sort(b);
    quick_sort(q, 0, static_cast<int>(q.size()) - 1);

    print_array(src, "Исходный массив");
    print_array(b, "Пузырьковая сортировка");
    print_array(q, "Быстрая сортировка");

    std::cout << "Для 2D-массивов сортировки применимы к каждой строке/столбцу\n";
    std::cout << "или ко всему массиву после линейного представления.\n";
    return 0;
}

