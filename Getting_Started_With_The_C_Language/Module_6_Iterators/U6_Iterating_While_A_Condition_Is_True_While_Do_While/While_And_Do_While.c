/*  
    If we want to iterate over a statement while a condition is true, 
    the "while" statement is typicaly the tool we'll use.

    This differs from the for loop which will typically used
    when we know a discrete range og itertions we'll know
    we'll be iterating over. 
  
    While loops make the most sense when we're not sure exactly
    when the condition we're evaluating will become true,
    but we need to keep executing a block of code whilst//  it hasn't been satisfied. 
  
    The while loop will typicallly take the form:
    while(condition)
    {
        //  statements
    }

    Like a for loop, when the condition is true, we execute the block
    of code in the body of the loop.

    When the condition changes to false, we skip over the block of code,
    stop iterating, and jump to the next line below to continue normal
    program execution.

    Note that if the condition intially evaluate to false, then the program
    will skip over the while loop altogether. 

    But what if we come across an instance where we want to run our loop
    at least once before deciding if we want to stay in the loop
    or not?

    For these instances, we can use a do while loop. 

    Similar to the while loop, the do while will always execute it's
    block of code before evaluating the condition, which means that
    a do while loop will always run AT LEAST ONCE!

    After execution, the condition is then evaluated which determines wether
    or not the block is repeated. 

    do while blocks are structured like so:

    do
    {
        // statements to execute.
    } while(condition)
*/

#include <stdio.h> // Gives us printf
#include <stdlib.h> // Gives us rand.
#include <time.h> // Gives us a seed for the random generator.

int main(void) 
{
    int whileTestIsEven = 0;
    int doWhileTestIsEven = 100;

    printf("Keep Printing While We Generate A New Random Number That's Even! (WHILE)\n");
    
    //  Set a seed for random to use. Otherwise we'll just end up with the same numbers
    //  each run. A good seed to use is the current time! This means the pseudo random
    //  numbers are jumbled each time!
    srand(time(0));

    //  Keep iterating over the loop whilst the randomly generated result of each iteration
    //  is even! You might need to run the program a few times to see the while loop
    //  kick in as you can end up with a few odd numbers generated one after the other!
    while (whileTestIsEven == 0)
    {
        //  Gives us a random number between 0 and 49.
        //  Takes the remainder of a division between a random
        //  number and 50. See the "modulo" operator. 
        int randomNumber = rand() % 50;

        printf("\nRandom Number Is %d\n", randomNumber);

        whileTestIsEven = randomNumber % 2;

        if (whileTestIsEven == 0)
        {
            printf("%d Is Even! Keep Going!\n", randomNumber);
        }

        else 
        {
            printf("%d Is Odd! Exiting!\n", randomNumber);
        }
    }
    
    putchar('\n');
    printf("Keep Printing While We Generate A New Random Number That's Even! (DO-WHILE)\n");
    //  Now let's look at the do while loop. Notice how doWhileTestEven
    //  is set to 100 which doesn't satisfy the condtion, but the do
    //  while loop runs anyway. This is because the do while executes 
    //  the block first, THEN checks the condition, which means we're
    //  always guaranteed to generate an odd or even number AT LEAST
    //  ONCE.
    do
    {
        //  Gives us a random number between 0 and 49.
        //  Takes the remainder of a division between a random
        //  number and 50. See the "modulo" operator. 
        int randomNumber = rand() % 50;

        printf("\nRandom Number Is %d\n", randomNumber);

        doWhileTestIsEven = randomNumber % 2;

        if (whileTestIsEven == 0)
        {
            printf("%d Is Even! Keep Going!\n", randomNumber);
        }

        else 
        {
            printf("%d Is Odd! Exiting!\n", randomNumber);
        }
    } while(doWhileTestIsEven == 0);
    putchar('\n');
    return 0;
}