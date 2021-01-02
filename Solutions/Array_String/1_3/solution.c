#include <stdio.h>
#include <string.h>
#include <sys/_types/_size_t.h>


/**
 * Brute force solution
 *
 * Time Complexity:     O(n^3)
 * Space Complexity:    O(1)
 * n = length of string
 */
void removeDuplicateCharacters_Brute(char *str) {
    size_t len = strlen(str);
    for(int i = 0; i < len; i++) {
        char c = str[i];
        for(int j = i+1; j < len; j++) {
            if(str[j] == c) {
                for(int k = j; k < (len-1); k++) {
                    str[k] = str[k+1];
                }
                str[--len] = 0;
            }
        }
    }
}

/**
 *
 * Brute Force solution
 *
 * Time Complexity:     O(n^2)
 * Space Complexity:    O(1)
 * n = length of string
 */
 void removeDuplicateCharacters_Brute2(char *str) {
     size_t len = strlen(str);
     /* minimum length of the string after duplicate removal*/
     int tail = 1;
     for(int i = 0; i < len; i++) {
         int j = 0;
         /* check if str[i] is duplicate of a character in str[0:tail] */
         for(; j < tail; j++) {
             /* break once duplicate is found */
             if(str[j] == str[i]) break;
         }
         /* if no duplicate was found the minimum length after removal 
          * increases by one and str[i] becomes last character in the
          * string.
          *
          * if str[i] is a duplicate found then tail remains the same and str[i]
          * will be replaced with the next non duplicate found.
         */
         if(j == tail) {
             str[tail++] = str[i];
         }
     }
     /* make str[tail] the end of the string */
     str[tail] = 0;
 }

 /**
 * Linear solution
 *
 * Time Complexity:     O(n)
 * Space Complexity:    O(n)
 */
 void removeDuplicateCharacters_Linear( char *str) {
     /* Length of String */
     size_t len = strlen(str);
     /* boolean array indexed using ascii symbols */
     /* implicit initialization of all values to 0 */
     short arr[256] = {0};
    //  for(int i = 0; i < 256; i++) {
    //      arr[i] = 0;
    //  }
     /* index for next non duplicate character */
     int tail = 0;
     for(int i = 0; i < len; i++) {
         if(arr[str[i]] == 0) {
             str[tail] = str[i];
             tail++;
             arr[str[i]] = 1;
         }
     }
     str[tail] = 0;
 }

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s str1 str2 ...\n", argv[0]);
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        char *t = strdup(argv[i]);
        removeDuplicateCharacters_Linear(argv[i]);
        printf("%s: %s\n", t, argv[i] );
    }
}