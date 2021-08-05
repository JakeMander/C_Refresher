#include <stdlib.h>
#include <stdio.h> //  For printf

/*
    In this module, we'll recap on variables and how to 
    declare them. 
*/

//  Prototype Scope! - Used for the final example!
int sum (int x, int y);

//  Global Scope! - Used for the final example!
int globallyScopedVariable = 10;
int main(void)
{
    /*
        Let's recap the basic concept of what a variable is.

        A variable is a name and address that map to a memory location
        assigned to your program by the OS which can be used to manage,
        manipulate and store data.

        In C, variable's have a type associated with them. Remember, 
        C is a statically typed language! C needs to know what types
        each variable are going to be so at compile time it knows
        how much memory to allocate and how the values stored
        in memory are going to behave and interact with the program.

        To declare a variable, you identify the type of the data that's
        going to be stored in the new block of memory, and give it a
        name.

        For example:
    */
    
    float exampleFloat; // Declared but not initalized (i.e. assigned a value)!
    
    //  We can declare multiple variables on the same line provided they are 
    //  comma seperated and we want them to be the same type. Again, these
    //  variables are declared but not initialised.
    char charOne, charTwo;

    //  Here we initalize a variable! Why? Because we've assigned it a value
    //  on creation!
    int intializedVariable = 1;

    //  Here's a multiline initialization:
    int a = 1, b = 2, c = 3;

    /*
        It's important you know that, when it comes to naming C variables, there
        are a few rules and conventions to follow:

        C variable names can:
            - Contain alphabet letters, digits and underscores.
            - Start with an alphabet letter or an underscore.
            - Be of any length (although try to make them short and 
              descriptive.)

        C variable names cannot:
            -   Start with a digit (0-9).
            -   Contain whitespace (i.e spaces).
            -   Be a reserved C keyword (i.e you cannot name a variable 
                "int", "if", "while" etc.)
            -   Contain special symbols like "!", "@" etc...
            -   Have the same name as another variable that exists inside
                the same scope (i.e. two different variables named "x"
                inside the curly braces of a function).
        
        C variable names are CASE SENSITVE! So "myVariable" is not equivalent to:
            - "MYVARIABLE"
            - "myVARIABLE"
            - "mYvArIaBlE"

        Now let's take a look at variable scope. As we know from our previous chapter,
        scope defines the lifespan of a variable and what it can be accessed by and 
        where.

        In C, the main types of variable scope are:
            -   Function Scope (Local Scope), Applies to all variables declared inside
                the body of a functions. Variables declared inside a function (both main/a
                user defined function) can access other variables or be read/written to
                inside the function. However, attempting to use them outside the function
                they were defined in results in a compiler error!
            
            -   File Scope (Global Scope), These variable are typically defined outisde all
                of your program's functions (including the main one!). Variables defined like
                this are said to exist in the global scope. They can be accessed from anywhere
                inside the same file (this includes when they are imported from another file using
                the #include directive!). 

            -   Block scope (Local variables), These variables are typically defined inside the
                brackets of conditional logic such as if, for and while statements. These 
                variables last for as long as the condition inside the brackets evaluates to
                true. They can be accessed inside the curly braces that implement the body
                of the statement, but trying to access these variables outside of these will
                result in a compiler error.

            -   Function Prototype Scope (Parameters), These variables are typicall declared
                whereever a function prototype is made. They exist inside the brackets of the
                function decleration and represent the parameters expected to be recieved as
                part of the function call. These variable only exist inside the brackets
                of the function prototype decleration meaning they can be re-used when the 
                body of the function is declared, and cannot be accessed from outside the
                prototype.

                The following would be an example of an invalid prototype decleration:

                void testFunction(int x, int x)

                Why? Because you can't have two variables of the same name inside the same
                scope!

                Finally, let's take a look at a practical example of scope:
    */

    //  Local scope
    int localScopedVariable = 20;

    //  Notice how we can pass A into this function call due to it's global
    //  scope.
    int result = sum(globallyScopedVariable, localScopedVariable);

    printf("%d\n", result);
    return 0;
}

//  X and Y are functional scope! They can only be accessed inside the sum function!
int sum(int x, int y)
{
    int result = x + y;
    return result;
}