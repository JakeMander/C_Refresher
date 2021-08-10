#include <stdlib.h> // For printf etc.

/*
    In this unit, we'll take a look at what storage classes are and how they're
    used in C to modify and define types.
*/

int main (void)
{
    /*
        What is a storage class?

        Well it's a C construct that's used to modify properties and speciify
        the type of storage of a variable during it's declaration.

        As we know, when we declare variables, we are associating a name with 
        a storage space in memory that is allocated to hold a value of the
        specified type.

        When the program completes, the Operating System then frees up all the
        memory used to hold the data used by your program back for re-use by
        other programs and services. 

        As we also know, some variables with smaller scope, such as local or
        prototype variables are released before the program finishes, 
        specifically when the function prototype is declared, or the parent 
        function that holds the local variables finishes it's exectuion.

        In order to have greater control over the scope of variables and when
        and where a given variable is accessible, C provides the storage class.

        The storage class also allows the developer to define the duration of a
        variable so that a variable's lifespan from allocation to deallocation
        can be controlled. This is an important consideration when you are
        working with limited resources and performance is a concern. By
        controlling the lifespan of variables, you can ensure memory is cleaned
        up exactly when it's not needed, allowing for more efficient use of
        memory.

        In addition, storage classes allow you to control linkage in C. This
        means you can define how variables should be linked by the C linker,
        (i.e. the component in the C compilation process that bundles all the
        object files together into a single executable binary). This allows you
        to control which scopes have access to variables declared in your program.

        Before we use storage classes, it's important to understand how memory
        is used in C.

        C manages memory using three memory constructs. These are:

        -   The Stack.
        -   The Heap.
        -   Static Memory.

        The stack is a First In First Out (FIFO) data structure that is used
        to manage variables that are stored in local scope. When a function
        is run, variables declared inside a function are added to the stack
        in the order they occur in code. When referenced, these values are 
        popped from the stack. When the function finishes, the stack should
        be cleared of all variables used for that function call.
        
        This process is managed automatically by the CPU and the OS. However
        care should be taken. It is possible to try and push too many values
        onto the stack which causes a stack overflow. Here, the stack becomes
        full, and the program has nowhere left to store variables so the 
        program crahses. 

        The heap is a large contiguous block of memory which is used to store
        variables created dynamically using C functions such as malloc or 
        calloc. This is where the user handles the allocation of memory
        themselves. This part of the memory is not automatically managed!
        Memory has to be assigned an unassigned memory! Don't forget to 
        deallocate memory you no longer need! Otherwise you'll end up with
        a memory leak in your program!

        Finally, we have static memory. These are the global variables 
        that have the same lifespan as your program. For example,
        any variables defined outside a function, or declared using
        the static keyword. Static memory is allocated when the program
        starts, and remains allocated until the program finishes. 

        Always bear these different memory types in mind when declaring 
        variables! 
        
    */
    return 0;
}