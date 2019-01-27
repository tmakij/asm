#include "RANDOM_TEST.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../ASM_LEVENSHTEIN_OUTPUT.h"
#include "../ASM_DYNAMIC.h"
#include "../ASM_STRING.h"
#include "../ASM_MYERS.h"

#define max_len_pattern MAX_PATTERN_LENGHT
#define max_len_text 256

static const unsigned long test_iteration_count = 20000;

static char buffer_text[max_len_text];
static char buffer_pattern[max_len_pattern];

struct ASM_STRING
randomize_string(char buffer[], const size_t max_len) {
    //Must be over 1
    const size_t size = (rand() % (max_len - 3)) + 2;
    const size_t size_without_null = size - 1;
    printf("%zu", size);
    for (size_t i = 0; i < size_without_null; i++) {
        //Different ranges of ascii table
        if (rand() % 2) {
            buffer[i] = 'A' + (rand() % 25);
        } else {
            buffer[i] = 'a' + (rand() % 25);
        }
    }
    buffer[size_without_null] = '\0';
    return ASM_STRING_ALLOC(buffer);
}

bool
test_results_correct2(const struct ASM_LEVENSHTEIN_OUTPUT expected, const struct ASM_LEVENSHTEIN_OUTPUT received) {
    const size_t expectedCount = ASM_LEVENSHTEIN_OUTPUT_COUNT(expected);
    const size_t receivedCount = ASM_LEVENSHTEIN_OUTPUT_COUNT(received);
    if (expectedCount != receivedCount) {
        printf("FAILED (random) Different position counts, expected %zu but received %zu\n", expectedCount, receivedCount);
        return false;
    }
    for (size_t i = 0; i < expectedCount; i++) {
        const size_t receivedPosition = ASM_LEVENSHTEIN_OUTPUT_AT(received, i);
        const size_t expectedPosition = ASM_LEVENSHTEIN_OUTPUT_AT(expected, i);
        if (receivedPosition != expectedPosition) {
            printf("FAILED (random) Different values at position %zu, expected %zu but received %zu\n", i, expectedPosition, receivedPosition);
            return false;
        }
    }
    puts("SUCCESS (random)");
    return true;
}

bool
test_random(count_levensthein to_compare) {

    unsigned long ok = 0;
    for (unsigned long i = 0; i < test_iteration_count; i++) {
        const size_t max_distance = rand() % (max_len_pattern + 5);//Probably useful to test over limit also...
        printf("Test number: %lu, distance: %zu\n", i, max_distance);
        printf("Pattern length: ");
        const struct ASM_STRING test_pattern = randomize_string(buffer_pattern, max_len_pattern);
        printf(", text length: ");
        const struct ASM_STRING test_text = randomize_string(buffer_text, max_len_text);
        printf("\nText: %s\nPattern: %s\n", ASM_STRING_VAL(test_text), ASM_STRING_VAL(test_pattern));
        //Dynamic is the base to compare
        const struct ASM_LEVENSHTEIN_OUTPUT expected = levenshtein_dynamic(test_text, test_pattern, max_distance);
        const struct ASM_LEVENSHTEIN_OUTPUT received = to_compare(test_text, test_pattern, max_distance);
        ASM_STRING_FREE(test_pattern);
        ASM_STRING_FREE(test_text);
        const bool correct = test_results_correct2(expected, received);
        ASM_LEVENSHTEIN_OUTPUT_FREE(expected);
        ASM_LEVENSHTEIN_OUTPUT_FREE(received);
        if (correct) {
            ok++;
        }
    }

    printf("Success ratio: %f\n", ok * 1.0 / test_iteration_count);
    return ok == test_iteration_count;
}
