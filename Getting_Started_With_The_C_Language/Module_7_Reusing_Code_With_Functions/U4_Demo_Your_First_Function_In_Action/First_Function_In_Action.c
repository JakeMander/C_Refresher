/*  In this example we'll demonstrate our previous temperature conversion
    in another example!

    Here, we'll use our function to print out a temperature conversion table!
*/

#include <stdio.h> // Gives us printf/puts

/*
    It's always good prctice to comment your functions! It reminds you
    and other developers what the purpose of it is! Try to avoid examplaining
    what it does! Moreso explain why it's there and how it fits in regarding
    the context of the program!

    A function to be used to convert and input from celcius to farenheit.
    Allows implementation of simple C to F temperature conversion within
    the program.
*/
float FarenheitToCelcius(float temperatureInFarenheit)
{
     // Convert the temperature value from F to C
    float temperatureCelcius = (temperatureInFarenheit - 32.0) * 5.0 / 9.0;

    // Return the converted value
    return temperatureCelcius;
}

int main(void) 
{
    puts("Temperature Conversion Table");
    puts("============================");

    //  For each farenheit temperature below 100.0, in steps of 5 degress farenheit, calculate
    //  the equivalent temperature in Celcius. 
    for (float farenheitTemperature = 10.0; farenheitTemperature < 100.0; farenheitTemperature += 5.0 )
    {
        float temperatureInCelcius = FarenheitToCelcius(farenheitTemperature);
        //  Print values to 2 decimal places. Celcius value has a width of 6 
        //  to pad out the table.
        printf("%.2f F      |      %6.2f C \n\n", farenheitTemperature, temperatureInCelcius);
    }

    // Print the table footer after all our conversion values have been output
    puts("----------------------------");

    return 0;
}