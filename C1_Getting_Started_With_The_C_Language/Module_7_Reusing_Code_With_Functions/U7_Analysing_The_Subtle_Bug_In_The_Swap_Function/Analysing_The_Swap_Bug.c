/*  
    As we saw in the last exercise, something strange was happening
    with our swap variable!

    Our swap logic was sound, but the changes to our a and b variables were
    not being persisted when we exited the function into our global scope.

    We passed two variables in and swapped them! Surely then x and y should
    have swapped!

    Unfortunately that's not how C works...

    The problem lies in how we pass in our two arguments!

    When we pass two variables as arguments into a function, they are passed
    by VALUE. This means when X and Y are passed in as arguments, C looks 
    up the variables in memory, says "Let's have a look what's stored here"
    and then copies the values to TWO NEW MEMORY LOCATIONS, a and b. 

    Meanwhile X and Y sit there doing nothing whilst the function runs.

    These new variable memory locations a and b are now used as part 
    of the local scope (including our new temp variable) to hold the
    values we swap over. But as we know, local scope only lasts as long
    as the function does... So a and b, now holding our newly swapped values
    end up going out of scope. The program stops caring about those locations, 
    and then goes "Ahhhh, let's print X and Y now!".

    But X and Y haven't changed! The change happened to A and B which were
    storing copies of the original values! And they've now been lost
    in memory somewhere!

    This is a REALLY IMPORTANT part of C! If you just pass a variable
    such as an integer, float or char (arrays are a bit different in
    C) as arguments into a function call, you pass by value.

    If you pass by value, you essentially create copies of the 
    original values the variables you pass in point to and assign
    them to new variables created especially for the function. 

    This means that when you exit the function, the variables holding
    the inital values are completely independent of the function
    and known nothing of any changes that went on inside it!

    So how can we change this? How can we make our function point 
    to the original variable and manipulate those values instead
    of creating completely new variables and manipulating them instead?

    We know this is possible because we use scanf which takes user
    input and assigns it to the address of a variable we provide!

    Remember we use "&" for scanf. Because scanf needs the address
    of the variable to assign the recieve user value to.

    If we remember, "&" can be seen to mean "Give me the memory
    address of the following variable"

    Aha! There lies the issue! & is a pointer to a variable!

    If we pass pointers into our functions we explicitly say,
    "refer to whatever is stored in these memory addresses"! 

    We are now no longer passing arguments by value, but by
    reference! We are now refering explicitly to places in
    memory that we should manipulate and so we can now start
    to fix our program!
*/

#include <stdio.h> // Gives us printf


//  The swap function! Take in two values, store one in a temporary variable, 
//  swap one value, and then assign the remaining value stored in the temp
//  to the other variable!
void Swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main(void) 
{
    int x = 10;
    int y = 20;

    printf("Inital Values: \n x = %d, y = %d \n\n", x, y);

    Swap(x, y);

    printf("Value After Swap: \n x = %d, y = %d \n\n", x, y);

    return 0;
}