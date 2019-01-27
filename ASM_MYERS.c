#include "ASM_MYERS.h"
#include <string.h>
#include <stdio.h>

//Outside for stackoverflow prevention
//This program only supports ascii characters
static uint64_t bits[CHAR_MAX];

//If you have just 1 << something it is treated as int, and on gcc it is just 32 bits!
static const uint64_t ONE = 1;

struct ASM_LEVENSHTEIN_OUTPUT
levenshtein_myers(const struct ASM_STRING text, const struct ASM_STRING pattern, const size_t max_distance) {
    struct ASM_LEVENSHTEIN_OUTPUT output = ASM_LEVENSHTEIN_OUTPUT_ALLOC();
    const size_t len_pattern = ASM_STRING_LEN(pattern);
    const size_t len_text = ASM_STRING_LEN(text);
    if (len_pattern > MAX_PATTERN_LENGHT) {
        printf("ERROR: too long pattern: %zu when maximum allowed is %zu\n", len_pattern, MAX_PATTERN_LENGHT);
        return output;
    }
    //memset treats everything as chars...
    memset(bits, 0, sizeof bits);
    for (size_t i = 0; i < len_pattern; i++) {
        const char pattern_char = ASM_STRING_AT(pattern, i);
        //I think all ascii chars are guaranteed to be positive, but overflow is well defined and consistent anyway
        bits[(unsigned char) pattern_char] |= ONE << i;
    }
    const uint64_t lenBitSelector = ONE << (len_pattern - 1);
    uint64_t pv = -1;
    uint64_t mv = 0;
    size_t g = len_pattern;
    for (size_t j = 0; j < len_text; j++) {
        const uint64_t eq = bits[(unsigned char) ASM_STRING_AT(text, j)];
        const uint64_t xh = (((eq & pv) + pv) ^ pv) | eq;
        const uint64_t ph = mv | (~(xh | pv));
        const uint64_t mh = pv & xh;
        const uint64_t xv = eq | mv;
        pv = (mh << 1) | (~(xv | (ph << 1)));
        mv = (ph << 1) & xv;
        g += (ph & lenBitSelector) != 0;
        g -= (mh & lenBitSelector) != 0;
        if (g <= max_distance) {
            ASM_LEVENSHTEIN_OUTPUT_ADD(&output, j);
        }
    }
    return output;
}
