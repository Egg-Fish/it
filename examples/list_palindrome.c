#include "it.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    List l = List_create();

    assert(List_getLength(l) == 0);

    char *word =
        "loremipsumdolorsitametconsecteturadipiscingelitintegerjustometussodalesvitaeve"
        "litaefficiturfinibusmolestieitselomsubinifruticiffeatileveativseladossutemotsu"
        "jregetnitilegnicsipidarutetcesnoctematisrolodmuspimerol";

    size_t wordLength = strlen(word);

    for (size_t i = 0; i < wordLength; i++) {
        List_appendItem(l, (char *)(word + i));
    }

    assert(List_getLength(l) == wordLength);

    bool isPalindrome = true;
    size_t length = List_getLength(l);

    for (size_t i = 0; i < length; i++) {
        size_t j = length - 1 - i;
        char *left = (char *)List_getItem(l, i);
        char *right = (char *)List_getItem(l, j);

        bool isEqual = *left == *right;

        printf("%c = l[%zu] == l[%zu] = %c? %s\n", *left, i, j, *right,
               isEqual ? "YES" : "NO");

        if (!isEqual) {
            isPalindrome = false;
        }
    }

    printf("palindrome? %s", isPalindrome ? "YES" : "NO");

    List_destroy(l);
    return 0;
}
