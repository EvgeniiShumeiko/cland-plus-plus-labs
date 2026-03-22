#include <iostream>
using namespace std;

int main(void) {
    int a = 2, b = 5;

    // внес изменения в контракт функции, чтобы она возвращала новые значения
    pair<int, int> obmen1(int, int);
    void obmen2(int*, int*);
    void obmen3(int&, int&);

    cout << "до обмена: a = " << a << ", b = " << b << endl;

    // первый способ обмена
    auto [na, nb] = obmen1(a, b);
    a = na;
    b = nb;
    cout << "после обмена 1: a = " << a << ", b = " << b << endl;

    // второй способ обмена
    obmen2(&a, &b);
    cout << "после обмена 2: a = " << a << ", b = " << b << endl;
    
    // третий способ обмена
    obmen3(a, b);
    cout << "после обмена 3: a = " << a << ", b = " << b << endl;
    return 0;
}

// В функцию передаюется только значения, поэтому нет возможности влиять на исходные переменные, поэтому мы возвращаем новые значения
pair<int, int> obmen1(int a, int b) {
    return {b, a};
}

void obmen2(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void obmen3(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}