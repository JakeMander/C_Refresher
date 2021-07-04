/* 

    There are a whole class of bugs that can lead to security vulnerabilities that result from allowing the 
    user to access portions of memory they shouldn't be allowed to access. This is typically done when the
    user hijacks a string function such as scanf or printf to overflow the allocated buffer in memory and
    move onto memory they shouldn't be able to access.

    After it's original release, C then released more secure functions to help protect against this.

    strcpy_s
    strcat_s

    Safe functions are suffixed with an "_s"!

    These function perform more runtime checks on the incoming arguments to ensure that safe string memory is being 
    accessed. 

    To do this, the safe functions require that the user provide the destination buffer size so the function knows how much
    memory is available for it and when to prevent the user from going beyond this.

    These safe functions will STOP WRITING characters when they reach the safe end of the destination buffer.

    C is powerful, but it provides the user the ability to write incredibly unsafe code! So pay attention!

*/

#include <stdio.h>

/* strcpy and strcat are included in the string library.*/
#include <string.h>
int main(void)
{
    // The previous final example with the SAFE functions:

    char name[30] = "Jake ";
    char middleBit[30] = "is learning ";
    char programmingLaguage[12] = "C.";
    char output[100];

    /*  Note the use of "sizeof". This will allow us to calculate the size of our output buffer in bytes at 
        runtime and plug in the size of it when it's required. This is much better practice than manually
        passing in "magic" literal values. For example, we should avoid doing:

        strcpy_s(output, 100, name).

        This is bad for code maintainability and can often make code difficult to understand what is going on.
        For example, what is 100 and why does it need to be 100 long?
        
    */
    strcpy_s(output, sizeof(output), name);
    strcat_s(output, sizeof(output), middleBit);
    strcat_s(output, sizeof(output), programmingLaguage);
    
    /*  
        Convienient way of outputting a value when no specific formatting is required. Note, puts automiatcally appends a newline
        character to the end of the string.
    */
    puts(output);

    return 0;
}