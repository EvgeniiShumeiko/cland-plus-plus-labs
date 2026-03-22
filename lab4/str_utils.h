#pragma once

#include <cstddef>

inline int dlina1(const char* s) {
    int n = 0;
    while (s && s[n] != '\0') ++n;
    return n;
}

inline int dlina2(const char* s) {
    if (!s) return 0;
    const char* p = s;
    while (*p) ++p;
    return static_cast<int>(p - s);
}

inline int dlina3(const char* s) {
    if (!s) return 0;
    int i = 0;
    for (; s[i] != '\0'; ++i) {}
    return i;
}

inline void kopir(char* dst, const char* src) {
    if (!dst || !src) return;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = '\0';
}

inline int sravn(const char* a, const char* b) {
    if (!a || !b) return 0;
    while (*a && *b && *a == *b) {
        ++a;
        ++b;
    }
    return static_cast<unsigned char>(*a) - static_cast<unsigned char>(*b);
}

inline void konkat(char* dst, const char* src) {
    if (!dst || !src) return;
    while (*dst) ++dst;
    while (*src) *dst++ = *src++;
    *dst = '\0';
}

