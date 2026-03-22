#include <string>
#include <iostream>
using namespace std;

#define PR(x) printf("x=%p, *x=%d, &x=%p\n", (void *)(x), *(x), (void *)&(x))
#define PRs(x) printf("x=%p, *x=%s, &x=%p\n", (void *)(x), (*(x)).c_str(), (void *)&(x))
#include <stdio.h>

int main(void) {

    // Работа с указателями на int
    int mass[] = {100, 200, 300};
    int *ptr1, *ptr2;
    ptr1 = mass;
    ptr2 = &mass[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2 - ptr1 = %ld\n", ptr2 - ptr1);


    // Работа с указателями на string
    string strs[] = {"string1", "string2", "string3"};
    string *ptr3, *ptr4;
    ptr3 = strs;
    ptr4 = &strs[2];
    PRs(ptr3);
    *ptr4 = "some changes still here";
    *(ptr4 - 2) = "some changes not here";
    ptr3++;

    *ptr3 = "some changes here";
    PRs(ptr3);
    PRs(ptr4);
    ++ptr4;
    
    printf("ptr4 - ptr3 = %ld\n", ptr4 - ptr3);
    cout << strs[0] << endl;
    cout << strs[1] << endl;
    cout << strs[2] << endl;
    return 0;
}