#include <iostream>
#include <stdexcept>

template <class T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    std::size_t size_ = 0;

public:
    ~LinkedList() {
        while (head_) {
            Node* t = head_;
            head_ = head_->next;
            delete t;
        }
    }

    void push_back(const T& value) {
        Node* n = new Node{value, nullptr};
        if (!tail_) {
            head_ = tail_ = n;
        } else {
            tail_->next = n;
            tail_ = n;
        }
        ++size_;
    }

    bool erase_first(const T& value) {
        Node* prev = nullptr;
        Node* cur = head_;
        while (cur) {
            if (cur->value == value) {
                if (prev) prev->next = cur->next;
                else head_ = cur->next;
                if (cur == tail_) tail_ = prev;
                delete cur;
                --size_;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    std::size_t size() const { return size_; }

    void print() const {
        Node* cur = head_;
        while (cur) {
            std::cout << cur->value << ' ';
            cur = cur->next;
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.print();
    list.erase_first(20);
    list.print();
    std::cout << "size=" << list.size() << '\n';
    return 0;
}

