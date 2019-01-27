#include "ASM_DYNAMIC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MIN.h"

/* Dynamic programming solution,
 * with only linear memory in relation to the pattern length
 */
struct ASM_LEVENSHTEIN_OUTPUT
levenshtein_dynamic(const struct ASM_STRING text, const struct ASM_STRING pattern, const size_t max_distance) {

    struct ASM_LEVENSHTEIN_OUTPUT output = ASM_LEVENSHTEIN_OUTPUT_ALLOC();
    const size_t len_text = ASM_STRING_LEN(text);
    const size_t len_pattern = ASM_STRING_LEN(pattern);
    const size_t rows = len_pattern + 1;
    const size_t columns = len_text + 1;
    const size_t alloc_size = rows * sizeof alloc_size;
    size_t * const distance_matrix = malloc(alloc_size);
    for (size_t i = 0; i < rows; i++) {
        distance_matrix[i] = i;
    }
    for (size_t x = 1; x < columns; x++) {
        const size_t x_char_index = x - 1;
        size_t c = distance_matrix[0];
        distance_matrix[0] = 0;
        /*The string processing algorithms slides told to use
         * distance_matrix[0] = x
         * but hopefully that was wrong
         */
        for (size_t y = 1; y < rows; y++) {
            const size_t y_char_index = y - 1;
            const size_t diagonal_prev = c + ASM_STRING_LEVENSHTEIN_CHANGE(x_char_index, y_char_index, text, pattern);
            const size_t up_prev = distance_matrix[y - 1] + 1;
            const size_t left_prev = distance_matrix[y] + 1;
            const size_t minimal_change = min3(diagonal_prev, up_prev, left_prev);
            c = distance_matrix[y];
            distance_matrix[y] = minimal_change;
        }
        const size_t distance = distance_matrix[len_pattern];
        if (distance <= max_distance) {
            ASM_LEVENSHTEIN_OUTPUT_ADD(&output, x_char_index);
        }
    }

    free(distance_matrix);
    return output;
}
