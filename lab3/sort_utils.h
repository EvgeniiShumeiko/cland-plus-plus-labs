#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

inline void print_array(const std::vector<int>& arr, const std::string& label) {
    std::cout << label << ": ";
    for (int v : arr) {
        std::cout << v << ' ';
    }
    std::cout << '\n';
}

inline void min_max_sort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    std::size_t left = 0;
    std::size_t right = arr.size() - 1;
    while (left < right) {
        std::size_t min_idx = left;
        std::size_t max_idx = left;
        for (std::size_t i = left; i <= right; ++i) {
            if (arr[i] < arr[min_idx]) min_idx = i;
            if (arr[i] > arr[max_idx]) max_idx = i;
        }
        std::swap(arr[left], arr[min_idx]);
        if (max_idx == left) {
            max_idx = min_idx;
        }
        std::swap(arr[right], arr[max_idx]);
        ++left;
        if (right == 0) break;
        --right;
    }
}

inline void bubble_sort(std::vector<int>& arr) {
    for (std::size_t i = 0; i + 1 < arr.size(); ++i) {
        for (std::size_t j = 0; j + 1 < arr.size() - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

inline int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

inline void sort_even_asc_odd_desc(std::vector<int>& arr) {
    std::stable_sort(arr.begin(), arr.end(), [](int a, int b) {
        const bool a_even = (a % 2 == 0);
        const bool b_even = (b % 2 == 0);
        if (a_even != b_even) return a_even > b_even;
        if (a_even) return a < b;
        return a > b;
    });
}

inline bool normalize_range(std::size_t n, int& l, int& r) {
    if (n == 0) return false;
    if (l > r) std::swap(l, r);
    if (r < 0 || l >= static_cast<int>(n)) return false;
    l = std::max(0, l);
    r = std::min(static_cast<int>(n) - 1, r);
    return l <= r;
}

