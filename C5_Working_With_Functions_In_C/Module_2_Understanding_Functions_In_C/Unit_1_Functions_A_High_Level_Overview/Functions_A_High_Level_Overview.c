#include <stdlib.h>
#include <stdio.h>
/*
    In this introduction, we'll learn what functions are and why we use them.

    Functions have their origins based in mathematics. 
    
    However, in the world of computer science, a function is typically an
    'abstraction' that reecieves an input (or inputs) and provides an output.

    What do we mean by abstraction? It typically means building something
    to hide away the inner workings of something. Programmers like to work
    in ideas rather than specific details! 

    If we want to open a file, it's much easier for us to hide away the file
    opening functionality inside a "ReadFile()" function than exposing another
    programmer to all the code involved in reading from a file!

    The simplest model of a function is as follows:

    input --> processing/transformation --> output

    In terms of a process, functions involved:

    1. First, defining the inputs. These can be of an concievable type (i.e.
    integer, character or even other functions). Once we know what inputs we
    are going to pass to a particular operation, we can then create a function!

    2. Second we define the function itself. This typically involves 
    implementing some work, processing or transformation that needs to be done 
    to produce some form of output.

    3. Output is the entity that is produced from the operations of a 
    function. Output is optional! Sometimes a function changes things but
    doesn't output anything! 

    It's worth noting input and output is optional! We don't have to pass in
    values for a function to operate on, nor do we always have to expect that
    our funtion will produce an output value for us to use.

    In simple terms, a function is something that bundles operations/work 
    together into a single, callable block. They are an incredibly vital 
    component to almost all programming languages!

    In the C language, there are two primary groups of functions:

    - User defined functions: Functions explixitly defined by a programmer.
      That could be you, or another programmer who has written functions that
      have been bundled into a third party library.

    - The C standard library functions: Library functions are functions included
    inside the "C Standard Library". This is essentially a number of header files
    that have pre-defined functions built by the original authors/current 
    curators of the C language. 
    
    These C functions provide the C language with a basic set of functionality
    that comes bundled with every C compiler. In essence, the C library is the
    backbone of the C language! 
    
    Want to write a file? Dennis Ritchie wrote a function for you to use that
    will do that for you back in the 70's so you didn't have to worry about
    reading from the disk or using the operating system to find files!

    Want to write a string to the console? You don't have to write the code to
    do that! It comes pre-packaged with C in the form of printf or one of the
    many other functions that handle input/output! Typically, you'll find all 
    these in the stdio.h or string.h libraries that Dennis Ritchie wrote for
    the C language!

    Composing these basic set of functions provided by the C language allows 
    you to buld powerful C programs without the hassle of writing all the 
    code for yourself!

    So why should we use functions:

        1. Functions make code modular - You can split out parts of your system
        making your program obey a concept known as "Seperation of Concerns".

        It's a lot easier to test smaller, logically grouped blocks of code 
        than a single file containing one long continuous steam of code!

        2. Reusable Code - In programming, you should avoid repeating the same
        code over and over again! Programmers are lazy creatures! We don't like
        typing the same stuff over and over again, nor do we like having to search
        through thousands of files to fix the same bug that has been rewritten in
        muliple sections throughout our code.

        Functions allow you to bundle a single operation/behaviour into a single
        callable function. That means, you can simply call the function whenever
        you need it instead of writing out the same code over and over again
        in the places you need it.

        In addition, if your code has a bug, it's isolated to a single location!
        A problem with your function's code is a lot easier to fix when it's 
        contained inside a single location! 

        Remember! COPYING AND PASTING CODE IS A BIG NO-NO! It's just more work
        for you to maintain further down the line!

        Repeating the same code over and over is a good indication that the 
        code you've written should be placed inside a function!

        3. Maintainability - Smaller blocks of repeatable code that deal with
        a single concern are much easier to read and fix than huge blocks of 
        code that deal with lots of different concerns! 

        Functions help break down your code into readable, manageable chunks!

        They key to good programming is simplicity! It's a lot easier to break
        a problem down into small, easy to understand steps and behaviours!

        In programming, functions are vital in achieving this!

        4. Functions make code easy to test - Isolating behaviour into
        small blocks of code make testing much easier! It's a lot easier to 
        provide simulated input and test that the code you have written works
        when it is isolated into a small function isolated from the changes
        imposed by other code thant to test a single block of thousands of 
        lines of code that are affected by multiple different factors. See
        test driven development for more details on this.
*/

int main(int argc, char *argv)
{
    return 0;
}