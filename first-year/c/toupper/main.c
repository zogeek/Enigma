#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = toupper( *src++ ) );
    return result;
}

int main() {

    char * input = "Hello World!";
    char result[1];

    printf( "Result: %s\n", strtoupper( result, input ) );

    return EXIT_SUCCESS;
}
