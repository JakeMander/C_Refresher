#include <stdio.h>

int main(void)
{
    //  Variable decleration - Storage for user input - Specify the type and the
    //  name of the variable. Optionally, an initial value can be provided.
    float temperatureF = 42.3;

    /* Prompt the user to enter a temperature value in Farenheit. */
    printf("Please Enter A Temperature In Farenheit:\n");

    /*  Printf handles output, Scanf handles input. 
        Scanf takes two arguments, a format specifier which tells C
        what type the input should be, and the memory address of a 
        variable where the input is to be stored, which is extracted 
        through use of the ampersand '&'. Why do we need this?
        Because the second argument of the scanf function is a pointer!

        Pointers point to memory addresses! Therefore pointers == memory addresses.

        Why do we need to pass in memory addresses to functions? Because then we have
        direct access to that value in memory! If we change it inside the function,
        it changes inside the whole program! We can pass the variable name, but in doing so
        we just pass in a copy of the value that is stored at the variable's memory location.

        In the below example, we expect input to be a floating point value, and
        will store this input at the memory address where he "temperatureF" 
        variable is stored.
    */
    scanf("%f", &temperatureF);

    //  Notice the use of "f". This specifies our values should be "floats".
    //  Brackets are used to set operation precedence. Think BODMAS! We want
    //  Our subtraction to occur before the multiplication!
    float temperatureC = (temperatureF - 32.0f) * 5.0f / 9.0f;

    //  Notice the use of the format specifier in prinf (%f). Here we are saying, insert
    //  the first argument passed in to the function here and, if you can, format it as a 
    //  float. If you can't throw an error!
    printf("\nThe Corresponding Temperature In Celcius Is %f C. \n", temperatureC);
    return 0;
}