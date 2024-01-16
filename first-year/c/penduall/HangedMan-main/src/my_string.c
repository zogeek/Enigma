#include <stdio.h>
#include <string.h>
#include "my_string.h"

int my_strLen(const char str[]) // return a lenght of string.
{
    int i = 0;

    while (str != 0)
    {
        i++;
    }
    
    return i;
}

char outStringFromFile(FILE *f, char str[])
{
    f = fopen("word.txt", "r");
    if (f == NULL)
        printf("Error : file do not be found.\n");
        exit(1);
    
    fgets(str, my_strLen(str), f);
    strcpy(str, f);
    fclose(f);

    return str;
} 