/* The for loop allows the developer to iterate over a defined body of statements
over a given number of times (or iterations). 

Let's take a look at a for-loop:

for (int i = 0; i < 5; i++) {
    // statements to execute.
}

The for loop is broken down into three individual sections seperated by a semi-colon. 
Each has it's own purpose in running the for loop. Starting from the left hand side we
have:

- Initialization: In this first section, we an initalize a variable (typically called 'i',
but this is just common practice). This value acts as a counter and will be iterated to
help us determine how many times we should perform the embedded statements in the body.

- Condition: The middle section is where we declare a condition. This condition determines
when the iteration should stop. It's defined by a boolean condition. Whilst this condition
remains true, we'll keep hitting the statements. If it goes False, we stop the loop
and jump to the line below the last curly brace. Note that the condition is evaluated
BEFORE the body is executed! that means if the condition is set to initally evaluate to
false, then the loop will not run!

- Iterator: The end section is the iterator. This operation is called each time the condition
evaluates to true. It updates our initalized value and typically increments or decrements
the value. How much this is by can be varied using the += or -= increment or decrement 
operators. The iterator will ultimately change the initialized value in such a way
that the condition is no longer satisfied. The for loop will then stop!

As we've seen with if statements, if your for loop encloses a body that consists of only
a single statement, you can omit the curly braces like so:

for(int i = 0; i < 20; i++)
    printf("%d\n", i);

But be careful! It might look cleaner, but you'll have to start adding curly braces all over
the place if you decide later on you need more code inside the loop!

As one final note, it's important to note that you can ony access the variable
you initialize as part of the for loop INSIDE the scope of the for loop. 

So you can't do the following:

for (int i = 0; i < 50; i++)
{
    // statements
}
i = 12 //  NOt ALLOWED! "i" has gone out of scope!
*/

#include <stdio.h>

int main(void) 
{

    printf("%s", "For Loop Incrementing\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    
    printf("%s", "**********************\n");
    printf("%s", "For Loop Decrementing\n");
    for (int i = 10; i > 0; i--)
    {
        printf("%d\n", i);
    }
    printf("%s", "**********************\n");
    printf("%s", "For Loop Incrementing By 2\n");
    for (int i = 1; i < 20; i += 2)
    {
        printf("%d\n", i);
    }
    printf("%s", "**********************\n");
    printf("%s", "For Loop Incrementing By A Factor Of 2\n");
    for (int i = 1; i < 50; i *= 2)
    {
        printf("%d\n", i);
    }
    printf("%s", "**********************\n");
    printf("%s", "A For Loop That Never Runs!\n");
    for (int i = 0; i > 100; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}