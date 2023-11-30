#include <stdio.h>
#include <stdlib.h>

#include "Palindrome.h"


int main()
{
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);
    if (isPalindrome(word)) {
        printf("%s is a palindrome\n", word);
    } else {
        printf("%s is not a palindrome\n", word);
    }
    free(word);
    return 0;
}
