/*  
    The following demo expands on our while loop 
    knowledge by building our own interpretation 
    of C's strlen function!

    Remember, a string in C is an array of characters with 
    an additional element sat at the end containing the
    null terminator '\n'.

    If we hit this, we know we've reached the end of a string, 
    so we can just count along until we hit it!
*/

#include <stdio.h> // Gives us printf

int main(void) 
{
    char str[] = "Jake";

    int len = 0; // Current char index in the str array.

    while (str[len] != '\0') // Keep iterating the index until we hit the null terminator.
    {
        len++;
    }

    // Print our string and the result!
    printf(" String: \"%s\" \n", str);
    printf(" Length: %d chars \n", len);
}