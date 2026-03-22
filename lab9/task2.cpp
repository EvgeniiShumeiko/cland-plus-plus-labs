#include <cstring>
#include <iostream>

template <class T>
T getmax(T a, T b) {
    return a > b ? a : b;
}

template <class T>
T getmax(T arr[], std::size_t size) {
    T m = arr[0];
    for (std::size_t i = 1; i < size; ++i) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

template <>
const char* getmax<const char*>(const char* a, const char* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}

int main() {
    int i1 = 3, i2 = 5;
    int arr[] = {3, 9, 5, 8};
    const char* s1 = "строкаA";
    const char* s2 = "строкаZ";

    std::cout << "max(int,int)=" << getmax(i1, i2) << '\n';
    std::cout << "max(array)=" << getmax(arr, sizeof(arr) / sizeof(arr[0])) << '\n';
    std::cout << "max(cstr,cstr)=" << getmax(s1, s2) << '\n';
    return 0;
}

