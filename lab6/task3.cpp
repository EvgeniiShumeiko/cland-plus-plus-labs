#include <iostream>

class StrokaManual {
private:
    char str_[256];

    static int len(const char* s) {
        int n = 0;
        while (s && s[n] != '\0') ++n;
        return n;
    }
    static void copy(char* dst, const char* src) {
        while (src && *src) *dst++ = *src++;
        *dst = '\0';
    }
    static int cmp(const char* a, const char* b) {
        while (*a && *b && *a == *b) { ++a; ++b; }
        return static_cast<unsigned char>(*a) - static_cast<unsigned char>(*b);
    }
    static void cat(char* dst, const char* src) {
        while (*dst) ++dst;
        while (*src) *dst++ = *src++;
        *dst = '\0';
    }

public:
    StrokaManual() { str_[0] = '\0'; }
    explicit StrokaManual(const char* s) { copy(str_, s); }
    StrokaManual(const StrokaManual& other) { copy(str_, other.str_); }

    StrokaManual& operator=(const StrokaManual& other) {
        if (this != &other) copy(str_, other.str_);
        return *this;
    }
    StrokaManual operator+(const StrokaManual& other) const {
        StrokaManual r(*this);
        cat(r.str_, other.str_);
        return r;
    }
    bool operator==(const StrokaManual& other) const { return cmp(str_, other.str_) == 0; }
    int dlina() const { return len(str_); }
    void vyvod() const { std::cout << str_; }
};

int main() {
    StrokaManual a("manual_");
    StrokaManual b("version");
    StrokaManual c = a + b;
    std::cout << "c="; c.vyvod(); std::cout << '\n';
    std::cout << "len(c)=" << c.dlina() << '\n';
    std::cout << "a==b ? " << (a == b ? "true" : "false") << '\n';
    return 0;
}

