/*
    In the below example, we've moved our temperature conversion
    functionality into a function! 

    A function is made up of two main components:
    
    - The function interface (or prototype) - That's the top line of
    code that defines the return type, function name, and the 
    arguments and their types the function expects.
    - The function body - That's between the curly braces. This is
    where our functionality goes:

    //  Function returns int        //  The function Name   //  Function parameters
    int                             MyFunction              (int parameter1, float parameter2, char parameter3)

    Prototypes are really important in C! They tell the compiler
    what functions are going to be in our program, and give it
    a rough idea of what they require and what they do!

    Sometimes the compiler will complain if we call a function 
    and the compiler can't find a matching prototype! This is 
    because the compiler relies on these to match up function
    behaviour to function calls, as well as planning ahead as
    to what functions are available in the program!

    Note that the names of the parameters are not part of the 
    function protype! We just need to know:
        - What type of varaible a function returns.
        - What the name of the function is.
        - How many parameters our function expects, and what type
          each parameter should be.  

    Ultimately, variables can be assigned to function calls so long
    as the function returns a value. As C is a "strongly typed
    language", the C compiler needs to know what value types variables 
    are storing, and additonally, what types of value functions return if
    they return a value at all.

    What is meant by this is that some variables do not return values.
    Instead they sometimes change (mutate) other parts of your program
    such as editing variables, or implement behaviour such as 
    interacting with an API to draw something to the screen. These
    are identified by a "void" type... When you see this, the 
    function does something, but doesn't return a value!
    
    We define the return type as the first component of the function.

    Secondly, we need to provide an identifier so we can actually
    call our function in code. This is what the second component is
    for. Bear in mind that The function name should ideally be written 
    in Pascal case (i.e. every word has a capital letter). 

    Alternatively, "Snake Case" (i.e. my_function) is another accepted
    naming convention.

    Finally, C allows us to pass values into our functions so we can 
    vary our output by passing different values to our functions
    behaviour. These are parameters and form the third and final
    component of the function prototype. Multiple parameters of 
    multiple different types can be provided!

    Note that the variables we pass into a function will sometimes be called
    two different things:
    - When called "parameters", we refer to the variables that are passed in
    during the decleration of our function and it's behaviour.
    - When called "arguments", we refer to the values we pass in during
    a function call.

    Ultimately, functions are said to have a "signature". This is defined
    by the type returned by the function, and the types of, 
    and number of parameters we pass in.

    Finally, the function body is where the behaviour of our function goes.
    When the function is called, the body contains the sequence of code
    that gets executed.

    If the function is not void, it should return a value that matches
    the defined return type otherwise the C compiler will complain!

    Let's look at the example below and compare it to our non-function
    program. Notice how we've stripped our our conversion behaviour
    and bundled it into a function. We'll call this in our next example:

    One thing to note about our new temperatureCelcius variable that exists in
    the function. Remember how we touched on local and global scope. Well 
    temperatueCelcius has local scope in relation to the function. Therefore,
    it will only live for as long as the function. We only have access to
    it inside of our function! We cannot get it's value from outside!
*/

#include <stdio.h> // Gives us printf

/*  A few things on declaring a function. It has to be done outside
    of the main() function, and the decleration should be done at 
    the top! The C compiler reads from top to bottom and if you 
    call a function before it hits it's prototype, then an error
    gets thrown! 

    There are a few different ways to declare a function in C (header
    files, stick the prototype decleration at the top of the file, 
    declare the full function below main etc.), but we'll
    stick with this simple approach to start with!
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
    printf("Please enter a temperature value in Farenheit: ");

    float temperatureFarenheit;
    scanf("%f", &temperatureFarenheit);

    //  We can pass functions as parameters into other functions! 
    //  The return value of our new function gets passed to printf which
    //  is how we see it appear in the console!
    printf("The corresponding temperature in Celcius is %.2f C.\n", FarenheitToCelcius(temperatureFarenheit));

    return 0;
}