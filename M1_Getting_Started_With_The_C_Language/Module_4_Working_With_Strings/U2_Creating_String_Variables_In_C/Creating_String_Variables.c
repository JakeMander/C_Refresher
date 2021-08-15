/*
    There are no convinient string types in C! C is not high level enough to provide that functionality!

    For example, there is no "string name = jake"

    In C, strings are treated as a continuous block of characters. In memory, these are assigned to a single contiguous block
    of memory that starts from a single memory address.

    How do we create a string in C? See below!
*/
#include <stdio.h>

int main(void)
{
    /*  
        Character array. Char is a C type! In this instance, it is used to tell the C compiler that we are using an array of single
        characters organised into a single block of memory. 
         
        "firstname" is the identifier that represents the name of the string variable.
     
        "Jake" is the content of the string. This is a "string literal"!
    */
    char firstName[] = "Jake";
}