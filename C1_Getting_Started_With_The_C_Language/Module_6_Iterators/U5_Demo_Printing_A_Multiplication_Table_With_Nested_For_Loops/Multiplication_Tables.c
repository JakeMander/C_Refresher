//  The following demonstrates how we can nest for loops 
//  together to sequence iterations together. In this example,
//  we use two for loops to print both rows and columns of a 
//  multiplication table. 

#include <stdio.h> // Gives us printf
#include <string.h> // Gives us strlen

int main(void) 
{
    //  Calculate the first 12 multiples of everything up to the 12 times tables!
    //  The outer loop will control the number of rows we have! Each time we enter
    //  the loops body, we hit another for loop! This loop then takes control and
    //  we wont exit that loop until it has fully iterated and satisfied it's condition.
    //  When this happens, we hit the end of the outer loop and start another iteration.
    //  This continues until the outer loop fully satisfies it's own condition.
    for (int i = 1; i <= 12; i++) 
    {
        //  The inner loop will control the number of columns and calculate
        //  the multiplication of the times tables. Once the first 12 values
        //  have been computed, move on to a new line and move back to the top
        //  of the loop so the outer loop can iterate again. 
        for (int j = 1; j <= 12; j++) 
        {
            //  Here we specify a 4 column minimum width for each value output
            //  to the console. This will format our times table more nicely :-)
            printf("%4d", (i * j));
        }
        //  We've reached the end of the row, so we'll want to start our new 
        //  times table on a new line!
        putchar('\n');
    }
    return 0;
}