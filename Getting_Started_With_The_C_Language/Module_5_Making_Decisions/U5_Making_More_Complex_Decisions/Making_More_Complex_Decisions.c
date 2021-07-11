/* In most programming languages we can make decisons
between mutliple outcomes using something we'll call
the "if-else ladder". Here, we can iterate through a
set of conditions, evaluting against each one 
until we find a condition that evaluates
to true and executes it's contained block of code.

We can chain these evaluations together by starting with
an "if" statement, and following this with subsequent 
"if-else" statement's which are evaluated in sequence
until one evaluates to true. Once this happens,
we exit the ladder and carry on executing the 
code that appears below it.

Note that is different behaviour from a simple list
of "if" statements. With that, we could possibly 
trigger multiple conditions, executing code contained
within multiple condition bodies assuming the values we
passed in satisfied multiple conditions. With a set of
"if-else" statements, only a single condition can be
evaluated.

With the ladder, we also attatch one final "else" statement
to catch instances where none of our other conditions 
evaluate to true. This acts as a sort of failsafe operation.
If our input/values are outliers that aren't handled by any
of our other conditional evaluations, then do something
to handle this instance!
*/

#include <stdio.h>  /* For console IO */
#include <string.h> /* For strcmp - Remember, we can't use = to copy strings! */

int main(void) {
    int value = 10;

    printf("If Chain Example!:\n");
    if (value % 2 == 0)
    {
        printf("%d Is Even!\n", value);
    }

    if (value >= 5) 
    {
        printf("%d Is Greater Than Or Equal To Five!\n", value);
    }

    if (value <= 20)
    {
        printf("%d Is Less Than Or Equal To 20\n", value);
    }
    printf("End Of The Chain!\n");
    printf("*************************************\n");

    printf("If Else Ladder Example 1!:\n");

    if (value % 2 != 0)
    {
        printf("%d Is Odd\n", value);
    }

    else if (value > 15)
    {
        printf("%d Is Greater Than 15\n", value);
    }

    else
    {
        printf("%d Is A Weird Number!\n", value);
    }
    printf("End Of The Ladder!\n");
    printf("*************************************\n");

    printf("If Else Ladder Example 2!:\n");

    if (value % 2 != 0)
    {
        printf("%d Is Odd\n", value);
    }

    else if (value >= 8)
    {
        printf("%d Is Greater Than 15\n", value);
    }
    //  Won't get hit! Above if statement catches first and then
    //  bypasses the remainder of the ladder!
    else if (value <= 20)
    {
        printf("%d Is Less Than 20\n", value);
    }

    else
    {
        printf("%d Is A Weird Number!\n", value);
    }
    printf("End Of The Ladder!\n");
    printf("*************************************\n");
    return 0;
}