#include <stdlib.h>

/*
    In this section we'll look at operators and how they can be leveraged to
    act on data and transform it in C.

    In essence, operators are symbols that represent the operations you want
    to perform on variables. They operate on and manipulate data!

    For example, let's look at the first example in main.

    Here we are performing a multitude of operations with our data. 

    In our first example, we perform an arithmetic operation (addition) and
    an assignment operation ('='). 

    In the second example, we again, perform an arthimeric operation (subtraction)
    and an assignment operation ('='). The arthimetic operator has changed from the
    previous example. 

    C has the following operator groups:

    -   Arithemtic Operators: Performs mathematical based operations such as addition,
        subtraction, division, multiplication etc... (Think BODMAS!).
    
    -   Assignment Operators: Used to assign values to variables! ('=').

    -   Conditional Operator: Used to construc ternary statements using the '?'
        and ':' operators.

    -   Bitwise Operators: Used to perform operations on a variable's bits (i.e. bit-shifts).
        Can be useful for high performance operations such as multiplication and division
        on the bit level!

    -   Miscellaneous Operators: Perform various operations (non-specific)

    -   Relational Operators: Used to compare two values together. Think of operations
        such as:
            - Greater Than (>).
            - Less Than (<).
            - Greater than or Equal To (>=).
            - Less than or Equal To (<=).
            - Equal to (==).
            - Not Equal to (!=).
    
    -   Logical Operators: Used to help construct conditional expressions that
        evaluate to either true or false and which allow the program to vary
        how it executes based on an outcome. Think of the '&&', '||'
        and '!' operators we've used so far!

*/
int main(void) 
{
    int x = 20;
    int y = 10;

    int z = x + y;
    int w = x - y;

    return 0;
}