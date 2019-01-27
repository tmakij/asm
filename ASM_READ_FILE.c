#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "ASM_STRING.h"

struct ASM_STRING
READ_FILE(const char* const file_path) {

    size_t read_chars_count = 1;
    char* read_chars = '\0';
    FILE * const file = fopen(file_path, "r");
    if (!file) {
        printf("File %s not found\n", file_path);
        return ASM_STRING_ALLOC("\0");
    }

    for (;;) {
        const int read = fgetc(file);
        if (read == EOF) {
            break;
        }
        read_chars_count++;
        read_chars = realloc(read_chars, read_chars_count * sizeof *read_chars);
        read_chars[read_chars_count - 2] = read;
    }

    read_chars[read_chars_count - 1] = '\0';
    const bool error = !feof(file);
    fclose(file);
    if (error) {
        perror("ERROR reading file: ");
        free(read_chars);
        return ASM_STRING_ALLOC("\0");
    }

    const struct ASM_STRING read_string = ASM_STRING_ALLOC(read_chars);
    free(read_chars);
    return read_string;
}
