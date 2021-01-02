#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Using bit vector
 *
 * Assumptions: The string only contains lower case ascii characters
 *
 * Time Complexity:     O(n)
 * Space Complexity:    O(1)
 */
char *hasUniqueCharacters(char *str) {
    int checker = 0;
    int v;
    while(*str != 0) {
        v = *str - 'a';
        if((checker & (1 << v)) > 0) return "False";
        checker |= (1 << v);
        str++;
    }
    return "True";
}

/**
 * Comparion function for qsort (Lexicographic)
 */
int compareChars(const void *i, const void *j) {
    return *((char*)(i)) > *((char*)(j));
}

/**
 * Doing in-place sorting
 *
 * Time Complexity:     O(n log n + n)
 * Space Complexity:    O(1)
 */
char *hasUniqueCharacters_Sort(char *str) {
    size_t len = strlen(str);
    qsort(str, len, sizeof(char), compareChars);
    for(int i = 0, j = 1; i < len && j < len; i++,j++) {
        if(str[i] == str[j]) return "False";
    }
    return "True";
}

/**
 * Brute force solution
 *
 * Time Complexity:     O(n^2)
 * Space Complexity:    O(1)
 */
char *hasUniqueCharacters_Brute(char *str) {
    size_t len = strlen(str);
    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            if(str[j] == str[i]) return "False";
        }
    }
    return "True";
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s str1 str2 ...\n", argv[0]);
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        printf("%s: %s\n", strdup(argv[i]), hasUniqueCharacters_Brute(argv[i]));
    }
}

