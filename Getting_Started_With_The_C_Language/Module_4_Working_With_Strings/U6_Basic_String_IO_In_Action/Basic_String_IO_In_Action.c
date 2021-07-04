#include <stdio.h>

int main(void)
{
    printf("What is your name?: ");
    
    /*  Recap: We declare an array of 40 memory blocks with enough space to hold a character each
        However, remember one of those needs to be the null terminator, so in our string input (scanf) 
        we explicitly tell C to only read the first 39 characters of input so we can leave the last 
        array element free as the null element. 

        As a final note, remember, we don't need to use an '&' with name to tell scanf to store the result to
        name's memory location. name is an array and therefore it's implied that a call to name refers to the
        first memory location.

        Try debugging the program. You'll see how C is handling the 'name' string location behind the scenes.
        A lot of these will be garbage values left over from previous computations!
    */
    char name[40];
    scanf("%39s", name);

    printf("\n");
    printf("Hello! Nice to meet you %s\n", name);
    return 0;
}