#include "sort_utils.h"

int main() {
    std::vector<int> arr = {7, 2, 9, 4, 3, 8, 5, 6, 1, 0, 11, 14, 13};
    print_array(arr, "До сортировки");
    sort_even_asc_odd_desc(arr);
    print_array(arr, "После: четные по возр., нечетные по убыв.");
    return 0;
}

