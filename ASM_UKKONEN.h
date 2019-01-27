#ifndef PATTERN_UKKONEN_H
#define PATTERN_UKKONEN_H

#include "ASM_STRING.h"
#include "ASM_LEVENSHTEIN_OUTPUT.h"

struct ASM_LEVENSHTEIN_OUTPUT
levenshtein_ukkonen(const struct ASM_STRING text, const struct ASM_STRING pattern, size_t max_distance);

#endif
