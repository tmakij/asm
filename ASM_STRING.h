#ifndef ASM_STRING_H
#define ASM_STRING_H

#include <stddef.h>

struct ASM_STRING {
    const char* const arr;
    const size_t size;
};

struct ASM_STRING
ASM_STRING_ALLOC(const char* arr);

size_t
ASM_STRING_LEN(const struct ASM_STRING val);

const char*
ASM_STRING_VAL(const struct ASM_STRING val);

char
ASM_STRING_AT(const struct ASM_STRING val, size_t position);

size_t
ASM_STRING_LEVENSHTEIN_CHANGE(
        size_t position_a,
        size_t position_b,
        const struct ASM_STRING val_a,
        const struct ASM_STRING val_b);

void
ASM_STRING_FREE(const struct ASM_STRING val);

#endif
