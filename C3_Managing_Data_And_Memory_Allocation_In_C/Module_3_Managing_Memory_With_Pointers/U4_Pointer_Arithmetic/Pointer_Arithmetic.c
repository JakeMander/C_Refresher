#include <stdlib.h>
#include <stdio.h>

/*
    In this module, we'll look at pointer arithmetic and how we can use
    arithmetic operators with pointers to manipulate where pointers point
    to.

    It can be a complex topic to cover, but we'll try and keep things simple
    here.

    To sum up pointer arithmetic, let's ask ourselves a couple of questions 
    first:

        1. Don't pointers contain memory addresses?
            - Yes they do! We've touched on this quite a few times now and
              should be familiar with the idea that a pointer is just a
              variable that stores a memory address!

        2. Aren't memory addresses just numbers?
            - Yes they are! They're tpically a numeric value represented 
              in hexadecimal. But numbers mean we can perform all kinds
              of useful artithmetic! We can add, subtract, divide or 
              multiply addresses by operands if we need to!

              That can be particularly useful when we need to find out
              how big a block of dynamic memory should be, or need
              to increment or decrement a pointer by a certain number of
              bits and bytes in order to point to the next set of memory!

    If we reflect on the questions we put forward, we'll realise that pointer
    arithmetic is simply address manipulation! In essence, we can apply all of 
    the arithmetic operators to a memory address in order to manipulate it!

    It's often best to visually demonstrate pointer arithmetic.

    Let's say we dynamically create a block of memory using the following:

    int *my_ptr = (int*) malloc(6 * sizeof(int))

    We'll end up with the following in memory:
    ____________________________________________________________________________________
    |         |         |          |          |          |          |          |        |
    |         |  Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |        |
    |         |   104   |    108   |    112   |    116   |    120   |    124   |        |
    |_________|________ |__________|__________|__________|__________|__________|________|                                                                               |
              |
              |
              |
            my_ptr 

    Here, malloc creates us a memory block of size 6 x the size of an integer
    variable on the current system and points the pointer to the memory address
    of the start of the block.

    Now, in reality, this is one single contiguous block of memory. There is no
    in-memory means of distinguishing which bits belong to one variable, and 
    which bits belong to another. So in essence, what we have is a single block 
    of memory made up of 192 bits on a 64 bit Windows Operating system (Each 
    int on a 64-bit system is typically 4 bytes, or 32-bits so 6 x 32 is 192).

    It is C which can give meaning to the defined block of memory and seperate a
    single block into multiple chunks through the use of pointers and pointer
    artihmetic! C does this through the use of typed pointers!

    For example, if we cast the void pointer returned by malloc to an integer
    pointer, we essentially tell C that the block of memory will have boundaries
    of 32 bits (4 bytes) per value. Therefore C now knows that it will need to
    traverse the memory block in steps of 4 bytes to read a full, single 
    integer value. 

    Therefore C now knows that pointer arithmetic such as increment, decrement 
    or division should be done by a factor of 4 bytes in order to traverse the
    memory in steps equal to the size of an integer variable on the system.

    And that's a really important consideration when it comes to C, and why we
    should use the sizeof operator! Different systems have different memory
    sizes for it's data types! The C compiler will look these values up when
    it compiles on a system to make sure it's allocating the correct amount of
    memory for the specific system!

    Let's demonstrate what we discussed above. 
    
    So we've initalised our memory block which is big enough for six integers.
    The void pointer that was returned from malloc is sitting at the starting
    memory address of this block and has been cast to an int pointer.

    But what if we want to step through our block of memory and read the next
    values? The key is pointer arithmetic!

    Let's run this increment operator on our pointer:
    my_ptr++

    In doing so, our memory block has now changed to the following:

    ____________________________________________________________________________________
    |         |         |          |          |          |          |          |        |
    |         |  Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |        |
    |         |   104   |    108   |    112   |    116   |    120   |    124   |        |
    |_________|________ |__________|__________|__________|__________|__________|________|                                                                               |
                        |
                        |
                        |
                      my_ptr

     Why has this happened? Because, as mentioned, the C compiler knows that
     on my 64-bit Windows Operating System, a single integer value should
     take up 4 bytes of memory. As "my_ptr" is a pointer of type "int", C
     knows that in order to step over enough memory to travel to the next
     integer value stored in a contiguous block of memory (at least on my
     system), it needs to move 32 more bits (4 bytes). So when increment is
     called, the memory address gets 4 added to it to skip over the 4 bytes
     required to take us to the next integer value!

     And we do the same again:
     my_ptr++

    ____________________________________________________________________________________
    |         |         |          |          |          |          |          |        |
    |         |  Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |   Addr:  |        |
    |         |   104   |    108   |    112   |    116   |    120   |    124   |        |
    |_________|________ |__________|__________|__________|__________|__________|________|                                                                               |
                                   |
                                   |
                                   |
                                 my_ptr

    Another 4 bytes skipped, and we're on to the next memory address!

    The key take away here is, it's the system architecture and the pointer
    type that determines how much pointer arithmetic is incremented or
    decremented by!

    So when should we use pointer artihmetic?

    In short, avoid it whenever possible!!! Code that uses pointer arithmetic
    is hard to read!

    There are however, always appropriate use cases that call for pointer
    arithmetic. these are:

        - Calculating byte offsets.
            - For example, if you're accessing a big binary file which contains
              data you need to access starting at byte 256, you can simply
              add a numerical value to your pointer, such that you end up with
              a new pointer to that particular byte offset. You can then use
              this pointer as your starting point for accessing the data you
              need past the 256th byte.

        - Comparing memory addresses.
            - Remember, memory addresses are numbers and numbers can be
              compared! This might be useful when you are comparting memory
              size, the start and end points of memory blocks etc.

        - Rare use cases where code is cleaner as a result of using pointer
          arithmetic. 
            - One useful example is iterating over an array of values. 
              Pointer arithmetic helps cut down on the number of 
              variables you are using to keep track of previous and next 
              elements by making moving to next and previous values a 
              matter of simple increment and decrement operators. 

    Though powerful, pointer arithmetic can be incredibly dangerous to your 
    program if not used carefully!

    The first danger is readability. For the most part, pointer arithmetic is
    hard to read! Pointer arithmetic is abstracted away from the programmer by
    C and thus introduced some mental complexity by making you think about 
    what's going on behind the scenes and in memory! It's not inutitive to think
    about arithmetic in terms of memory blocks, addresses and pointers!

    Think of it like this. When we increment a pointer by one, the pointer
    can end up being incremented by 1, 2, 4 or 8 bytes depending on what
    type of variables the pointer is handling, and how big these values are
    based on the system the program is running on. This isn't exactly the 
    most intuitive way of thinking about addition.

    The second danger is memory overflow. 

    The problem with pointer arithmetic is there are no safety measures in 
    place to stop you writing to memory you didn't mean to write to. If 
    you're not careful and don't carefully track the bounds of your memory, you
    may end up hitting memory used for other variables and partially or fully
    overwrite the values stored for them instead when you dereference the 
    memory address! 
    
    Or you might end up reading an incorrect value that you didn't mean to 
    access and end up introducing errors into your program when you dereference
    the value pointed to at the memory address outside the bounds of your 
    dynamic memory on the heap.

    You could also end up attempting to access reserved memory that the OS uses
    for it's own functionality. In this case, the OS will stop you from 
    accessing this memory and give you a telling off in the form of a 
    "segmentation fault" warning.


    Finally, using Pointer Arithmetic introduces complexity into your program.
    Operator precedence in pointer arithmetic can take a while to understand 
    or make understanding how memory is being accessed more difficult to 
    understand, thus tying in to readability of code! Always remember, code
    should be simple to make it readable for others!

    So proceed with caution when using dynamic memory and pointer arithmetic!
    Always favour the array index notation (i.e array[i]) over pointer 
    arithmetic if it's appropriate to do so!

    To compound everything we've learned, let's have a look at a demo!
*/
int main(void)
{
    int count = 4;

    //  Pointer points to the start of the memory block. We'll use this as our
    //  starting point to perform all of our other operations and arithmetic 
    //  from.
    int *intPtr = (int*) malloc(count * sizeof(int));

    /* 
        Example 1: Simple Pointer Addition

        Loop through our new block of dynamic memory using pointer arithmetic
        and the number of integers we wanted to store.

        Notice how addresses printed in the console are not incremented by 1, but
        by the total size of the value type on the current system!
    */
    printf("Example 1\n");
    printf("**********************************\n");
    
    for (int i = 0; i < count; i++)
        printf("'intPtr' Current Address: %p\n", intPtr + i);

    /*
        Example 2: Assigning Values to memory Addresses and Dereferencing 
        Pointers Using Pointer Arithmetic.

        In this example we iterate over our dynamicaly created block of memory
        using pointer arithmetic to increment by the number of integer values
        we made enough space for. 

        As we do so, C increments our pointer by the size of an int variable
        each time so we point to the starting address of the next full 
        integer value.

        We then dereference the pointer to provide read/write access to the 
        memory and assign whatever value our 'initalValue' variable has been 
        incremented to.  

        We need to take care with pointer arithmetic when considering operator
        precedence. When we dereference a pointer, we need to wrap the 
        arithmetic in brackets to ensure the pointer arithmetic occurs before
        the dereference! This is seen when we use *(intPtr + i).
    */
    printf("\nExample 2\n");
    printf("**********************************\n");
    
    int initalValue = 5;
    for (int i = 0; i < count; i++)
    {
        *(intPtr + i) = initalValue++;
        printf("'intPtr' Current Address: %p - Current Position %d - Current Value %d\n", 
            intPtr + i, i, *(intPtr + i));
    }

    
    /*
        Example 3: Accidentally Losing Address Offsets

        In this example, we demonstrate the dangers of pointer arithmetic by
        accidentally incrementing our pointer and losing the starting memory
        address of a pointer.

        In the event that this happening it then becomes easy for you to
        overflow into other memory as you have lost a consistent reference
        to a point in your dynamic memory! 
    */
    printf("\nExample 3\n");
    printf("**********************************\n");

    int* myOtherIntPtr = (int*) malloc(count * sizeof(int));

    printf("Starting Memory Address of New 'myOtherIntPtr' Malloced Block: %p\n", myOtherIntPtr);

    for (int i = 0; i < count; i++)
    {
        //  Here we accidentally increment the pointer address itself instead 
        //  of returning a new address value based off our starting address.
        printf("'myOtherIntPtr' Address: %p\n", myOtherIntPtr++);
    }

    /*  
        We expect the address of 'myOtherIntPtr' to be the same as the original
        printf statement... But it's not! We've overwritten the original value
        in the for loop and will not be able to get back unless we decrement
        it by our count value again!
    */
    printf("Expecting The Memory Address of 'myOtherIntPtr' To Be The Original Starting Address: %p\n", myOtherIntPtr);

    return 0;
}