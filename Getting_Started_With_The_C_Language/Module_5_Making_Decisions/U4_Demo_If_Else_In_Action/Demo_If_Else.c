/* The following program aims to put into practice all we have learned
so far using a simple program to demonstrate comparing string input
against a stored password value and performing an operation based
on the result.
*/

#include <stdio.h>  /* For console IO */
#include <string.h> /* For strcmp - Remember, we can't use = to copy strings! */

int main(void) {
    //  Max password size of 19.
    char password[20];

    printf("Please enter your password: ");
    //  Limit user input to 19 characters to prevent overflow.
    scanf("%19s", password);

    /*  Strcmp compares two strings lexicograpically (i.e. character
        by character). The function returns an integer value. 
        
        If the strings are matching, the function returns 0.

        If the strings don't match, the the function returns
        one of two possible values:

            - A postive integer representing the ASCII value
            of the last matching (or first available) character
            when the left string's ASCII value is greater than
            that of the right string.

            - A negative integer representing the ASCII value
            of the last matching (or first available) character 
            when the left string's ASCII value is less than
            that of the right string.

        We'll use this to determine our program's behaviour! */
    if (strcmp(password, "tOpSEcReT") == 0)
    {
        printf("Corrct Password! :-)\n");
    }

    //  If the passwords don't match, strcmp returns a value that
    //  isn't 0! So we'll enter the else body instead!
    else 
    {
        printf("Wrong Password :-( \n");
    }

    return 0;
}