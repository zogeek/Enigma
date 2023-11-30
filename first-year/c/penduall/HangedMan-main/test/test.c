#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printAllF(FILE *f, char str[], int length);

int main(int argc, char const *argv[])
{
    /*int* found = NULL;*/
    char secret[15];
    FILE *file = NULL;

    printAllF(file, secret, 15);

    /*found = malloc(sizeof(int) * strlen(secret));
    free(found);*/

    return 0;
}

void printAllF(FILE *file, char str[], int length)
{
    file = fopen("C:\\Users\\Chris\\Desktop\\HangedMan\\word.txt", "r");
    if (file == NULL)
    {
        printf("Error : file do not be found.\n");
        exit(1);
    }

    while (fgets(str, length, file) != NULL)
    {
        printf("%s", str);
    }

    fclose(file);
}
