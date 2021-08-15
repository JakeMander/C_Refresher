/*  Let's take have another look at the main!
    
    So far, we've learned that main is very imporant component
    in a C program!

    It's the starting point of the appliation and is the first set 
    of code that get's called when a C executable is run!

    But now we know about functions, we may have noticed a couple of
    it's features!

    For a start, main is a function we've been implementing all along
    in each of our programs!

    This is called by the OS each time we run a C program.

    void means our main function takes no parameters! We can however change
    this and pass in parameters to our program by calling the excutable 
    via the command line! Don't let this confuse you at the moment though!

    Now look at the 'return 0' statement. This return simply tells the OS
    that everything ran and completed fine. This is the program exit code!

    0 means the program termiated correctly, anything other than 0 means an 
    error occured!

    This is why main returns an integer value! We're actual;y returning a
    number back to the OS to tell it that our program closed in a particular
    state!

    Alternatively, if the stdlib.h library is included, the following integer
    constants can be returned instead:
        - EXIT_SUCCESS
        - EXIT_FAILURE

    And that's it! now we know a bit more about main!
*/

#include <stdio.h> 

int main(void) 
{
    return 0
}