/*
    Pointers are key in the ability to refer to values by reference in C and
    are the main means by which to access and reference the blocks of memory
    you create. 

    When handling dynamic memory allocation in C, it's important to fully
    understand what pointers are and how they operate.

    The following exercise serve's as a recap on the existing pointer
    knowledge we have.

    First off, let's revist what a pointer is.

    A pointer is simply a variable that contains a memory address.

    These memory addresses point to a location in memory which may
    store:

        - A value (i.e. an integer, a character, a struct, a floating point
          value etc...)
        - Another pointer which points to another memory address when ]
          dereferenced.

    Let's jump in to a nice simple example in code.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    /*
        Let's use the following code as an example. In our first line of code,
        we simply declare a variable that stores an integer value. When this 
        is done, allocates a block of memory which will track:

            - The variable name.
            - The value stored at this block.
            - The memory address this value is stored at.

        For example:

            Memory Block 1
            Name:            myInt
            Value            10
            Memory Address:  100
    */
    int myInt = 10;

    /*
        The above definition is all well and good. But what happens if we want
        to directly access the memory address of the above variable? 

        Remember, accessing the above variable without a memory address to 
        reference results in the value being passed as a copy. The variable
        itself will not change!

        For this, we use pointers! And as we know, pointers simply store
        memory addresses!

        To create a pointer to "myInt", simply create a new variable which
        stores a pointer to an integer value. This can be done by using the
        star (*) operator before the new variable's name and after the type
        decleration.
        
        Finally, in order to assign our pointer a memory address, we need to 
        use the ampersand operator (&) on the variable who's memory address
        we need to extract.
        
        Putting all this together, we end up with: 
    */

    int *ptr = & myInt;

    /* 
        With the pointer created, we now have two blocks of memory on the stack
        that look like the following:

            Memory Block 1
            Name:            myInt
            Value            10
            Memory Address:  100

            Memory Block 2
            Name:            ptr
            Value            100
            Memory Address:  200 

        As we can see, our new variable has in it's memory, the memory address 
        that stores "myInt's" value whilst itself having a memory address of
        200.

        This pointer "redirection" is part of the reason why pointers can be 
        considered as confusing, particularly when you have pointers pointing
        to pointers pointing to pointers. This is why it's important to avoid
        misusing them and use them clearly! Unfortunately, if you don't know
        what you're doing with pointers, it's easy to fall into these
        traps.

        As mentioned before, pointer syntax revolves around the use of the
        ampersand (&) and star (*) syntax. These are referred to as the 
        "address of" and "star" operators respectively.

        Whenever you need to declare a pointer, you'll use the star operator.
        There are a couple of different styles for this approach. For example,
        the star can go just after the type declaeration, or may go before the
        variable name like so:

            int *pointer1;
            int* pointer2;

        They both do the same, so just pick a stlye and stick with it! 
        Remember, consistency is key!
    */
    
    int number1 = 10;
    int number2 = 15;
    int number4;
    
    int *pointer1;
    int* pointer2; // Shows different way of declaring pointer.
    int *pointer3;

    /*   

        To intialize a pointer, we use the "address of" operator (&) to
        return the memory address of the variable we apply the operator
        to.
    */

    pointer1 = &number1;

    /*
            As we learned in the last section, malloc, calloc and realloc all
            return a void pointer in anticipation of a cast to a typed
            pointer which we perform in the example below. 

        We don't need to use the ampersand operator below. Malloc returns
        a pointer (memory address) for us!

        Also remember, the same can be said for arrays! Referencing an array
        causes the reference to decay to a poinyter to the starting 
        memory address of the array!  
    */
    pointer2 = (int*)malloc(sizeof(int));
    pointer3 = (int*)malloc(sizeof(int));
    
    /*
        Finally, what happens when we want to extract the value from a memory
        address that the pointer is pointing to? 

        Well if we just attempt to access the pointer with just a reference
        to the pointer's name, then the memory address the pointer points
        to will be returned.

        Instead, the star (*) operator can be used to extract the value
        stored at the associated memory address through a process known as
        dereferencing. 

        Dereferencing a pointer simply means, extract the value stored at a 
        given memory address.
    */

    // Extract the value found at number1's pointed address and assign to new
    // variable.  
    int number3 = *pointer1;

    //  By dereferencing the variable call, we're telling C to assign the value
    //  50 to the memory address pointed to by the number4 pointer. If we don't
    //  dereference, we'll be changing the memory address the pointer is 
    //  pointing at to 50 instead.
    *pointer3 = 50; 

    /*
        In order to build on the idea that malloc, calloc and realloc all 
        return pointers, let's run through an example of dynamically 
        allocating a memory block with enough space for four integers.  

        In the below example we decalre and initialize the fourIntBlock
        variable to be a pointer to an integer that we have initalized as a
        block of memory big enough to contain 4 integers. We cast the pointer
        malloc returns to an integer pointer to make sure C knows what we're
        storing at the memory block and how we should handle the data stored 
        in the block.

        But what does this look like in memory?

        -------------------------------------------------------------------------------
            |    Block One    |    Block Two     |   Block Three  |   Block Four  |                                                                       
            |    Size: 4byt   |    Size: 4byt    |   Size: 4byt   |   Size: 4byt  | 
            |     Address:    |     Address:     |    Address:    |    Address:   |
            |     xxxxxxx0    |     xxxxxxx4     |    xxxxxxx8    |    xxxxxxxc   |                                                                       
        -------------------------------------------------------------------------------
                     |
              fourIntBlockPtr

        As we can see, in our big block of program memory, we allocate four chunks
        of memory. As we've specfied in our initalization that these memory blocks
        should be big enough to store 4 times an integer value (128 bits/16bytes),
        as on a Windows OS running a 64 bit processor, C's int's are of size 
        32 bits.

        You can see this in the above memory addresses. Note how each address
        (representing one byte) increments by four each time. This is because
        each interger value is 32 bits (4bytes). This is quite an important 
        consideration when working with dynamic memory, as it will determine
        the pointer arithmetic (covered later) you need to perform in order
        to increment your pointers by the correct amounts to move from one
        stored value to another stored value in your dynamically allocated
        blocks of memory! Don't worry about this for now however.

        So, when C allocates a single block of coniguous memory of 16 Bytes 
        (128 bits), it then points the pointer produced by malloc to the 
        starting memory location of the block. From here, to move between
        our values in the memory block, we'd need to increment our pointer by
        four bytes to get to the next stored value (again, covered in more detail
        when we go over pointer arithmetic).
    */
    int *fourIntBlock = (int*) malloc(4 * sizeof(int));

    /*
        Now, time for one last demo!
    */

    int demoNumber = 10;
    int *demoPtr;

    // Get the address of demo_ptr using & operator.
    printf("Address of 'demoPtr: %p\n", &demoPtr);

    //  Initialize a pointer using the & operator. 
    demoPtr = &demoNumber;

    //  Initalize a pointer using malloc.
    char *name = (char*) malloc(8 * sizeof(char));

    //  Dereference a pointer to read value at its address.
    printf("Value of 'demoNumber': %d\n", *demoPtr);

    int demoCopiedNumber = *demoPtr;
    printf("Value of 'demoCopiedNumber': %d\n", demoCopiedNumber);

    //  Dereference a pointer to assign a value to its address
    *demoPtr = 50;
    printf("Value of 'demoPtr' After New Value Assignment: %d\n", *demoPtr);

    free(name);
    return 0;
}