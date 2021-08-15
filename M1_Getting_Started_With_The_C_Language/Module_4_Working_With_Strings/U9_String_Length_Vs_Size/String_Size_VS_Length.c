/* 
    If we create a char array and invoke the sizeof function, we get the size of the array in chars (or bytes... remember each char
    is 8-bits which is a byte!) as the returned value. This is the maximum size of the array and is the total space it takes up
    in memory!

    It is important you don't confuse it with length!  Length is the number of elements in the array that are occupied by a value
    EXCLUDING the terminating null character.

    These functions are demonstrated below.

*/

#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[40];

    /* 
        Remember, we can't directly assign a value to a string in C after it's been declared using the '=' operator!
        We have to use strcpy or strcpy_s instead!
     */
    strcpy_s(name, sizeof(name), "Jake Mander");
    printf("Size of array: %d\n", sizeof(name));
    printf("Length of array %d\n", strlen(name));

    /* 
        Now, time for a more dynamic version of the above code!
    */

    char input[40];

    /*  
        Note that spaces in between words will mean scanf only stores the characters before the space occured.
        The %s format specifer will cause scanf to stop at the first non-whistespace character!

        An input of "Bob Marley" will give us an output of:
            "Size of input 40 : Length of input 3"

    */
    scanf_s("%39s", input, sizeof(input));

    int sizeOfInput = sizeof(input);
    int lengthOfInput = strlen(input);

    printf("Size of input %d : Length of input %d\n", sizeOfInput, lengthOfInput);
    return 0;
}