/*  
    So we now know the issue with our problem! 

    Before we fix it however, let's just explain how pointers work in
    C in a little more detail

    Let's suppose we create a variable like so in memory:
        int n = 64;

    As we know, we've created a block in memory that's big enough to hold
    an integer value. The name "n" refers to this location in memory.
    More specifcally, n refers to the hexadcimal address that the
    value 64 is stored at!

    Now what if we want to point to this specific value in memory?

    Well, we can create a variable that is a pointer TO AN integer:

        int *p = &n;

    What happens here?

    Well we declare a block of memory that's big enough to store a
    value that can hold the address of an integer value. This is
    because we're not storing a value, but a memory address!

    Now, as we know, we need to assign this a value. What value
    do we want to store? That's the memory address of the variable 
    holding the value 64 which is "n".

    How do we get the address of a memory location? 

    As we know, we use the ampersand operator ("&")!

    So our new pointer variable can be read as:

        "Assign a pointer to (the address of) variable n to variable p, which stores 
        a pointer to a memory address which stores an integer. "

    So now, variable p is a pointer which stores the memory address of n.

    But it is variable n that stores the value of 64!

    To clarify, this is the syntax to declare a pointer to a variable:

    int *p; 

    The above pointer has been declared but not assigned (initalized).

    We can however, assign the variable an inital address:

    int *p = &n;

    Alternatively we can use a special pointer value called NULL.

    NULL essentially tells the assigned pointer to point to nothing!

    This is useful in cases where we might not know to start with the 
    memory address we're pointing to, but will eventually know it at
    a later stage. Null acts as a sort of placeholder.

    int *p = NULL;

    Now let's suppose that the pointer is pointing to an integer value.

    What happens if we want to change the value that is stored at the 
    memory location storing the integer?

    Well in C we use the "dereference" syntax to tell C that we 
    don't want the memory address the variable is pointing to, 
    but the actual value that is stored there.

    For example if we do this:

    n = 64;
    int *p = n
    p = 500

    We're trying to set the pointer to an address of 500.

    Instead we need to use a "*" infront of our assigned variable name
    to explitly tell C that it's not the memory address that p is pointing
    to that we want to change, but it's the value of the memory address
    that p points to that we want to change! So if we want to change 
    the value of the memory address that p points to to 500, we can do this:

    n = 64;
    int *p = n;
    *p = 500;
    
    By dereferncing we have accessed the pointer target and mutated it!

    Note that dereferencing should be used when you want to read or 
    write the value of a pointer's targetted address.

    Now we know how the basics work, let's look at passing some
    pointers as arguments. This will be key in solving our intial 
    swap function bug.

    In our swap function, the logic is sound, so we should keep
    the alogirthm the same. However, as we disucssed previously,
    we need to pass in values by reference so we can access
    the original memory addresses and swap them over!

    To do this, we need to pass in pointers to our X and Y
    variables. As such the parameters should be converted into
    pointers. In the example below you'll see we have done this
    simply by adding an asterix to both parameter definitions.

    Now that we're handling pointers in our function, to swap the
    values themselves, we need to use the dereference operator
    to explicitly tell C that it's the values we want to re-assign
    to each pointer's target, not the address to the pointer.

    Notice how our swap function now implements the * operator
    in each place where we reassign values.

    Notice how "temp" doesn't need dereferencing. This is because it
    is holding an already dereferenced value which can be copied 
    to the value pointed at by B.

    With the function set up, there is one last thing we need to change.

    Remember, our parameters now expect a type of integer pointer, so
    our function now needs to recieve two memory addresses which we can
    pass in using the "&" operator next to our variable names like in
    the example below.

    Now if we run our program, we should see that the bug is fixed!

    It can be slightly confusing when you first start out with pointers,
    but keep practicing and you'll get it eventually!

*/

#include <stdio.h> // Gives us printf


//  The swap function! Take in two values, store one in a temporary variable, 
//  swap one value, and then assign the remaining value stored in the temp
//  to the other variable!
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void) 
{
    int x = 10;
    int y = 20;

    printf("Inital Values: \n x = %d, y = %d \n\n", x, y);

    //  Pass in the addresses to the function as our parameters
    //  are pointers.
    Swap(&x, &y);

    printf("Value After Swap: \n x = %d, y = %d \n\n", x, y);

    return 0;
}