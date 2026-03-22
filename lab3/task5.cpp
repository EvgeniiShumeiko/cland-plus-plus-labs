#include "sort_utils.h"

int main() {
    std::vector<int> arr = {30, 12, 99, 41, 5, 88, 72, 15, 64, 9};
    int n1 = 1, n2 = 6;
    print_array(arr, "До сортировки от N1 до N2");
    if (normalize_range(arr.size(), n1, n2)) {
        std::sort(arr.begin() + n1, arr.begin() + n2 + 1, std::greater<int>());
    }
    print_array(arr, "После сортировки по убыванию");
    return 0;
}

