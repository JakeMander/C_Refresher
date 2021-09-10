#include <stdlib.h>
#include <stdio.h>

/*
    In this unit we'll recap on the relationship between structs and 
    pointers.

    So, just to make sure it's drilled in to memory (pardon the pun), a pointer
    is a variable that stores a value that represents a memory location.

    Specifically it's the address of another variable in memory...

    OR

    It contains the address of a chunk of RAM (this is typically the starting 
    location of a contiguous block of memory that represents a struct or an
    array). 

    Let's also recap on the point of pointers (pardon the pun again)...

    C is a mid-level language which is just a step above assembly language.
    This means it's close to the machine code which is read directly by
    the processor.

    To this end, pointers in C provide access to memory locations much in the 
    same way as assembly accesses memory. 

    So pointers provide direct access for programmers to access and
    manipulate data, something which many higher level programming languages
    abstract away from the programmer and try their best to hide.

    As we've covered, there are some rules to using pointers. These are:

    - Pointers have a data type. The type must match the referenced variable
      (with the exception of void pointers. They just point to a memory address
      of any type, but do not allow you to perform pointer arithmetic... 
      they don't know the type so can't figure the size of the jumps to make!).

    - A pointer must be initialized before use!

    Remember, pointers are funny little things. Let's address the primary source
    of confusion again.

    A pointer is declared as so:
        int *ptr // A pointer to an int is declared.

    But once declared we can then call the pointer in two different ways to 
    yield two completely different values.

    Taking the above example as a demonstration we can call a pointer like so:

    ptr 

    OR

    *ptr
    
    The first approach Gives us the address of the memory location the ptr 
    variable points to.

    The second approach 'dereferences' the pointer... That is, the program goes
    to the memory address the pointer is pointing to, and returns whatever 
    value is stored there.

    Now to assign an address to a pointer, we use the ampersand operator '&' 
    (or the "address of" operator) and apply it to a variable.

    Let's have a look at a quick example:

*/

int main (int argc, char* argv)
{
    int age;
    int *ptr;

    //  Standard variable initalization...
    age = 40;
    // Assign the address of age to the ptr pointer...
    ptr = &age;

    //  Now let's compare the values!!!
    printf("\n\tValue of 'age': %d", age);
    printf("\n\tAddress of 'age' (&ptr): %p", ptr);
    printf("\n\tValue of 'ptr' (*ptr - ptr dereferenced): %d\n\n", *ptr);
}