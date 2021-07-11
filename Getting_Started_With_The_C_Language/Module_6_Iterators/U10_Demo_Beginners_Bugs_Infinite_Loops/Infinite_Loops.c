/*
    You may encounter instances where your program continues to print out
    values but never exits it's surrounding loop. This is symptomatic of
    a loop whose condition never evaluates to false...

    It's called an "infinite loop"... because your loop goes on and on
    forever and ever amen. 

    
*/

#include <stdio.h> // for printf

int main(void)
{
    // Why did this loop not work???
    for (int i = 0; i <= 10; i) 
    {
        printf("New Value is %d\n", i);
    }
}


/*  

    Answer: We forgot the iterator! So i just stays stuck at 0 and never
    goes above 10 which is our exit criteria!

    Bugs like this just require a bit of patience and a keen eye to 
    solve.
    
    If you're endlessly stuck in a cycle, it's most likely an issue with
    a loops conditional check!

    Keep an eye out for bugs like this too:

    int input = 0;
    
    while (input = 64)
    { 
        printf("Please Enter Number that is NOT 64 to continue: ")
        scanf("%d", input)

        printf("You Entered: %d \n\n", input)
    }

    return 0

    The loop will be stuck whatever you enter! Why? Because of this line:
 
        while(input = 64)

    We're using the assignment operator (=) not the 
    equality operator (==). So 64 is assigned to input EACH LOOP.
    64 is a non-zero number, so the statement evaluates to true each 
    iteration! 
*/
