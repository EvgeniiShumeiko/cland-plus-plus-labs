#include <cstring>
#include <iostream>

class DynamicStroka {
private:
    char* data_;
    std::size_t size_;

public:
    DynamicStroka() : data_(new char[1]{'\0'}), size_(1) {}

    explicit DynamicStroka(const char* s) {
        if (!s) {
            data_ = new char[1]{'\0'};
            size_ = 1;
            return;
        }
        size_ = std::strlen(s) + 1;
        data_ = new char[size_];
        std::memcpy(data_, s, size_);
    }

    DynamicStroka(const DynamicStroka& other) : data_(new char[other.size_]), size_(other.size_) {
        std::memcpy(data_, other.data_, size_);
    }

    DynamicStroka& operator=(const DynamicStroka& other) {
        if (this != &other) {
            char* tmp = new char[other.size_];
            std::memcpy(tmp, other.data_, other.size_);
            delete[] data_;
            data_ = tmp;
            size_ = other.size_;
        }
        return *this;
    }

    ~DynamicStroka() {
        delete[] data_;
    }

    void print() const { std::cout << data_; }
};

int main() {
    DynamicStroka s1("dynamic");
    DynamicStroka s2 = s1;
    DynamicStroka s3("initial");
    s3 = s1;
    s1.print(); std::cout << '\n';
    s2.print(); std::cout << '\n';
    s3.print(); std::cout << '\n';
    return 0;
}

