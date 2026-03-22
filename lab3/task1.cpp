#include "sort_utils.h"

int main() {
    std::vector<int> mas = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    print_array(mas, "До mini-max");
    min_max_sort(mas);
    print_array(mas, "После mini-max");
    return 0;
}

