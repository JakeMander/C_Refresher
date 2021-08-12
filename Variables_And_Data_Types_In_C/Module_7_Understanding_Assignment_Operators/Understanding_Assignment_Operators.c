#include <stdlib.h>
#include <stdio.h>

/*
    In this tutorial, we'll be looking at how to assign values to variables
    using a variety of approaches in C.
*/

void printOperands(int leftOperand, int rightOperand);

int main(void)
{

    /*
        C provides a number of convinient assignment operators that provide
        a shorthand means of performing an operation and assignment in a 
        single call. 

        Essentially, all of the basic arithmetic operators can be bundled 
        together with an assignment to save on the more verbose chain of
        operators required to perform an operation and assignment together.

        For example, let's say we have a variable x, and we want to add 7
        to it's current value then replace that value with the result of
        the addition, then typically we would do the following:

        int x = 10;
        x = x + 7;

        To save on typing, C allows us to do the following:

        x += 7; (x now equals 17)

        C provides the following assignment operators for assigning 
        values to variables:

            - Simple Assignment Operator (=)
                - Description: Simply assigns the right hand operand to the 
                  left hand variable 
                - Examples: 
                    - x = 1;
                    - x = y;
            
            - Add AND Assignment Operator (+=)
                - Description: Adds the right hand operand to the left hand 
                  operand. The result is then assigned to the left hand 
                  variable.
                - Examples: 
                    - x += 3;

                    Is the same as:
                    
                    - x = x + 3;
            
            - Subtract AND Assignment Operator (-=)
                - Description: Subtracts the right hand operand from the left hand 
                  operand. The result is then assigned to the left hand 
                  variable.
                - Examples: 
                    - x -= 3;

                    Is the same as:
                    
                    - x = x - 3;
            
            - Multiply AND Assignment Operator (*=)
                - Description: Multiplys the left hand operand by the right hand 
                  operand. The result is then assigned to the left hand 
                  variable.
                - Examples: 
                    - x *= 3;

                    Is the same as:
                    
                    - x = x * 3;

            - Divide AND Assignment Operator (/=)
                - Description: Divides the left hand operand by the right hand 
                  operand. The result is then assigned to the left hand 
                  variable.
                - Examples: 
                    - x /= 3;

                    Is the same as:
                    
                    - x = x / 3;

            - Modulo AND Assignment Operator (%=)
                - Description: Divides the left hand operand by the right hand 
                  operand and takes the remainder (returns 0 if no remainder). 
                  The remainder is then assigned to the left hand variable.
                - Examples: 
                    - x %= 3;

                    Is the same as:
                    
                    - x = x % 3;

        Let's look at some examples:
    */

   int leftOperand = 12;
   int rightOperand = 3;

   for (int i = 0; i < 5; i++)
   {
       printOperands(leftOperand, rightOperand);

       switch(i)
       {
            case 0:
                printf("Adding Operands! (%d + %d)\n", leftOperand, 
                rightOperand);
                printf("Left Operand Now Equals %d\n", 
                leftOperand += rightOperand);
                printf("***********************\n\n");
                break;
            
            case 1:
                printf("Subtracting Operands! (%d - %d)\n", leftOperand, 
                rightOperand);
                printf("Left Operand Now Equals %d\n", 
                leftOperand -= rightOperand);
                printf("***********************\n\n");
                break;

            case 2:
                printf("Multiplying Operands! (%d * %d)\n", leftOperand, 
                rightOperand);
                printf("Left Operand Now Equals %d\n", 
                leftOperand *= rightOperand);
                printf("***********************\n\n");
                break;
            
            case 3:
                printf("Dividing Operands! (%d / %d)\n", leftOperand, 
                rightOperand);
                printf("Left Operand Now Equals %d\n", 
                leftOperand /= rightOperand);
                printf("***********************\n\n");
                break;

            case 4:
                printf("Modulous Of Operands! (%d %% %d)\n", leftOperand, 
                rightOperand);
                printf("Left Operand Now Equals %d\n", 
                leftOperand %= rightOperand);
                printf("***********************\n\n");
                break;

            
            default:
                printf("Invalid Value\n");
       }
   }
   
    /*
        C also supports a number of bitwise assignment operators that perform
        the same operations explored in the previous bitwise operators 
        tutorial. These operators are:

            - Bitwise AND and Assignment Operator (&=)
                - Description: Applies a bitwise AND operation to the right 
                  and left hand operands to the left hand and assigns the
                  resulting bits to the left hand variable.
                - Examples: 
                    - x &= 3;

                    Is the same as:
                    
                    - x = x & 3;
            
            - Bitwise OR and Assignment Operator (|=)
                - Description: Applies a bitwise OR operation to the right and
                  left operands. Takes the result and assigns it to the 
                  variable on the left hand side of the operator.
                - Examples: 
                    - x |= 3;

                    Is the same as:
                    
                    - x = x | 3;
            
            - Bitwise XOR and Assignment Operator (^=)
                - Description: Applies a bitwise XOR operation (evaluates a bit
                  as 1 if ONLY ONE bit is set to 1) to the right and
                  left operands. Takes the result and assigns it to the 
                  variable on the left hand side of the operator.
                - Examples: 
                    - x ^= 3;

                    Is the same as:
                    
                    - x = x ^ 3;

            - Left Shift AND Assignment Operator (<<=)
                - Description: Shifts the left hand operand's bits to the left 
                  by the right hand operand. The result is then assigned to the
                  left hand variable.
                - Examples: 
                    - x <<= 2;

                    Is the same as:
                    
                    - x = x << 2;

            - Right Shift AND Assignment Operator (>>=)
                - Description: Shifts the left hand operand's bits to the right
                  by the right hand operand. The result is then assigned to the
                  left hand variable.
                - Examples: 
                    - x >>= 2;

                    Is the same as:
                    
                    - x = x >> 2;


    */
}

void printOperands(int leftOperand, int rightOperand)
{
   printf("Left Operand Is: %d\n", leftOperand);
   printf("Right Operand Is: %d\n", rightOperand);
}