/*
    Notes:
    -   Use "int" to declare a variable type of integer. 
    -   Int's can be signed (positive/negative) or unsigned.
        -   You'll typically use unsigned values when handling low level raw data.
            The specifier for this is %u.
        -   You may also use %x to output an integer as a hexadecimal value. 
    -   This list is not conclusive. There are more specifiers to be found in the C
        language.
*/
#include <stdio.h>
int main(void)
{
    int numberOfUsers = 15;
    int temperatureOfNorthPole = -42;
    int temperatureOfBahamas = 32;

    //  %d is typically used as the format specifier for printing standard form
    //  integers.
    printf("The Number Of Users Is %d\n", numberOfUsers);

    //  Undefined behviour, negative sign takes one of the higher bits and causes a massively
    //  inflated postive value because the unsigned format specifier is expecting a number.
    printf("The Temperature Of The North Pole Is %u Degrees Celcius\n", temperatureOfNorthPole);

    //  Will run correctly.
    printf("The Temperature Of The Bahamas Is %u Degrees Celcius\n", temperatureOfBahamas);
    printf("The Number Of Users Is %x\n", numberOfUsers);
    return 0;
}