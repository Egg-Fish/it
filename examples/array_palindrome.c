#include "it.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    Array a = Array_create();

    assert(Array_getLength(a) == 0);

    char *word =
        "loremipsumdolorsitametconsecteturadipiscingelitintegerjustometussodalesvitaeve"
        "litaefficiturfinibusmolestieitselomsubinifruticiffeatileveativseladossutemotsu"
        "jregetnitilegnicsipidarutetcesnoctematisrolodmuspimerol";

    size_t wordLength = strlen(word);

    for (size_t i = 0; i < wordLength; i++) {
        Array_appendItem(a, (char *)(word + i));
    }

    assert(Array_getLength(a) == wordLength);

    bool isPalindrome = true;
    size_t length = Array_getLength(a);

    for (size_t i = 0; i < length; i++) {
        size_t j = length - 1 - i;
        char *left = (char *)Array_getItemAtIndex(a, i);
        char *right = (char *)Array_getItemAtIndex(a, j);

        bool isEqual = *left == *right;

        printf("%c = a[%zu] == a[%zu] = %c? %s\n", *left, i, j, *right,
               isEqual ? "YES" : "NO");

        if (!isEqual) {
            isPalindrome = false;
        }
    }

    printf("palindrome? %s", isPalindrome ? "YES" : "NO");

    Array_destroy(a);
    return 0;
}
