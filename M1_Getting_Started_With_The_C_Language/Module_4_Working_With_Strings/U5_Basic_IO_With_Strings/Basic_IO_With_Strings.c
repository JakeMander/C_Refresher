#include <stdio.h>

int main(void)
{
    /* 
        We have declared a character array (string) that can hold 40 characters...
        BUT DON'T FORGET! One of those characters needs to be free for the null terminator!
        Otherwise, the string will overflow, cut off our null terminator and we'll run into all
        sorts of bugs.

        In reality, we can only read 39 chars from the user.

        Now let's record some input
    */
    char name[40];

    /*  
        We could use scanf as we've already explored. Remember, we must provide the format specifier
        we expect, and a pointer to a memory location to store our input. 
        
        Now before we used '&' to extract the addresss of our variable. Here, we don't need to do this 
        because we're referencing an array. Calling an array returns a pointer to the memory address 
        that the array starts from (i.e. the first element)!
        
        scanf("%s", name); 
    */

    //  A better approach is to provide a format specifier that only allows the user to enter
    //  a specific number of input characters. We can do this by prefixing a number to the 
    //  format specifier. This way we prevent any buffer overflow attempts from users.
    //
    //  If the user goes over this limit, only the first 39 characters of the console input
    //  are recorded. The last character in the array remains the '\o'.
    scanf("%39s", name);

    //  Call our character array with the "%s" format specifer to tell C we want our chain of 
    //  characters out as a string! Remember, we don't need the & for our array! The name of an
    //  array when called IS the address!
    printf("%s", name);
    return 0;
}