#ifndef ASM_MYER_H
#define ASM_MYER_H

#include "stdint.h"
#include "limits.h"
#include "ASM_STRING.h"
#include "ASM_LEVENSHTEIN_OUTPUT.h"

//uint64_t is used to the store bits in Myers
#define MAX_PATTERN_LENGHT (sizeof(uint64_t) * CHAR_BIT)

struct ASM_LEVENSHTEIN_OUTPUT
levenshtein_myers(const struct ASM_STRING text, const struct ASM_STRING pattern, size_t max_distance);

#endif
