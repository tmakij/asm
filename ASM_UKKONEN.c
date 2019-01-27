#include "ASM_DYNAMIC.h"
#include <stdio.h>
#include <stdlib.h>
#include "MIN.h"

/* Dynamic programming solution, with Ukkonen's Cut-off heuristic and
 * only linear memory in relation to the pattern length
 */
struct ASM_LEVENSHTEIN_OUTPUT
levenshtein_ukkonen(const struct ASM_STRING text, const struct ASM_STRING pattern, const size_t max_distance) {

    struct ASM_LEVENSHTEIN_OUTPUT output = ASM_LEVENSHTEIN_OUTPUT_ALLOC();
    const size_t len_text = ASM_STRING_LEN(text);
    const size_t len_pattern = ASM_STRING_LEN(pattern);
    const size_t rows = len_pattern + 1;
    const size_t columns = len_text + 1;
    size_t smallest_undiscarded_diagonal = min2(max_distance + 1, len_pattern);
    const size_t alloc_size = rows * sizeof alloc_size;
    size_t * const distance_matrix = malloc(alloc_size);
    for (size_t i = 0; i <= smallest_undiscarded_diagonal; i++) {
        distance_matrix[i] = i;
    }

    for (size_t x = 1; x < columns; x++) {
        size_t c = distance_matrix[0];
        distance_matrix[0] = 0;
        const size_t x_char_index = x - 1;
        for (size_t y = 1; y <= smallest_undiscarded_diagonal /*Cut-off*/; y++) {
            const size_t y_char_index = y - 1;
            const size_t diagonal_prev = c + ASM_STRING_LEVENSHTEIN_CHANGE(x_char_index, y_char_index, text, pattern);
            const size_t up_prev = distance_matrix[y - 1] + 1;
            const size_t left_prev = distance_matrix[y] + 1;
            const size_t minimal_change = min3(diagonal_prev, up_prev, left_prev);
            c = distance_matrix[y];
            distance_matrix[y] = minimal_change;
        }
        //Counting the cut-off position
        while (distance_matrix[smallest_undiscarded_diagonal] > max_distance) {
            smallest_undiscarded_diagonal--;
        }
        if (smallest_undiscarded_diagonal == len_pattern) {
            ASM_LEVENSHTEIN_OUTPUT_ADD(&output, x_char_index);
        } else {
            smallest_undiscarded_diagonal++;
            distance_matrix[smallest_undiscarded_diagonal] = max_distance + 1;
        }
    }

    free(distance_matrix);
    return output;
}
