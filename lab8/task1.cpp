#include <fstream>
#include <iostream>
#include <string>

struct Student {
    std::string name;
    int group{};

    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        return os << s.name << ' ' << s.group;
    }
    friend std::istream& operator>>(std::istream& is, Student& s) {
        return is >> s.name >> s.group;
    }
};

int main() {
    Student s1{"Ivanov", 101};
    {
        std::ofstream out("students.txt");
        out << s1 << '\n';
        out << Student{"Petrov", 102} << '\n';
    }
    std::ifstream in("students.txt");
    Student s;
    while (in >> s) {
        std::cout << "Прочитано: " << s << '\n';
    }
    return 0;
}

