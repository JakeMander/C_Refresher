/* The following program acts as an additional demo of the
if-else ladder and how it can be used in conjunction with
user input.
*/

#include <stdio.h>  /* For console IO */

int main(void) {
    printf("Please enter an integer number: ");
    int number1 = 0;
    scanf("%d", &number1);

    printf("Please enter another integer number: ");
    int number2 = 0;
    scanf("%d", &number2);

    if (number1 > number2) 
    {
        printf("%d is greater than %d\n", number1, number2);
    }

    else if (number1 < number2) 
    {
        printf("%d is less than %d\n", number1, number2);
    }

    else 
    {
        printf("%d is equal to %d\n", number1, number2);
    }
    return 0;
}