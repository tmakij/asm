#include "ASM_STRING.h"
#include <stdlib.h>
#include <string.h>

struct ASM_STRING
ASM_STRING_ALLOC(const char* const c_string) {
    const size_t length = strlen(c_string);
    char* const value = malloc(sizeof *value * (length + 1));
    memcpy(value, c_string, length);

    value[length] = '\0';
    //Needed for test debugging only...

    const struct ASM_STRING new = {
        .arr = value,
        .size = length
    };
    return new;
}

size_t
ASM_STRING_LEN(const struct ASM_STRING val) {
    return val.size;
}

const char*
ASM_STRING_VAL(const struct ASM_STRING val) {
    return val.arr;
}

char
ASM_STRING_AT(const struct ASM_STRING val, const size_t position) {
    return val.arr[position];
}

size_t
ASM_STRING_LEVENSHTEIN_CHANGE(
        const size_t position_a,
        const size_t position_b,
        const struct ASM_STRING val_a,
        const struct ASM_STRING val_b) {

    if (ASM_STRING_AT(val_a, position_a) == ASM_STRING_AT(val_b, position_b)) {
        return 0;
    }
    return 1;
}

void
ASM_STRING_FREE(const struct ASM_STRING val) {
    free((void*) val.arr);
}
