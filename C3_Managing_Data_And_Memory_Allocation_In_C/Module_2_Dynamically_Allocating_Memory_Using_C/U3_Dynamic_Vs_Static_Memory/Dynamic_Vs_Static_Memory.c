/*
    Before we dive any further into memory management and allocation
    let's compare statioc memory allocation against Dynamic Memory allocation.

    Static Memory is:

    - Allocated on the stack. Static memory is as it's name suggests, static
      and unchanging. Once it's pushed on to the stack, that's where it lives
      and the memory block holding the value does not change during its 
      lifespan. 

      Static memory is ultimately managed by the compiler when placed on the 
      stack. 

    - Allocated at compile time. The compiler determines how large the stack
      needs to be at compile time in order for your program to run.

    - Memory that cannot be manually freed. This is all done for you by the
      C compiler.


    Dynamic Memory is:

    - Allocated on the heap. Dynamic memory is managed by the programmer.

    - Allocated at runtime. Throughout the life of the program, C will provide
      you the ability to add and remove memory to the heap during runtime. 
      Whilst this provides you with a lot of power, it does come with a degree
      of risk if memory is not managed properly (i.e. crashes are common if you
      don't deallocate memory and cause the program to overflow it's allocated
      memory). 

    - Freed by the programmer. This is where "Manual Memory Management" comes 
      from. If you don't free up memory after it's used, you will end up with a
      memory leak!

    Now let's get ready to manage some memory!

    In this course, we'll be working for a made up compant called "Wired Brain
    Coffee". They build Iot (Internet of Things) coffee machines!

    But they've been having problems. The previous programmer they hired wrote
    some code which is causing all manner of problems for their machines! 

    It's full of memory leaks and other bugs and we've been hired to write some
    better code!

    We'll also be on board to make sure the software we right is performant!
    Wired Brain's machines only have a limited amount of memory so we need
    to make sure the memory we have stretches and isn't wasted!

    Finally, one important point. The programs written for Wired Brain will
    have memory dynamically allocated which means we will never be able to
    know the amount of memory needed to run the program until runtime.

    We won't be able to know at compile time how much dynamic memory we use!
    So we'll need to use the memory functions provided by the C standard
    library. 

    Next up, we'll explore how we can use these standard functions to
    dynamically manage memory and the behaviour each offers!
*/