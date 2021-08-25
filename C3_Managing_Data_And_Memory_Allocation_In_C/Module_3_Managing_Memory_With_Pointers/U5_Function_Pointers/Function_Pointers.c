#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

/*
    In this module, we'll be looking at "Function Pointers".

    But before we start, let's begin with a definition:

    As we know, pointers are simply variables that contain a memory address.

    If we go one step further, we'll find function pointers are a specific type
    of pointer that contain the beginning address of a function stored in
    memory.

    If we know the starting address of a function, then we can use this to call
    it!

    But why would we want to call a function via a pointer instead of a standard
    function call? Well there are numerous different reasons for this:

        - Function pointers allow us to call functions dynamically at runtime!
          That means we can let the user define what functions are called based
          on user input at runtime rather than relying on declaring multiple
          static function calls in our code. In doing so, we can make C 
          programs flexible and able to function on various different 
          systems and environments.

        - Function pointers are great for asynchronous code (i.e. code that
          is executed simultanesouly to the main thread and which doesn't 
          block it's execution - if you've not covered asynchronous 
          programming, don't worry about it too much yet, or altenatively
          have a read about it here:
            
          https://docs.microsoft.com/en-us/archive/msdn-magazine/2011/october/asynchronous-programming-easier-asynchronous-programming-with-the-new-visual-studio-async-ctp)

          They allow us to pass functions around to other functions as 
          parameters, thus allowing us to set up functions in a way
          that call these functions ONLY when an event occurs, or after an
          asynchronous function completes it's execution. These are known 
          as callbacks (i.e. they are initalized but only called back
          when something finishes it's execution or raises an event!) 
          and function pointers are key to this concept.

        - Function pointers are also useful in abstracting concepts away from 
          hardware and the user. For example, you may be writing an open source
          library that you want to share with users, and you may want to allow
          them to write their own functions that will be called when certain 
          events are handled or when certain asynchronous actions are completed.

          By using pointers, you can explicitly tell the C program that 
          particular functions will be called, at certain points in code, but
          defer specifying what functions get called until another programmer
          imports your library and wires it up to their own custom code and
          functions.

    The syntax for function pointers can be seen in example 1.
*/

typedef struct Person
{
    char* name;
    int age;
    void (*greeting)();
} Person;



int Multiply(int a, int b);
void SayEnglishGreeting();
void SaySpanishGreeting();

int main(int argc, char *argv[])
{
    /*
        Example 1
        First off we need to declare the pointer that will point to our 
        function. It is here where we define the signature (i.e. what
        return type and parameter types that a function must have in
        order for the pointer to be able to point to it - this is to
        ensure a function pointer consistently returns the same type
        and expects the same type amd number of user provided arguments)

        There are three components to this:
            1. First off, the return type the function must have.
               In the below example, our function pointer can be assigned
               to a function as long as it returns an int.

            2. IN BRACKETS, a star to indicate the variable is a pointer
               followed by the variable name the pointer will be called by.
               In the below example, we define our variable as a function
               pointer of name 'funcPtr'.

            3. Finally, IN BRACKETS, the types of argument that must be passed
               in to a function in order for a function pointer to be assigned
               to a function. In our example below, 'funcPtr' can be assigned
               to any function that takes in TWO arguments with:

                - The first argument being a variable of type int.
                - The second argument also being a variable of type int.

        Here we have defined a signature which the C compiler will use in order
        to determine which functions are allowed to be pointer to by this
        pointer.
    */
    printf("Example 1\n");
    printf("********************\n");
    int (*funcPtr)(int, int);

    /*
        With the function pointer declared, we now need to define it by 
        pointing it to a function. We can do this by using the ampersand
        operator to assign the memory address of a function to our
        function pointer.

        At this stage, we are essentially assigning the starting memory
        address of 'multiply' to the funcPtr variable. 
    */
    funcPtr = &Multiply;

    /*  
        We can call the function pointer simply by calling the pointer name
        and passing in the arguments specified in the signature of the function
        pointer.
    */
    int result = funcPtr(5, 7);
    printf("Result Is: %d\n", result);

    /*
        Let's now take a look at a function pointer demo!

        Here we'll take a look at how function pointer's can be used alongside
        structures. This is a common use cases for function pointers in C!

        We'll also look at some dynamic code which allows us to determine 
        function calls at runtime. 

        Note, you will need to run this program from the command line and pass 
        in an argument for the demo to work!

    */

    printf("\nDemo\n");
    printf("********************\n"); 

    //  Declare our function pointer.
    void (*greeting)();

    /*
        Check the number of arguments passed in from the command line.

        We are going to translate a greeting based on the recieved input from
        the command line. If the user provides "spanish" as a command line
        argument, we will output a spanish greeting. Otherwise, output a 
        greeting in english.
    */ 
    if (argc > 1)
    {
        printf("Argument Count Is: %d - Argument Is %s\n", argc, argv[1]);
        greeting = !strcmp("spanish", argv[1]) ? &SaySpanishGreeting : &SayEnglishGreeting;
    }

    else
    {
        printf("Please Pass a 'Greeting' Argument!\n");
        return 1;
    }

    /*  
        Pass a copy of the memory address that our local function pointer is
        pointing to to our new 'Person' struct, thus dynamically initalizing 
        Fred to speak whatever language was specified in the CMD line arguments
    */
    Person fred = { "Fred", 25, greeting};
    fred.greeting();
    return 0;
}

//  A funtion to be pointed to by a function pointer.
int Multiply(int a, int b)
{
    return a * b;
}

void SaySpanishGreeting()
{
    printf("Hola!\n");
}

void SayEnglishGreeting()
{
    printf("Hello!\n");
}