#include "MIN.h"

size_t
min3(const size_t a, const size_t b, const size_t c) {
    return min2(min2(a, b), c);
}

size_t
min2(const size_t a, const size_t b) {
    if (a > b) {
        return b;
    }
    return a;
}
