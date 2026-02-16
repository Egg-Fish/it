#include "it.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    List l = List_create();
    
    assert(List_getLength(l) == 0);

    const char *word = "aabbaa";

    for (size_t i = 0; i < 6; i++) {
        List_appendItem(l, (char *)(word + i));
    }
    
    assert(List_getLength(l) == 6);

    bool isPalindrome = true;
    size_t length = List_getLength(l);

    for (size_t i = 0; i < length; i++) {
        size_t j = length - 1 - i;
        char *left = (char *)List_getItem(l, i);
        char *right = (char *)List_getItem(l, j);

        bool isEqual = *left == *right;

        printf("l[%zu] == l[%zu]? %s\n", i, j, isEqual ? "YES" : "NO");

        if (!isEqual) {
            isPalindrome = false;
        }
    }

    printf("is %s a palindrome? %s", word, isPalindrome ? "YES" : "NO");

    List_destroy(l);
    return 0;
}
