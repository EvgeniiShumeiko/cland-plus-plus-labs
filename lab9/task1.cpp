#include <iostream>
#include <vector>

template <class T>
void Sort(std::vector<T>& a) {
    for (std::size_t i = 0; i + 1 < a.size(); ++i) {
        for (std::size_t j = 0; j + 1 < a.size() - i; ++j) {
            if (a[j] > a[j + 1]) {
                T tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

struct Money {
    long dollars{};
    int cents{};
    bool operator>(const Money& rhs) const {
        if (dollars != rhs.dollars) return dollars > rhs.dollars;
        return cents > rhs.cents;
    }
};

std::ostream& operator<<(std::ostream& os, const Money& m) {
    return os << '$' << m.dollars << '.' << m.cents;
}

int main() {
    std::vector<int> a = {10, 20, 30, 11, 25, 32, 0};
    Sort(a);
    for (int v : a) std::cout << v << ' ';
    std::cout << '\n';

    std::vector<Money> m = {{19, 10}, {99, 99}, {99, 95}, {19, 95}};
    Sort(m);
    for (const auto& v : m) std::cout << v << ' ';
    std::cout << '\n';
    return 0;
}

