/* 

    In high level languages such as C, copying a string is a simple as using the assignment operator '='.

    For example:

    string example = "bob";
    string example2 = example;

    In C however, copying is done via the "strcpy" function provided by the C standard library as demonstrated
    below. The copy function takes in two arguments, the first being the destination for the copied values,
    the first being the memory location holding the string to copy.

    In addition, we may know that in high level languages, we can use the '+' operator to concatenate strings.
    Again, in C, this is not supported functionality. Instead, we need to call the 'strcat(dest, source)'.
*/

#include <stdio.h>

/* strcpy and strcat are included in the string library.*/
#include <string.h>
int main(void)
{
    char stringToCopy[30] = "Hello World";
    char destination[100];

    char stringOne[10] = "Hello ";
    char stringTwo[10] = "World";

    //  Copy the second argument's string value into the memory address pointed at by the first argument.
    printf("Copying Values... \n");
    strcpy(destination, stringToCopy);
    printf("The copied string is %s \n", destination);

    //  Add the value that the second argument points to onto the end of the memory address pointed to by the 
    //  first argument.
    printf("Concatenating Values: \"%s\" and \"%s\"\n", stringOne, stringTwo);
    strcat(stringOne, stringTwo);
    printf("Result: %s\n", stringOne);

    //  One final example:

    char name[30] = "Jake ";
    char middleBit[30] = "is learning ";
    char programmingLaguage[12] = "C.";
    char output[100];

    strcpy(output, name);
    strcat(output, middleBit);
    strcat(output, programmingLaguage);
    printf("Output Is %s\n", output);

    return 0;
}