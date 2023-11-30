#include "controller.h"
#include "my_string.h"

// get a chararacter inputted from a user and transform his input to uppercase character and ignore '\n'.
char readChar()
{
    char character = 0;

    character = getchar();
    character = toupper(character);

    while (getchar != '\n')
        ;

    return character;
}

// check if the user input equal to a string and return a boolean. If it s true, the user found the character of the word.
int isValid(char input, char str[])
{
    for (int i = 0; i < my_strLen(str); i++)
    {
        if (input == str[i])
        {
            return True;
        }
    }
    return False;
}

// check if the entire of array of boolean is on true else return false.
int isWin(int tab[], char str[])
{
    int win = True;

    for (int i = 0; i < my_strLen(str); i++)
    {
        if (tab[i] == False)
        {
            win = False;
        }
    }
    return win;
}