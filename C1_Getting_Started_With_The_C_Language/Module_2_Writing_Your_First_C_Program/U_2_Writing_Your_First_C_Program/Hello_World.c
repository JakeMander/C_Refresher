/* 
    Header files are quite important in C. It's where we declare what integers
    our source file is going to use and what function prototypes we're expecting.
    This is quite important as it allows the compiler to know what to expect before
    it comes across calls to it in actual implementation in code.

    Here what we have is a C standard library file. stdio handles input and output
    and was almost certainly written by Dennis Ritchie when his genius mind concieved
    C. When the file is compiled the preprocessor sees the "include" keyword and inserts
    the C code found in both the stdio.h header file into the actual stdio.c implementation
    file so it has acces to all the definitions, macros and global variables it needs.
    
    Note this is all done on a file by file basis so file1.c has file1.h added to it's file
    and file2.c has file2.h added to it's file by the preprocessor.

    With this done, each file then get's compiled into an object ".o" file. this is where  
    the linker kicks in! If one object file depends on another object file by virute of an
    "include", then the linker handles the binding of these together.

    In this example, we import the import/output functionality of the C standard library
    to print out our very first message!
*/
#include <stdio.h>

int main(void)
{
    printf("Hello World\n");
    return 0;
}