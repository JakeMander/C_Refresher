/*
    In this lesson, we'll explore the following:

        - Why pointers are useful.
        - Use cases for pointers.
        - How pointers can be used to pass values by reference.

    One of the most prominent uses of poiters is data structures. Because data
    strutures are dynamic in their application (i.e. they are determined at run
    time by user/program behaviour), pointers allow us to dynamically and
    efficiently track new components of the data structure as they are created.

    In addition, pointers are useful as they allow the programmer to pass 
    values by reference into functions via parameters. This is more performant
    than C's approach of "passing by value" (i.e. creating a copy of the value
    passed in the argument and pushing it on to the stack to be referenced as
    the function parameter).

    The issue with passing by value is performance will often take a hit. 
    Values have to be copied which takes up memory and takes time to perform.
    The problem is worserned in instances where you're passing large numbers of
    data that needs copying, or large single objects that need copying to a 
    function.

    Instead, pointers allow us to pass large amounts of data around by passing 
    the address to that data around rather than copies of the data itself. 
    There are more benefits to the pass by reference approach which we'll look
    at later on.

    Pointers are also incredibly important in dynamic memory management! 
    They're used heavily for this purpose and play a key role in dynamic 
    memory. They're that important that the C standard memory management
    functions (i.e. calloc, malloc, realloc) all use them one way or another!

    Let's take a look at an example of pointers being used in a data structure.

    We'll look at the linked list:
    https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist.png

    As we can see, the linked list consists of a series of nodes which contain
    two components. 
    
    The first component is the data section, this contains
    a data value that acts as the value that is to be processed as part of the
    application (for example, it could be a name, a struct representing a 
    person, an element in a network or graph etc. etc.).

    The second component is the "next" node pointer which points to an adjacent
    node in the list which the program can access. How can the program access
    this? Well because the "next" component is a pointer, when a new node is
    added to the list, the last current node in the list has it's next pointer
    updated to store the memory address of the newly created node so it can
    locate the next item in the list. When we iterate through the list, we
    do so by accessing each node's next pointer, essentially jumping from
    memory address to memory address! 

    Linked lists are powerful because they can grow or shrink depending on
    the needs of the application! Arrays can't do this! When they're initalised
    they get initalised to a set size which needs to be defined at compile time!

    With linked list, you can use pointers to dynamically create new nodes and
    link up existing nodes to new nodes on the fly! Powerful stuff!

    Pointers have heavy usage in other data structures, for example stacks and 
    queues... but we won't go into them here!

    What happens though when these data structures get large? Well if we need
    to start passing them into functions then we end up taking a hit to our 
    memory usage! Why? Because these data structures are being copied by value
    as a result of C's approach to passing arguments to functions!

    Take the first example in the main method:



*/
 #include <stdlib.h>
 #include <stdio.h>

//  Demo function prototypes. 
void AddOne(int num);
void AddOneByReference(int *num);

//  Demo function prototypes
void PrintIntByReference(int* numberPtr);
void PrintIntByValue(int number);

void MallocIntDangerous(int* numberPtr);
void MallocIntSafe(int** numberPtr);

int main(void)
{
    /*  
        Example 1

        Even though we pass num in an argument to the AddOne function, the
        function does not have access to the original value stored in memory.
        
        Why?

        Because C takes a copy of the value stored in main's "num" variable and
        assigns it to the function's "num" variable which has been created and
        put on the stack. 

        C then increments this variable, thus leaving the original main value
        untouched. When the function is complete, it's "num" variable goes
        out of scope and is popped off the stack. 

        It looks a bit like this;

        *Program Starts*

        Memory Location 1:
        Name:       num
        Scope:      main
        Value:      10
        Address:    100

        *Function Called*

        Memory Location 1:
        Name:       num
        scope:      main
        Value:      10
        Address:    100

        Memory Location 2:
        Name:       num
        scope:      AddOne
        Value:      10
        Address:    104

        *Function Increments AddOne Num*

        Memory Location 1:
        Name:       num
        scope:      main
        Value:      10
        Address:    100

        Memory Location 2:
        Name:       num
        scope:      AddOne
        Value:      11
        Address:    104

        *Function Finishes*

        Memory Location 1:
        Name:       num
        scope:      main
        Value:      10
        Address:    100

        <- Memory Location 2 Goes Out of Scope! ->

        This is why you should avoid passing large chunks of data into a 
        function by value! It all get's copied and clogs up your program's 
        stack in memory!

        The solution to this is to pass by reference!

        This is demonstrated in example 2!
    */
    int num = 10;
    int numByReference = 50;

    printf("Example 1\n");
    printf("******************\n");
    printf("num Is Initalised To %d In Main\n", num);
    printf("'AddOne' Called\n");
    AddOne(num);
    printf("num In Main Is Now %d In Main\n", num);

    /*
        Example 2:

        Notice how now we now have direct access to the variable stored in the
        main function!

        Why? Because technically, we end up passing in a copy of the memory
        address of numByReference into the function. 

        This is an important thing to consider. Though we say "pass by 
        reference", what C is actually doing is passing a copy of a 
        memory address reference BY VALUE! So we're still using memory
        to store the copy of the memory address, but that's still more
        efficient than copying a huge data structure!

        Because the function receives the address of numByReference in main,
        we can use the dereference operator to look up the value stored
        at that address, and thus, have passed numByReference into 
        AddOneByReference by reference!

        The important thing here is, remember that C applies pass by value ALL
        THE TIME. Don't get confused by "pass by reference". We still copy
        the memory address! This is important when it comes to things such
        as pointers to pointers which we'll cover next!

        When writing a C program there may come an instance where we need to
        alter a pointer from within a function. The best way to do this is
        pass a pointer to a pointer into the function!

        Sounds confusing, but don't worry, we'll go over this!

        Remember, a pointer is simply a variable that contains a memory 
        address! So a pointer to a pointer is still a variable that contains
        a memory address, it's just that the memory address it stores will take
        you to another address if you follow it via a dereference!

        Let's take a look at this in example 3!
    */
    printf("\nExample 2\n");
    printf("******************\n");
    printf("\nnumByReference Is Initalised To %d In Main\n", numByReference);
    printf("'AddOneByReference' Called\n");

    //  Be sure to supply the ADDRESS of numByReference as AddOneByReference 
    //  has an integer pointer argument!
    AddOneByReference(&numByReference);
    printf("numByReference In Main Is Now %d In Main\n", numByReference);

    /*
        Example 3
        In the below example we create a variable that stores the value 10.

        We then create a pointer to this value. So the memory address of
        example3Value is stored here. When we dereference this pointer,
        C will check the value stored at this variable which is the
        memory address of example3Value, follow it and retrieve the value
        stored at that location which is 10.

        Then finally, we create our pointer to a pointer. Here, we store the
        memory address of our example3Ptr variable. Again, when we dereference
        this pointer, C checks the value stored at this variable which is the
        memory address of example3Ptr, follows it, and retrieves the value
        stored at that location which is the memory address of example3Value!

        The important thing to note here is a pointer to a pointer is denoted
        by a double star (i.e. **variableName), and that this value should
        point to another memory address!

        Pointer to pointers are incredibly useful in the following use cases:
        
            - Multideimensional Arrays: Dynamically allocated mutlidimensional
              arrays are dependent on pointers to pointer in order to act as
              the indexes to each row of arrays. The pointer to the pointer
              points to the base address of the array which can then be used
              to point to the elements stored in that particular array!
              These will be covered in the next module!

            - Arrays of Character Strings: In itself a multi-dimensional array.
              As we know, a string in C is just an array of characters. So if
              we have arrays of character string, we essentially have an array
              of pointers that point to arrays of characters!

            - Passing pointers by reference: Sometimes a pointer needs to be
              modified inside a function! Remember, you pass pointers by value
              if you pass them to a function, so you can't access the memory
              address of the original pointer from the parameter value passed
              to the function!

              Why?

              Because the parameter value is a newly created memory block that
              lives on the stack which has a memory address that is different to
              that of the original pointer! 

              Instead, you want to pass in the memory address of the pointer 
              via a pointer to a pointer so you can gain access to it's location
              in memory, as well as dereference the value it points to

        Let's finish up with a demo!

    */
    int example3Value = 10;
    int *example3Ptr = &example3Value;
    int **example3PtrToPtr = &example3Ptr;

    printf("\nExample 3\n");
    printf("******************\n");
    printf("\n'example3Value' Addr: %p, 'example3Value' Value: %d", &example3Value, example3Value);
    printf("\n'example3Ptr' Addr: %p, 'example3Ptr' Value: %p, 'example3Ptr' Dereferenced Value: %d", &example3Ptr, example3Ptr, *example3Ptr);
    printf("\n'example3PtrToPtr' Addr: %p, 'example3PtrToPtr' Value: %p, 'example3PtrToPtr' Dereferenced Value: %p\n", &example3PtrToPtr, example3PtrToPtr, *example3PtrToPtr);


    printf("\nDemo\n");
    printf("******************\n");

    // Give example of passinf an int via a pointer instead of by value.
    int myNumber = 10;

    PrintIntByValue(myNumber);
    PrintIntByReference(&myNumber);
    printf("The Addresses Printed Above Should Be Different!^^\n\n\n");

    int* numberPtr = &myNumber;

    printf("'numberPtr' Points To Address %p Before Malloc.\n", numberPtr);

    /*
        This function both will not work and will introduce a memory leak into
        the program!

        Why?

        Because, though we pass a pointer to the function, we are infact
        copying this address by value into the functions numberPtr parameter.

        When this occurs, the local numberPtr variable ends up being initalized
        in it's own space in memory, with a new memory address, but with the
        memory address that the main numberPtr was assigned copied to it. 

        So when MallocIntDangerous attempts to assign the malloced block of
        memory to what the programmer hopes is the "numberPtr" variable found
        in the main function, what actually happens is created pointer to the
        new memory block is assigned to the memory address on the stack created
        for the function's local numberPtr variable.

        Now this is a BIG problem! Because as we know, when the function 
        completes, all our local variables go out of scope and end up popped
        off the stack. The local numberPtr essentially disappears, taking the
        one reference to the new memory block we created on the heap with it!

        Thus, we end up with a dangling pointer and no means of freeing up
        the new dynamic memory we allocated on the heap! That's a memory leak!
    */
    MallocIntDangerous(numberPtr);

    printf("Original 'numberPtr' address after dangerous malloc: %p\n", numberPtr);
    printf("The above address for 'numberPtr' does not change!\n");

    /* 
        Function that takes in a pointer to a pointer to an int and malloc's
        memory to the dereferenced pointer to pointer.

        Below we pass the address of numberPtr to the function. If we pass the
        address of a pointer, we have created a pointer to a pointer (i.e. an
        address that when dereferenced, gives us another address).
    */
    MallocIntSafe(&numberPtr); 

    printf("'numberPtr' Address After Safe Malloc: %p\n", numberPtr);

    //  DON'T FORGET TO FREE THE MEMORY YOU ALLOCATED ON THE HEAP IN YOUR CALL
    //  'MallocIntSafe'!
    free(numberPtr);

    //  Good practice: Null your pointer after it's been freed to protect against
    //  double frees.

    numberPtr = NULL;
    return 0;
}

void AddOne(int num)
{
    printf("\n");
    printf("Num in 'AddOne' Function Is Received As: %d\n", num);
    ++num;
    printf("Num in 'AddOne' Function Is Incremented To %d\n", num);
    printf("\n");
}

void AddOneByReference(int *numByReference)
{
    printf("\n");
    printf("numByReference in 'AddOneByReference' Function Is Received As: %d\n", *numByReference);
    
    /*  
        Dereference the pointer to get the value stored at it's memory address!
        Dereference operator needs to be in brackets so the derefernece occurs
        first, otherwise we'll end up incrementing the pointer instead!
    */
    (*numByReference)++;
    
    printf("numByReference in 'AddOneByReference' Function Is Incremented To %d\n", *numByReference);
    printf("\n");
}

void PrintIntByReference(int* numberPtr) 
{
    printf("Printing Int => Address: %p | Value: %d\n", numberPtr, *numberPtr);
}

void PrintIntByValue(int number)
{
    printf("Printing Int => Address %p | Value: %d\n", &number, number);
}

void MallocIntDangerous(int *numberPtr)
{
    numberPtr = (int*) malloc(sizeof(int));
    printf("'MallocIntDangerous' => 'numberPtr' Address After Dangerous Malloc: %p\n", numberPtr);
    printf("'MallocIntDangerous' => ^^That Address Space Marks A Memory-Leaked Block!\n");
    //  numberPtr now goes our of scope... We've lost the malloced memory block
    //  and started a memory leak!
}

void MallocIntSafe(int **numberPtr)
{
    /*
        No memory leak here! :)

        Our pointer to a pointer is passed in and copied into a new piece of
        memory on the stack. This copied value references the memory address that
        points to our original int pointer in the main function!

        So if we want to switch the value this points to, we can now derference 
        our pointer to the pointer.
        
        In doing so, we have access to the pointer and can mutate the address 
        it points to. In this instance, we overwrite it with the pointer 
        (address) that the malloc function returns!
    */
    *numberPtr = (int*) malloc(sizeof(int));
}


