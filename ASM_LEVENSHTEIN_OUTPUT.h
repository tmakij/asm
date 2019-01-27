#ifndef ASM_LEVENSHTEIN_OUTPUT_H
#define ASM_LEVENSHTEIN_OUTPUT_H

#include <stddef.h>

struct ASM_LEVENSHTEIN_OUTPUT {
#ifndef CSV_OUTPUT
    size_t* values;
    size_t internal_count;
#endif
    size_t count;
};

struct ASM_LEVENSHTEIN_OUTPUT
ASM_LEVENSHTEIN_OUTPUT_ALLOC();

void
ASM_LEVENSHTEIN_OUTPUT_ADD(struct ASM_LEVENSHTEIN_OUTPUT* to, size_t value);

size_t
ASM_LEVENSHTEIN_OUTPUT_COUNT(const struct ASM_LEVENSHTEIN_OUTPUT of);

size_t
ASM_LEVENSHTEIN_OUTPUT_AT(const struct ASM_LEVENSHTEIN_OUTPUT output, size_t position);

void
ASM_LEVENSHTEIN_OUTPUT_FREE(const struct ASM_LEVENSHTEIN_OUTPUT output);

#endif
