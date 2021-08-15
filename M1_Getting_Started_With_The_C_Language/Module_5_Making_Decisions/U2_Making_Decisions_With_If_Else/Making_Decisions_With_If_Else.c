/* In our program's we'll need to make decisions. One of the easiest ways
to do this in C is to use the "if statement". Here we provide a condition
that the run time evaluates. If the condition is satisfied and evaluates
to true, then the block of code associated with the statement is 
executed. If not, then the block is skipped.

The basic syntax is as follows:
if (expression) 
{
    // statement to be executed if expression is true. (the body)
}

// code execution resumes here

If you have a single lined statement to execute after the if statement.
The curly braces ca be omitted. For example:

if (variable == true)
    printf("It's true!")

Some coding styles do mandate that curly braces should ALWAYS be used (such as 1TBS)
so use at your own discresion.

Just remember that, if your single lined if statement grows in future, you'll need
to add the curly braces to stop bugs!

In addition to if statements, we have if-else statements! These dictate that, if the 
boolean condition in the if statement is not satisfied, then the code contained in
the body of the else statement should be executed instead!

It looks something like this:

if(expression) {
    // statements to execute if above expression is satisfied.
}

else {
    // statements to be executed if the if statement evaluates
    to false.
}
*/

#include <stdio.h>

int main(void) {
    //  No code here. Example is theory. 
    printf("Hello World");
}