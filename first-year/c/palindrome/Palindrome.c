//
// Created by ziyad on 24/11/2023.
//
#include <string.h>
#include <stdbool.h>
#include "Palindrome.h"

bool isPalindrome(char *word) {
    int length = strlen(word);
    char result[lenght];

    strtolower( result, word );
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return false;
        }
    }
    return true;
}
