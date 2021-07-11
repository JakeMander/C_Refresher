/*  
    In C, control statements can be used to change the flow
    of a program.

    For example, in the for or while loop, the "continue" statement
    can be used to skip the reamining statements in the current loop
    iteration to the end of the block ready to loop round again if
    the condition still evaluates to true.

    This is useful in cases where the program has entered a particular
    state where you are not ready to perform a certain operation, or
    you have already performed an operation and want to skip the rest,
    but still want to keep running through the loop, possibly to perform
    more operations, if the loop is still in a state that is okay to 
    keep looping. 

    You can use continue like so:

    while (loopCondition)
    {
        // statements

        if (condition)
        {
            continue // Iteration breaks here if condtion = true.
        }

        // other statements (Not executed if continue called)
    }
    //  continue takes us to the end of the loop where we go back
    //  to the top and re-evaluate the condition.

    Alternatively we can use "break" in a similar manner.

    When we call break, the current loop will stop where it is, 
    exit the loop, and carry on with the normal program execution.
    When break is called, no more statements in the loop are executed
    AND we do not re-evaluate the condition. We simply break out and 
    keep going!

    We can use break like so:

    while (loopCondition) {
        // statements

        if (exitCondition)
        {
            break; // exit loop immediately. NO MORE EVALUATION OF loopCondition!
        }

        //  other statements (not executed if break called)
    }
    //  Normal program flow.

    Finally, another control flow keyword you might come across
    (though if you do, you're probably looking at code from the
    1970's) is the "goto" statement. 

    The goto statement will jump program execution to a specified
    label.

    But using goto is now universally accepted as a BAD CODE SMELL!

    It is highly advised you NEVER EVER use it...

    However, for the sake of clarity, and in the event you ever 
    come across it's use, here's how it looks in practice:

    while (loop_condition)
    {
        if (error_condtion)
        {
            goto Cleanup;
        }
        // other statements (skipped if goto called)

    }

    //  Here is a "label". We'll jump here when we call "goto Cleanup"
    Cleanup:
        // do cleanup stuff

    Why don't we use goto anymore? Because it makes code really
    hard to follow when you're jumping about all over the place.
    Back in the day, it's overuse created a lot of spaghetti code
    and so it has generally fallen out of use!

*/

#include <stdio.h> // Gives us printf.
#include <stdlib.h> // Gies us rand()
#include <time.h> // Gives us time for seed gen.

int main(void) 
{
    srand(time(NULL));
    puts("\nWhile Continue Demo! Condition is set to keep iterating till 10");
    puts("If We Hit An Odd Number, Continue On The Next Iteration! \n");
    //  Use continue to skip all the odd numbers!
    for (int i = 1; i <= 10; i++)
    {
        //  If forContinueCount isn't wholly divisible by 2
        //  It's Odd! So Skiparoo!
        if (i % 2 != 0)
        {
            continue;
        }

        printf("%d Is Even!\n", i);
    }

    //  Use break to exit a while loop whenever a random 
    //  number goes over 22

    puts("\nDo While To Demo Break! Condition is set to finish when rand is 50.");
    puts("However, we break out if we hit 8, 14, 18, 33, or 40! \n");
    int whileRand = 0;

    do 
    {
        puts("Generating A Random Number!");
        whileRand = rand() % 51;

        printf("Random Number Is: %d\n", whileRand);

        if (whileRand == 8)
        {
            puts("BREAKING! We Hit 8!");
            break;
        }

        if (whileRand == 14)
        {
            puts("BREAKING! We Hit 14!");
            break;
        }

        if (whileRand == 18)
        {
            puts("BREAKING! We Hit 18!");
            break;
        }

        if (whileRand == 33)
        {
            puts("BREAKING! We Hit 33!");
            break;
        }

        if (whileRand == 40)
        {
            puts("BREAKING! We Hit 40!");
            break;
        }

        if (whileRand == 50)
        {
            puts("We Hit 50! Condition exits normally!");
        }
    } while (whileRand != 50);
}