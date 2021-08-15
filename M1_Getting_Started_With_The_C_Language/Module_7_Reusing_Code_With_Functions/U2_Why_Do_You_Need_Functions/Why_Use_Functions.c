/*
    In one of our previous examples, we built a temperature conversion
    program that converted farenheit to celcius. This is all good is we
    want to build a single program that runs once and runs the conversion
    behaviour once.

    But what if we want to build a bigger app where the conversion forms
    part of a bigger overall system like a weather app?

    Programmers are simple creatures who like to make life easy for 
    themselves! We don't like rewriting code!

    For example, if we need to run a conversion in our app in multiple
    places, we really don't want to have to write the same code over
    and over again in different parts of our application! This takes
    time, and leads to unmaintainble code.

    What happens when we want to change the behaviour of the conversion?
    Well then we have to trawl through our app, looking for every
    part of our code where the conversion appears and change the code
    so it's all the same! This is not a very agile or efficient approach
    to programming!

    Instead, we use functions to package particular behaviour into callable
    packages! These functions are what we've been using all along!

    Think of them as callable units of work!

    Printf for example is a function that was written as part of the C
    standard library! We've called it multiple times across our 
    programs! The input has been different, but the behaviour has always
    been the same! It writes to the console! 

    This is the power of functions! They can be grouped into libraries
    to provide groups of common functionality that can easilly be 
    imported in your programs.

    This is very powerful! It has meant we can have easilly recallable 
    functionality that we can place whereever we need to write something
    to the console! 

    As a programmer there are a couple of things to bear in mind:
    1.  If you notice behaviour that you use more than once in 
        your C files, turn it into a function! Always remember the
        DRY programming principle! Don't repeat yourself! This
        just makes your code so much easier to read and maintain!

    2.  You don't always need to write your own functions! Always
        check the standard library for a function that's already
        been written as part of it! There's a good chance the 
        tools are already there for you to use! 

    3.  It is good practice to go back over your code and ask yourself
        "Is my code neatly comparmentalised into reusable functions".
        These functions should serve only one purpose. They should
        change ONE thing, or output ONE thing or oversee the running
        of ONE thing. This is the SRP (Single responsibility principle).

        There is no hard or fast rule, and common sense should be applied
        with this rule. It can sometimes be difficult to identify these 
        responsibilities and it's not always clear what a responsibility is. 
        This however becomes easier with time and practice. 

        We'll master the basics first!

        Below we'll see our previous temperature conversion app.

        In the next tutorial we'll set about updating it so that
        our conversion behaviour is wrapped in functions

    
*/

#include <stdio.h> // Gives us printf

int main(void) 
{
    printf("Please enter a temperature value in Farenheit: ");

    float temperatureFarenheit;
    scanf("%f", &temperatureFarenheit);

    float temperatureCelcius = (temperatureFarenheit - 32.0) * 5.0 / 9.0;

    printf("The corresponding temperature in Celcius is %.2f C.\n", temperatureCelcius);

    return 0;
}