/*
    As we've already discussed, the char type is the building block of strings.

    A varaible of type char will take up 8 bits (1 byte) of memory.

    Let's look at how we can build some char variables.

*/
#include <stdio.h>

int main(void)
{
    /*  We've created a single char variable! We've intialised it to upper case A.
        It's important to note that the char is delimitted by SINGLE quotes. 

        Also note that the char is an INTEGER type in C! Why? Because it represents an ASCII
        code! So for our example, variable "ch" actually stores the value of 65 which, as per the
        ASCII tables is the numeric value used to represent upper case 'A'.

        To represent special characters like the newline character (\n),
        the tab character (\t) or the null terminating character (\o) we 
        use a '\'. C has a few of these special values which typically do not
        output a character to the string, but perform some operation like moving
        the console cursor down a line, adding a tabular space between strings, 
        or even ringing the console 'bell' (or making it beep).

        If you want to input a single quotation mark, you need to specify that you aren't
        delimiting the string by inserting a slash before the quote like so - \' or \"

        Or 

        Note also that '\x[ASCII Code]' will give you the ASCII character of the hex code you provide.
        For example the string "\x41" will give you the hexadecimal representation of ASCII A, 
        and "\x43" will give you upper case C. 
        
        A - (1 * 16^0) + (4 * 16^1))) = 65.
        C - (3 * 16^0) + (4 * 16^1))) = 67.
    */
    char ch = 'A';
    printf("\x43 \n");
    printf("\x41 \n");
    return 0;
}