#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
    We now have a firm uderstanding of the core operators offered by C. Now
    let's have a look at some of the miscellaneous operators that C offers
    for various general purpose use cases.
*/

void printOperands(int leftOperand, int rightOperand);

int main(void)
{
    /*
        C offers the following as miscellaneous operators:

            -   Size Of (sizeof):
                -   Used in instances where we want to manage memory and gauge
                    how much space our variables are taking up. As we've seen 
                    before, we can use sizeof to calculate the size of a given
                    type or variable in bytes.

                    Can also be used during bitwise operations to check how 
                    many bits/bytes you have to play with.

                - For example:
    */

    long int longInt = 22;
    char character = 'A';
    double doubleVariable = 234567;

    printf("Size Of long int: %d Bytes\n", sizeof(longInt));
    printf("Size Of char: %d Bytes\n", sizeof(character));
    printf("Size Of double: %d Bytes\n", sizeof(doubleVariable));

    /*
        We also have the ampersand operator (&) which we have also encountered
        before!

        As we know, this operator can be used to return the address of a 
        variable which allows us to retrieve pointers to locations in 
        memory which we can the manipulate by reference.
    */
    unsigned int testVariableOne = 2234;
    printf("The memory address of testVariableOne Is: %x\n", &testVariableOne);

   /*
        As we also know, C supports the Star operator (*) which can do two 
        main operations depending on the context:

            - Create a pointer to a variable of a defined type (handles
              any memory value returned by a call to the & operator).
            - Dereference a value pointed to by a pointer. Remember, a
              pointer points to an address not a stored value! To get
              the value, we must explicitly dereference the pointer!
   */

    //  When * is used before a variable identifier during a variable 
    //  decleration, the variable type becomes a pointer and will 
    //  be assigned a memory block big enough to store a memory 
    //  address big enough to reference the defined type.
    unsigned int * pointerToTestVariableOne = &testVariableOne;

    //  When * is used before a variable identifier in a call to a variable, 
    //  a dereference occurs (i.e. the value at the pointed memory address
    //  is returned).
    unsigned int dereferenceTestVariableOnePointer = *pointerToTestVariableOne;

    printf("\nValue of pointerToTestVariableOne: %x\n", pointerToTestVariableOne);
    printf("\nDereferenced Value of pointerToTestVariableOne: %d\n", dereferenceTestVariableOnePointer);

    /*
        Finally, we have the ternary conditional operator (? and :) which we
        can use in conjunction with a provided conditional statement. 

        As we've seen before, the ternary operator can be used in the following 
        manner:

        condition ? expression to return if true : expression to return if 
                                                   condition is false.

        You can't use these to call big, complex statements in the 
        condtions, but you can return values or call functions! Functions
        are expressions! 

        These provide a shorthand means of defining inline conditional logic
        like so:
    */

    int ternaryValueToEvaluate = -22;

    // Demo 1: Using ternary operators to call functions.
    (ternaryValueToEvaluate < 0) ? printf("Value Is Less Than 0!\n") : printf("Value Is Greater Than 0!\n");

    // Demo 2: Using ternary operators to return values.
    int returnedTernaryValue = (ternaryValueToEvaluate < 0) ? true : false;
    printf("Returned Ternary Value: %d\n", returnedTernaryValue);
}