#include <stdlib.h>
#include <stdio.h>


//  Function to provide a variable set of operators to be
//  called based on user input.
int ArithmeticOperation(int operandOne, int operandTwo, char operator);
void PostfixPrefixDemo(void);
/*
    Let's have a look at the arithmeric operators in C and how we can use them
    to perform various mathematical operations on values. 
*/
int main(void) 
{
    const char operators[] = {'+', '-', '*', '/', '%'};
    const int operandOne = 12;
    const int operandTwo = 9;
    /*
        C supports the following arithmetic operators:

        Addition (+):
            - Add two operands together.

        Subtraction (-):
            - Subtract two operands from each other.

        Multiplication (*):
            - Multiply two operands together.

        Division (/):
            -   Divides two operands.

        Modulus (%):
            - Performs a division between two operands and takes the 
              remainder. If no remainder, returned value is 0.
        
    */

    int arraySize = sizeof(operators);

    //  Loop over our operators and run an operation based on two
    //  input values.
    for (int i = 0; i < arraySize; i++)
        printf("Result From Operator (%c) Is: %d\n", operators[i], ArithmeticOperation(operandOne, operandTwo, operators[i]));
    puts("");
    PostfixPrefixDemo();
    puts("");
    return 0;

    /*
        Two important arithmetic operators are the increment and decrement operators. 

        These are as follows:
            - Increment ([value]++ OR ++[value]).
            - Decrement ([value]-- OR --[value]).

        Increment:
            - Increments the value it is applied to by one.
            - The increment operator cannot be used on constant values.
            - There are two variants of the increment operator which vary the
              order in which the addition and assignment take place:
                - Prefix(++x): Increment the value stored at X first AND 
                  THEN apply x to the assigned variable (if any assignment 
                  occurs).
                - Postfix(x++): Assign the value stored at x to the variable
                  (if any assignment takes place) and then increment the value
                  stored at x.

        Decrement:
            - Decrement the variable by one.
            - Decrement cannot be used on constant values.
            - Also has prefix and postfix variants.

        Take care with prefix and postfix operators! They can affect when
        conditional logic evaluates to true and cause a loop to iterate 
        over one more or one less iteration than is required if the wrong
        one is chosen!

        See below for more details!  
    */
}

//  Demo to show various arithmetic operators available in C.
int ArithmeticOperation(int operandOne, int operandTwo, char operator)
{
    int result = 0;
    switch (operator)
    {
        case '+':
            result = operandOne + operandTwo;
            break;

        case '-':
            result = operandOne - operandTwo;
            break;
        case '*':
            result = operandOne * operandTwo;
            break;
        case '/':
            result = operandOne / operandTwo;
            break;
        case '%':
            result = operandOne % operandTwo;
            break;
        
        default:
            printf("An invalid operator was provided\n");
            break;
    }
    return result;
}

//  Demo to show postfix and prefix examples.
void PostfixPrefixDemo(void)
{
    int x = 5;

    printf("X is: %d\n", x);

    //  Values should be different. X is decremented, and then assigned to Y.
    int y = --x;
    printf("Prefix Decrement Y: %d \n", y);
    printf("X Value Is: %d \n", x);


    //  Values Should Still be Different. X is assigned to Y before being 
    //  incremented back to it's original value!
    y = x++;
    printf("Postfix Increment Y: %d\n", y);
    printf("X Value Is: %d\n", x);

    //  Take care with postfix and prefix operators! They can affect
    //  conditional logic if used incorrectly.
    printf("Value of X Before if statement: %d\n", x);

    if(--x == 4)
    {
        printf("The value of X was decreased before evaluating the if condition \n");
    }
    printf("Value of X after if: %d\n", x);

    printf("Value of Y Before If Statement: %d\n", y);

    //  If statement does not trigger. Y is assigned before the increment so the conditional
    //  evaluation recieves 4 as the value for y. Therefore evaluates to false!
    if (y++ == 5)
    {
        printf("The Value of X Was INcreased After Evaluating The If Condition.\n");
    }

    printf("Value of Y After If Statement: %d\n", y);

}