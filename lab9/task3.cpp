#include <iostream>
#include <stack>
#include <vector>

template <class T>
class TStack {
private:
    std::vector<T> data_;

public:
    void push(const T& v) { data_.push_back(v); }
    T pop() {
        T v = data_.back();
        data_.pop_back();
        return v;
    }
    bool empty() const { return data_.empty(); }
    T top() const { return data_.back(); }
};

// Проверка возможности перестановки вагонов через тупик (stack permutation)
bool can_reorder(const std::vector<int>& target) {
    TStack<int> st;
    int need_idx = 0;
    int n = static_cast<int>(target.size());

    for (int incoming = 1; incoming <= n; ++incoming) {
        st.push(incoming);
        while (!st.empty() && need_idx < n && st.top() == target[need_idx]) {
            st.pop();
            ++need_idx;
        }
    }
    return need_idx == n;
}

int main() {
    std::vector<int> a = {5, 3, 1, 2, 4};
    std::vector<int> b = {4, 3, 5, 1, 2};
    std::cout << "Перестановка A: " << (can_reorder(a) ? "возможна" : "невозможна") << '\n';
    std::cout << "Перестановка B: " << (can_reorder(b) ? "возможна" : "невозможна") << '\n';
    return 0;
}

