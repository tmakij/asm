#include <stdio.h>
#include <stdlib.h>

#include "PRECOMPUTED.h"
#include "../ASM_LEVENSHTEIN_OUTPUT.h"
#include "../ASM_STRING.h"

void
print_output_test(const struct ASM_LEVENSHTEIN_OUTPUT output) {
    printf("Print: ");
    const size_t count = ASM_LEVENSHTEIN_OUTPUT_COUNT(output);
    const size_t end = count - 1;
    if (count == 0) {
        puts("nothing to print");
        return;
    }
    for (size_t i = 0; i < end; i++) {
        printf("%zu ", ASM_LEVENSHTEIN_OUTPUT_AT(output, i));
    }
    printf("%zu\n", ASM_LEVENSHTEIN_OUTPUT_AT(output, end));
}

bool
test_results_correct(const struct ASM_LEVENSHTEIN_OUTPUT expected, const struct ASM_LEVENSHTEIN_OUTPUT received) {
    const size_t expectedCount = ASM_LEVENSHTEIN_OUTPUT_COUNT(expected);
    const size_t receivedCount = ASM_LEVENSHTEIN_OUTPUT_COUNT(received);
    if (expectedCount != receivedCount) {
        printf("FAILED TestWithStrings (precomputed) Different position counts, expected %zu but received %zu\n", expectedCount, receivedCount);
        return false;
    }
    for (size_t i = 0; i < expectedCount; i++) {
        const size_t receivedPosition = ASM_LEVENSHTEIN_OUTPUT_AT(received, i);
        const size_t expectedPosition = ASM_LEVENSHTEIN_OUTPUT_AT(expected, i);
        if (receivedPosition != expectedPosition) {
            printf("FAILED TestWithStrings (precomputed) Different values at position %zu, expected %zu but received %zu\n", i, expectedPosition, receivedPosition);
            return false;
        }
    }
    printf("SUCCESS TestWithStrings (precomputed)\n");
    return true;
}

bool
test_levensthein(const count_levensthein to_test, const struct ASM_STRING text, const struct ASM_STRING pattern, const size_t error, const struct ASM_LEVENSHTEIN_OUTPUT expected) {
    const struct ASM_LEVENSHTEIN_OUTPUT output = to_test(text, pattern, error);
    const bool correct = test_results_correct(expected, output);
    print_output_test(output);
    ASM_LEVENSHTEIN_OUTPUT_FREE(output);
    return correct;
}

bool
test_with_values(const count_levensthein to_test, const char* const text_c, const char* const pattern_c, const size_t error, const size_t expected_result[]) {
    const struct ASM_STRING text = ASM_STRING_ALLOC(text_c);
    const struct ASM_STRING pattern = ASM_STRING_ALLOC(pattern_c);
    struct ASM_LEVENSHTEIN_OUTPUT expected = ASM_LEVENSHTEIN_OUTPUT_ALLOC();
    for (const size_t* i = expected_result; *i != (size_t) - 1; i++) {
        ASM_LEVENSHTEIN_OUTPUT_ADD(&expected, *i);
    }
    const bool test_success = test_levensthein(to_test, text, pattern, error, expected);
    ASM_STRING_FREE(text);
    ASM_STRING_FREE(pattern);
    ASM_LEVENSHTEIN_OUTPUT_FREE(expected);
    return test_success;
}

bool
test_precomputed(const count_levensthein to_test) {
    bool success = true;
    const size_t expected[] = {9, -1};
    success = success && test_with_values(to_test, "datastructure", "strict", 1, expected);
    const size_t expected2[] = {18, -1};
    success = success && test_with_values(to_test, "heello world, hello moon, heffo sun", "hello", 0, expected2);
    const size_t expected3[] = {5, 17, 18, 19, -1};
    success = success && test_with_values(to_test, "heello world, hello moon, heffo sun", "hello", 1, expected3);
    const size_t expected4[] = {3, 4, 5, 6, 16, 17, 18, 19, 20, 30, -1};
    success = success && test_with_values(to_test, "heello world, hello moon, heffo sun", "hello", 2, expected4);
    const size_t expected5[] = {-1};
    success = success && test_with_values(to_test, "sFlmmytQesiDwILTGJkGfvAuYujhNxMfupmEGRQnEcNwECqNyuEhAvoLwjboGcbMWrHpadXMeJHnRPjvmLoFoHYlSlvRTJMMXwbENHIsth", "ucoPNtrAWhcKjTmWvOaky", 1, expected5);
    return success;
}
