#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_size_t.h>
#include "uthash.h"

/**
 * Char comparison function
 */
int compareChars(const void *i, const void *j) {
    if(*(char*) i > *(char*) j) return 1;
    else if(*(char*) i < *(char*) j) return -1;
    else return 0;
}

/**
 * Time Complexity:     O(n log n + n)
 * Space Complexity:    O(1)
 */
char *areAnagrams(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    /* Property 1: Anagrams have same length */
    if(len1 != len2) return "False";
    /* Property 2: Sorted angrams should produce same string */
    qsort(str1, len1, sizeof(char), compareChars);
    qsort(str2, len2, sizeof(char), compareChars);
    char *x = str1, *y = str2;
    printf("%s, %s\n", str1, str2);
    while(*x != 0) {
        /* mismatch means not anagram */
        if(*x != *y) return "False";
        x++;
        y++;
    }
    return "True";
}

/**
 * Structure of an element in a map
 * Required when using uthash.
 * https://troydhanson.github.com/uthash
 */
typedef struct MAP{
    char key;
    int value;
    /* required by uthash */
    UT_hash_handle hh;
} map_t;

/**
 * Linear solution
 *
 * Time Complexity:     O(n)
 * Space Complexity:    O(n)
 */
char *areAnagrams_Linear(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    /* Property 1: Anagrams have same length */
    if(len1 != len2) return "False";
    /* Property 2: character count in anagrams is the same */
    /* initializing a map in uthash */
    map_t *map = NULL;
    map_t *temp = NULL;
    for(int i = 0; i < len1; i++) {
        HASH_FIND(hh, map, str1+i, sizeof(char), temp);
        if(temp == NULL) {
            map_t *m = malloc(sizeof(map_t));
            m->key = str1[i];
            m->value = 1;
            HASH_ADD(hh, map, key, sizeof(char), m);
        } else {
            temp->value++;
        }
    }
    for(int i = 0; i < len2; i++) {
        HASH_FIND(hh, map, str1+i, sizeof(char), temp);
        if(temp == NULL) {
            return "False";
        } else {
            temp->value--;
            if(temp->value < 0) return "False";
        }
    }
    return "True";
}

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: %s str1_a str1_b str2_a str2_b ...\n", argv[0]);
        return 1;
    }
    for( int i = 2; i < argc; i += 2) {
        printf("<%s, %s>: %s\n", strdup(argv[i-1]), strdup(argv[i]), areAnagrams_Linear(argv[i-1], argv[i]));
    }
}