#include <stdio.h>
#include <string.h>

/**
 * Swap characters at given pointers
 */
void swap(char *i, char *j) {
    *i ^= *j;
    *j ^= *i;
    *i ^= *j;
}

/**
 * In place rotation
 *
 * Time Complexity:     O(n)
 * Space Complexity:    O(1)
 *
 */
void reverseString(char *str) {
    /* Front index */
    int s = 0;
    /* Back index */
    int e = strlen(str)-1;

    while(s < e) {
        swap(str+s, str+e);
        s++;
        e--;
    }
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s str1 str2 ...\n", argv[0]);
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        char *t = strdup(argv[i]);
        reverseString(argv[i]);
        printf("%s: %s\n", t, argv[i]);
    }
}