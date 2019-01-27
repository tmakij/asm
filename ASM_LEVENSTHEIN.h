#ifndef ASM_LEVENSTHEIN_H
#define ASM_LEVENSTHEIN_H

#include "ASM_STRING.h"
#include "ASM_LEVENSHTEIN_OUTPUT.h"

typedef struct ASM_LEVENSHTEIN_OUTPUT(*count_levensthein)(const struct ASM_STRING, const struct ASM_STRING, size_t);

#endif
