#ifndef controller_h
#define controller_h

typedef enum
{
    False,
    True,
} Boolean;

char readChar();

int isValid(char input, char str[]);

int isWin(int tab[], char str[]);



#endif // controller_h