#include <iostream>

struct Node {
    int d{};
    Node* next{};
};

Node* first(int d) {
    Node* p = new Node;
    p->d = d;
    p->next = nullptr;
    return p;
}

void add(Node*& end, int d) {
    Node* p = new Node{d, nullptr};
    end->next = p;
    end = p;
}

Node* find(Node* beg, int key) {
    while (beg) {
        if (beg->d == key) return beg;
        beg = beg->next;
    }
    return nullptr;
}

bool remove(Node*& beg, int key) {
    if (!beg) return false;
    if (beg->d == key) {
        Node* t = beg;
        beg = beg->next;
        delete t;
        return true;
    }
    Node* prev = beg;
    Node* cur = beg->next;
    while (cur) {
        if (cur->d == key) {
            prev->next = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void print(Node* beg) {
    while (beg) {
        std::cout << beg->d << ' ';
        beg = beg->next;
    }
    std::cout << '\n';
}

int main() {
    Node* beg = first(1);
    Node* end = beg;
    for (int i = 2; i <= 5; ++i) add(end, i);
    print(beg);
    remove(beg, 5);
    print(beg);
    remove(beg, 1);
    print(beg);
    while (beg) {
        Node* t = beg;
        beg = beg->next;
        delete t;
    }
    return 0;
}

