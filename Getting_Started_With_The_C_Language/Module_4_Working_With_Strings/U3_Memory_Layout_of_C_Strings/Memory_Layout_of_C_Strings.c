/*
    The following is a discussion on the memory layout of string in C. 

    Take the following string literal:

    "Jake"

    Let's think about how this is represented in memory. Remember, we represent strings as a single
    contiguous block of memory consisting of a chain of memory locations containing a single character
    variable in memory. Each character memory will typically be 8-bits long when stored as ASCII (0-255).

    So looking at Jake we may think we have four blocks of memory containing an 8-bit (one byte) value each. 

    That's WRONG!

    It's actually five!

    To delimit (that is to mark the end of the string in memory), C needs to end strings with a null terminator
    ("\o") - this is a byte with all the bits set to 0. So Jake is actually:

    "J" -> "A" -> "K" -> "E" -> "\o"

    The arrows can be considered pointers. The array initialisation sets all this up for us.
    C will also automatically add the null character on the end of our character array for us, 
    so we don't need to worry about appending one to the end.

    JUST ALWAYS REMEMBER STRINGS ARE ALL TERMINATED BY A NULL CHARACTER.

    You can land yourself into a whole bunch of trouble if you don't handle them correctly. 
    For instance, if you're missing the null terminator, the C program will keep walking up
    memory returning garbage values until it hits an invalid value.

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