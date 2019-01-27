#ifdef ASM_TEST
#include "Tests/TESTS.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "ASM_STRING.h"
#include "ASM_DYNAMIC.h"
#include "ASM_UKKONEN.h"
#include "ASM_LEVENSHTEIN_OUTPUT.h"
#include "ASM_LEVENSTHEIN.h"
#include "ASM_MYERS.h"
#include "ASM_READ_FILE.h"

void
print_excel(
        const char* const sample_name,
        const count_levensthein counter,
        const struct ASM_STRING text,
        const struct ASM_STRING pattern,
        const size_t error) {

    const clock_t startTime = clock();
    const struct ASM_LEVENSHTEIN_OUTPUT output = counter(text, pattern, error);
    const clock_t endTime = clock();
    const double timeElapsed = 1.0 * (endTime - startTime) / CLOCKS_PER_SEC;
    printf("%s;%zu;%f;%zu\n", sample_name, ASM_STRING_LEN(pattern), timeElapsed, ASM_LEVENSHTEIN_OUTPUT_COUNT(output));
    ASM_LEVENSHTEIN_OUTPUT_FREE(output);
}

void
print_end_positions(const struct ASM_LEVENSHTEIN_OUTPUT output) {
    const size_t end = ASM_LEVENSHTEIN_OUTPUT_COUNT(output) - 1;
    for (size_t i = 0; i < end; i++) {
        printf("%zu ", ASM_LEVENSHTEIN_OUTPUT_AT(output, i) + 1);
        //From 0...N-1 to 1...N
    }
    printf("%zu\n", ASM_LEVENSHTEIN_OUTPUT_AT(output, end) + 1);
}

void
levenshtein(const count_levensthein counter, const struct ASM_STRING text, const struct ASM_STRING pattern, const size_t error) {
    const clock_t startTime = clock();
    const struct ASM_LEVENSHTEIN_OUTPUT output = counter(text, pattern, error);
    const clock_t endTime = clock();
    const double timeElapsed = 1.0 * (endTime - startTime) / CLOCKS_PER_SEC;
    printf("%f seconds\n ", timeElapsed);
    if (ASM_LEVENSHTEIN_OUTPUT_COUNT(output) != 0) {
        print_end_positions(output);
    } else {
        puts("  No positions were found");
    }
    ASM_LEVENSHTEIN_OUTPUT_FREE(output);
}

const char* bool_as_string(const bool value) {
    return value ? "true" : "false";
}

int
main(const int argc, const char *const argv[]) {

#ifdef ASM_TEST

    (void) argc;
    (void) argv;
    srand(time(NULL));
    const bool pre_dyn = test_precomputed(levenshtein_dynamic);
    const bool pre_ukk = test_precomputed(levenshtein_ukkonen);
    const bool pre_mye = test_precomputed(levenshtein_myers);
    const bool rand_ukk = test_random(levenshtein_ukkonen);
    const bool rand_mye = test_random(levenshtein_myers);
    puts("Succeeded:");
    puts(" Precomputed:");
    printf("  Dynamic:%s\n  Ukkonen:%s\n  Myers:%s\n", bool_as_string(pre_dyn), bool_as_string(pre_ukk), bool_as_string(pre_mye));
    puts(" Random:");
    printf("  Ukkonen:%s\n  Myers:%s\n", bool_as_string(rand_ukk), bool_as_string(rand_mye));

#else
#ifdef CSV_OUTPUT

    if (argc != 3) {
        puts("Must have exactly two arguments:\n 1:pattern\n 2:text file path");
        puts(" e.g. asm hello hello_world.txt");
        return EXIT_FAILURE;
    }
    const struct ASM_STRING pattern = ASM_STRING_ALLOC(argv[1]);
    const struct ASM_STRING text = READ_FILE(argv[2]);
    if (ASM_STRING_LEN(text) == 0) {
        return EXIT_FAILURE;
    }
    /*
     * Static pattern, different error
     */
    puts("algorithm;pattern_length;time;positions");
    for (size_t max_distance = 0; max_distance <= MAX_PATTERN_LENGHT; max_distance++) {
        print_excel("Dynamic", levenshtein_dynamic, text, pattern, max_distance);
        print_excel("Ukkonen", levenshtein_ukkonen, text, pattern, max_distance);
        print_excel("Myers", levenshtein_myers, text, pattern, max_distance);
    }

    /*
     * Used for static error, different pattern
     * Comment above and comment out below
     */

    /*
    static const char *const test_vals[] = {
        "F", "FI", "FIQ", "FIQG", "FIQGY", "FIQGYS", "FIQGYSD", "FIQGYSDL", "FIQGYSDLF", "FIQGYSDLFG", "FIQGYSDLFGN", "FIQGYSDLFGNR", "FIQGYSDLFGNRA", "FIQGYSDLFGNRAD", "FIQGYSDLFGNRADN", "FIQGYSDLFGNRADNY", "FIQGYSDLFGNRADNYA", "FIQGYSDLFGNRADNYAA", "FIQGYSDLFGNRADNYAAP", "FIQGYSDLFGNRADNYAAPG", "FIQGYSDLFGNRADNYAAPGS", "FIQGYSDLFGNRADNYAAPGSV", "FIQGYSDLFGNRADNYAAPGSVA", "FIQGYSDLFGNRADNYAAPGSVAS", "FIQGYSDLFGNRADNYAAPGSVASM", "FIQGYSDLFGNRADNYAAPGSVASMF", "FIQGYSDLFGNRADNYAAPGSVASMFS", "FIQGYSDLFGNRADNYAAPGSVASMFSP", "FIQGYSDLFGNRADNYAAPGSVASMFSPA", "FIQGYSDLFGNRADNYAAPGSVASMFSPAA", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAY", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLT", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTE", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTEL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELY", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYR", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYRE", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREA", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAK", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKN", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLH", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHD", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDS", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSS", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSS", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSI", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIY", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYY", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLD", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDK", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKR", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRR", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRP", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPD", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLA", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLAS", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLASL", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLASLM", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLASLML", "FIQGYSDLFGNRADNYAAPGSVASMFSPAAYLTELYREAKNLHDSSSIYYLDKRRPDLASLMLS"
    };

    for (size_t i = 0; i < 64; i++) {
        const struct ASM_STRING pattern_dyn = ASM_STRING_ALLOC(test_vals[i]);
        print_excel("Dynamic", levenshtein_dynamic, text, pattern_dyn, 60);
        print_excel("Ukkonen", levenshtein_ukkonen, text, pattern_dyn, 60);
        print_excel("Myers", levenshtein_myers, text, pattern_dyn, 60);
        ASM_STRING_FREE(pattern_dyn);
    }
     */
#else

    if (argc != 4) {
        puts("Must have exactly three arguments:\n 1:pattern\n 2:pattern maximum mismatch\n 3:text file path");
        puts(" e.g. asm hello 2 hello_world.txt");
        return EXIT_FAILURE;
    }
    size_t max_distance;
    if (sscanf(argv[2], "%zu", &max_distance) != 1) {
        perror("Error reading pattern maximum mismatch: ");
        return EXIT_FAILURE;
    }
    const struct ASM_STRING pattern = ASM_STRING_ALLOC(argv[1]);
    const struct ASM_STRING text = READ_FILE(argv[3]);
    if (ASM_STRING_LEN(text) == 0) {
        return EXIT_FAILURE;
    }
    puts("Time / End positions found with");

    /*printf(" Dynamic: ");
    levenshtein(levenshtein_dynamic, text, pattern, max_distance);
    printf(" Ukkonen: ");
    levenshtein(levenshtein_ukkonen, text, pattern, max_distance);*/
    printf(" Myers: ");
    levenshtein(levenshtein_myers, text, pattern, max_distance);

#endif

#endif
    return EXIT_SUCCESS;
}
