#include "sort_utils.h"

int main() {
    std::vector<int> arr = {30, 12, 99, 41, 5, 88, 72, 15, 64, 9};
    int n1 = 2, n2 = 7;
    print_array(arr, "До сортировки от N1 до N2");
    if (normalize_range(arr.size(), n1, n2)) {
        std::sort(arr.begin() + n1, arr.begin() + n2 + 1);
    }
    print_array(arr, "После сортировки по возрастанию");
    return 0;
}

