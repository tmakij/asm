#include "ASM_LEVENSHTEIN_OUTPUT.h"
#include <stdlib.h>

/*
 * For the CSV output only count is saved.
 * Realloc slows down very severly after around 30 iterations, and this test isn't about glibc's realloc implementation.
 * For other tests the internal capacity doubles its size, which should be enough for single iteration runs.
 */


#ifndef CSV_OUTPUT
static const size_t INTERNAL_CAPACITY_MULTIPLIER = 2;
#endif

struct ASM_LEVENSHTEIN_OUTPUT
ASM_LEVENSHTEIN_OUTPUT_ALLOC() {
    const struct ASM_LEVENSHTEIN_OUTPUT allocated = {
#ifndef CSV_OUTPUT

        .internal_count = 1,
        .values = NULL,
#endif
        .count = 0
    };
    return allocated;
}

void
ASM_LEVENSHTEIN_OUTPUT_ADD(struct ASM_LEVENSHTEIN_OUTPUT * const to, const size_t value) {
    to->count++;

#ifndef CSV_OUTPUT
    if (to->count == to->internal_count) {
        to->internal_count *= INTERNAL_CAPACITY_MULTIPLIER;
        to->values = realloc(to->values, to->internal_count * sizeof *to->values);
    }
    to->values[to->count - 1] = value;
#else
    (void) value;
#endif

}

size_t
ASM_LEVENSHTEIN_OUTPUT_COUNT(const struct ASM_LEVENSHTEIN_OUTPUT of) {
    return of.count;
}

size_t
ASM_LEVENSHTEIN_OUTPUT_AT(const struct ASM_LEVENSHTEIN_OUTPUT output, const size_t position) {
#ifdef CSV_OUTPUT
    (void) position;
    (void) output;
    return 0;
#else
    return output.values[position];
#endif
}

void
ASM_LEVENSHTEIN_OUTPUT_FREE(const struct ASM_LEVENSHTEIN_OUTPUT output) {
#ifdef CSV_OUTPUT
    (void) output;
#else
    free(output.values);
#endif
}
