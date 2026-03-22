#include "sort_utils.h"

int main() {
    std::vector<int> arr = {19, -3, 22, 7, 0, -11, 4, 9, 15};
    int n1 = -2, n2 = 100;
    print_array(arr, "Исходный массив");
    if (normalize_range(arr.size(), n1, n2)) {
        std::cout << "Нормализованный интервал: [" << n1 << ", " << n2 << "]\n";
        std::sort(arr.begin() + n1, arr.begin() + n2 + 1);
    }
    print_array(arr, "После обработки интервала");
    return 0;
}

