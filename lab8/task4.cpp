#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("random_access.txt");
    out << "line0\nline1\nline2\nline3\n";
    out.close();

    std::ifstream in("random_access.txt");
    in.seekg(6); // начало "line1"
    std::string line;
    std::getline(in, line);
    std::cout << "Считано через seekg: " << line << '\n';
    return 0;
}

