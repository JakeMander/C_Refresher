/* To write expressions for our if statements to evaluate, we
can use relational and logical operators. These keywords act as
a means for us to compare values and variables and detrmine the
criteria to be met for our if statement to pass and run it's
body of code. 

Relational operators are used to compare two values. C implements
the following:

- "==", Equality.
- "!=", Inequality.
- "<", Less Than (But Not Equal To).
- ">", Greater Than (But Not Equal To).
- "<=", Less than or equal to.
- ">=", greater than or equal to.

C also use logical operators to chain multiple expressions into a
single larger boolean expression. C uses the following:

- "&&", And (Both LHS and RHS must evaluate to true to output true).
- "||", Or (One of the LHS and RHS must evaluate to true to output true).
- "!" Not, The inverse of the expression must be returned to evaluate true. 

The following file demonstrates this with the following examples
of relational and logical operators.
*/

#include <stdio.h>

int main(void) { 
    int number = 64;
    int numberTwo = 72;

    //  Equality operator. Evaluates to true if LHS is equal to RHS.
    if (number == 64)
    {
        printf("Number %d is equal to 64!\n", number);
    }

    if (number == 42)
    {
        printf("This is the answer to life, the universe and everything!\n");
    }

    //  Inequality operator. Evaluates to true if LHS is NOT EQUAL to the RHS.
    if (number != numberTwo)
    {
        printf("%d Is Not Equal To %d!\n", number, numberTwo);
    }

    //  Greater Than. Evaluates to true is LHS is greater than (AND NOT EQUAL TO) the RHS.
    if (number > numberTwo)
    {
        printf("%d Is Greater Than %d!\n", number, numberTwo);
    }

    //  Less Than. Evaluates to true is LHS is less than (AND NOT EQUAL TO) the RHS.
    if (number < numberTwo)
    {
        printf("%d Is Less Than %d!\n", number, numberTwo);
    }

    //  Greater Than Or Equal To. Evaluates to true is LHS is greater than
    //  or equal to the RHS.
    if (number >= 64)
    {
        printf("%d Is Greater Than Or Equal To %d\n", number, 64);
    }

    if (91 >= 64)
    {
        printf("%d Is Greater Than Or Equal To %d\n", 91, 64);
    }

    //  Less Than Or Equal To. Evaluates to true is LHS is less than
    //  or equal to the RHS.
    if (numberTwo <= 100)
    {
        printf("%d Is Less Than Or Equal To %d\n", numberTwo, 100);
    }

    if (100 >= 100)
    {
        printf("%d Is Less Than Or Equal To %d\n", 100, 100);
    }

    // AND Operator. Number must be BOTH greater than 21 and less than 100
    if (number > 21 && number < 100) 
    {
        printf("%d is greater than %d AND less than %d\n", number, 21, 100);
    }

    //  OR Operator. Number must EITHER be greater than 70 OR less than 100.
    if (number > 70 || number < 100) 
    {
        printf("%d is EITHER greater than %d OR less than %d\n", number, 70, 100);
    }

    //  NOT. Number must NOT be greater than 70 (Do the inverse operation!)
    if (!(number > 70))
    {
        printf("%d Is NOT Greater Than 70\n", number);
    }
}