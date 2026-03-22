#include <fstream>
#include <iostream>

int main() {
    std::fstream fs("stream_state.txt", std::ios::in | std::ios::out | std::ios::trunc);
    fs << "123 abc";
    fs.seekg(0);

    int x = 0;
    std::string bad;
    fs >> x;
    fs >> bad;

    std::cout << "good()=" << fs.good() << ", eof()=" << fs.eof() << '\n';

    int impossible = 0;
    fs >> impossible;
    std::cout << "После ошибочного чтения: fail()=" << fs.fail() << '\n';
    fs.clear();
    std::cout << "После clear(): fail()=" << fs.fail() << '\n';
    return 0;
}

