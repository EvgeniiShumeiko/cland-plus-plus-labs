#pragma once

#include <iostream>

class Stroka {
private:
    char str_[256];

public:
    Stroka();
    explicit Stroka(const char* s);
    Stroka(const Stroka& other);

    Stroka& operator=(const Stroka& other);
    Stroka operator+(const Stroka& other) const;
    bool operator==(const Stroka& other) const;

    int dlina() const;
    void vvod();
    void vyvod() const;
};

