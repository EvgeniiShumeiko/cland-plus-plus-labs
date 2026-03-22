#include "Stroka.h"

#include <cstring>

Stroka::Stroka() {
    str_[0] = '\0';
}

Stroka::Stroka(const char* s) {
    if (!s) {
        str_[0] = '\0';
        return;
    }
    std::strncpy(str_, s, sizeof(str_) - 1);
    str_[sizeof(str_) - 1] = '\0';
}

Stroka::Stroka(const Stroka& other) {
    std::strcpy(str_, other.str_);
}

Stroka& Stroka::operator=(const Stroka& other) {
    if (this != &other) {
        std::strcpy(str_, other.str_);
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& other) const {
    Stroka result(*this);
    std::strncat(result.str_, other.str_, sizeof(result.str_) - std::strlen(result.str_) - 1);
    return result;
}

bool Stroka::operator==(const Stroka& other) const {
    return std::strcmp(str_, other.str_) == 0;
}

int Stroka::dlina() const {
    return static_cast<int>(std::strlen(str_));
}

void Stroka::vvod() {
    std::cin.getline(str_, sizeof(str_));
}

void Stroka::vyvod() const {
    std::cout << str_;
}

