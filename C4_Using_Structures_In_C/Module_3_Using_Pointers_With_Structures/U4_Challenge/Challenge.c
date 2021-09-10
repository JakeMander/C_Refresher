#include <stdlib.h>
#include <stdio.h>
/*
    Here's a nice simple programming exercise to test our pointer knowledge.

    First, declare a variable.

    Second, initalize a pointer to that variable. 

    Finally, output the address of the variable using:
        - The variable itself.
        - The pointer.
*/

int main(int argc, char *argv)
{
    int aVariable = 42;
    int *aPointerToThatVariable;
    
    aPointerToThatVariable = &aVariable;

    printf("\n\n\tAddress using variable: %p \t:\t Address Using Pointer: %p\n", &aVariable, aPointerToThatVariable);
    return 0;
}