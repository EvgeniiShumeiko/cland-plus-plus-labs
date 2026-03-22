#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Bus {
    int number{};
    std::string driver;
    int route{};
};

void print_by_route(const std::vector<Bus>& buses, int route) {
    std::cout << "Автобусы маршрута " << route << ":\n";
    for (const auto& b : buses) {
        if (b.route == route) {
            std::cout << "  #" << b.number << ", " << b.driver << '\n';
        }
    }
}

int main() {
    std::vector<Bus> park = {
        {101, "Иванов И.И.", 5},
        {102, "Петров П.П.", 7},
        {103, "Сидоров С.С.", 5},
        {104, "Кузнецов К.К.", 10}
    };

    std::cout << "Начальные данные автобусов:\n";
    for (const auto& b : park) {
        std::cout << "#" << b.number << " | " << b.driver << " | route=" << b.route << '\n';
    }

    int removed_number = 102;
    park.erase(
        std::remove_if(park.begin(), park.end(), [removed_number](const Bus& b) {
            return b.number == removed_number;
        }),
        park.end()
    );

    std::cout << "\nПосле удаления автобуса #" << removed_number << ":\n";
    for (const auto& b : park) {
        std::cout << "#" << b.number << " | " << b.driver << " | route=" << b.route << '\n';
    }

    print_by_route(park, 5);
    return 0;
}

