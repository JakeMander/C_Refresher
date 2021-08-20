/*
    In this unit, we'll look at the dynamic memory management functionality 
    offered by the C standard library and how each function should be
    used when we need to perform dynamic memory allocation and deallocation.

    To access the core memory functions, we'll need to import the C stdlib.h
    file into our projects.

    There are four funamental C standard library functions we'll heavilly use
    in the management of memory in C. These are:

        - Malloc.
        - Calloc.
        - Realloc.
        - Free.

    We'll take a look at each one in more detail!

    First off, let's cover some general ideas surrounding memory allocation in C.

    When allocating memory, we are essentially requesting C to fence off a
    block of memory in the heap. To the system, it doesn't really matter
    what is stored there. It's all 1's and 0's to the system. It's the C
    code that gives meaning to these bits and determines how the value 
    stored in memory is handled and the behaviour we can implement when
    referencing the stored value.
    
    How large this portion of memory is typically given in bytes and is 
    defined by us! 
    
    For example, if we want to allocate a block of memory capable of storing
    a single int, we need to know how much memory an integer value takes up
    so we can tell C we need to reserve the correct number of bytes to allow
    for enough storage in memory for the bits that make up the int data type. 

    On Windows 64 bit archeitectures, an integer is 32 bits (4 bytes), so C
    needs to reserve 4 bytes of memory when allocating memory. 

    Once the correct amount of memory has been 'fenced off' we then need to 
    ensure we maintain a reference to that block of memory so we can assign a 
    value to our new set of fenced off memory and access and mutate the value 
    we eventually store in the allocated set of memory.

    In doing so, we achieve two goals:
        - We maintain a reference to the memory we have fenced off so we can
            come back and modify, reallocate or free it. If we didn't do this,
            the memory would be allocated but would be lost in the program.
        
        - We define the type of the value stored in our memory location so the
            C compiler knows what type has been stored in the new fenced off 
            section of memory! In estbalishing a reference to dynamic memory, 
            we must define a type. In doing so, we give meaning to the values 
            we store in dynamically allocated memory. 

    The C library functions typically handles this reference bookkeeping 
    through use of void pointers. An allocation function will return a void
    pointer which we can use to reference our allocated memory.

    The void pointer has no type (we call this "generic" - though eventually
    each value stored in dynamic memory will have a type, it's much easier
    to treat memory as typeless to simplify locating and handling memory).
    
    Void pointers simply point to a blocks of memory via a memory address.
    It doesn't matter what type this value is or what type we're storing
    at that location at this stage. C just needs to be able to locate where 
    this memory is so it can access it in the future! 

    The great thing about this is, when we're ready to start handling values
    stored in dynamic memory, we can cast a void pointer to a specific type.
    In doing so, the compiler is given meaning regarding what values are
    stored at the addresses the void pointers store! 

    This is important because, as a void pointer doesn't have an associated
    type, C has no way of knowing what value is stored at the location and
    how it should handle it. As such, void pointers CANNOT be dereferenced!

    Casting a void pointer to a pointer of a specific type, which is perfectly
    valid as C explicitly knows how to do this, gives the C compiler the 
    understanding it needs to dereference the value stored at the memory
    address!

    Finally, in order to iterate through blocks of dynamic memory we need some
    way of iterating through memory in C. This functionality is provided to us
    by the C language via pointer arithmetic. 

    It's not vital to understand what this means at this moment in time, but
    it is important to note that, as void pointers just point to an address
    and have no way of knowing how big the associated block of memory is 
    (it has no type to indicate the size of the value stored there), then
    pointer arithmetic is not possible on void pointers. As before, void
    pointers must be cast to a pointer of a specified type before iteration
    of memory can occur via pointer arithmetic.
*/

#include <stdlib.h>
#include <malloc.h> // For msize - Gets size of dynamically allocated memory.
#include <stdio.h>

int main (void)
{

    /*

        With the basics of memory allocation and how pointers play a role in
        this covered above, let's now start to look at the basic set of 
        functions provided to us by C to faciliate dynamic memory management.

        These are:

        Malloc:
        In terms of allocating dynamic memory, malloc is one of the most 
        commonly used functions in the C library. Given a size in bytes,
        malloc triggers a request for a block of memory from the heap.

        This size is the only paramreter accepted by the malloc function
        and is of type "size_t", an unsigned 32 bit integer. Typically,
        values of type "size_t" are returned by the C "sizeof" operator.

        Typically, sizeof is used with the type that is to be stored in the
        newly created memory block as a means of conviniently providing
        the number of bytes as the first argument. This allows for cross
        platform differences in type sizes! 

        If you want to define multiple bytes using malloc, then multiply
        the byte_size by the number of values you want to store in that
        block of memory.

        When a call to malloc fires, the function looks to see if a block of
        memory that matches the size of the request is available. If this is
        case, then the function returns a null pointer in anticipation of a 
        cast to the type the memory block is storing. 

        If the memory allocation fails, or no memory is available for the
        allocation, then malloc returns null.

        The signature of the malloc function is as follows:

        void *malloc( size_t byte_size)

        An example of using malloc to dynamically allocate enough memory for a
        single integer value is given below:
    */ 

   /*   In order to dynamically create a memory block big enough to store an int
        we must:

            - Delcare a pointer to an integer - We need to tell the C compiler
              that we'll be pointing to a block of memory that we expect to 
              contain an integer value.

            - Call malloc and allocate a block of memory that we're sure will
              have enough size to hold a integer value. We do this by passing
              in the result of a call to the sizeof operator which we pass in
              the int datatype to in order to determine the size of the int
              type on this system. 

            - Remember, malloc is generic! It returns a void pointer which simply
              points us to a memory block somewhere on the heap! We need to tell
              C exactly what it is we're expecting to find at this memory address
              by casting the null pointer to a typed pointer. In this instance,
              we're expecting an integer value at the newly created block of
              memory, so we need to cast it to a pointer to an integer!
    */ 

   int *pointer = (int*) malloc(sizeof(int));

   //   Define a block of memory big enough for 10 ints.
   int *pointerToMultipleInts = (int*) malloc(10 * sizeof(int));

   printf("Memory Address of New Memory Block: %p\n", pointer);
   printf("Size of Memory Location @%p is: %d Bytes\n", pointer, _msize(pointer));

   printf("Memory Address of New Ten Int Memory Block: %p\n", pointerToMultipleInts);
   printf("Size of Ten Int Memory Location @%p is: %d Bytes\n", pointerToMultipleInts, _msize(pointerToMultipleInts));
   

   // As we can see in the above example, we now have a single block of memory
   // big enough for an integer value!

   /*
        Another allocation function we can use is calloc! This operates almost
        exactly the same as malloc, the only difference being the parameters 
        the function takes in order to allocate the memory we need. 

        There are three main differences with calloc:

            - Unlike malloc, calloc takes two arguments. These are:
                
                - count: The number of blocks of memory you want to
                  create. Each block will be sized according to the
                  second parameter.

                - byte_size: The size of the type you are allocating.

            Calloc's signature can be quite useful in that it forces you to 
            define how many blocks of memory you want and how big each one
            should be in a single call.

            With malloc, if you want to store multiple values in your allocated
            blocks of memory, it can be easy to forget to multiple the byte size
            by the number of variables you want to store!
            
            - With malloc, you don't know what your allocated memory is going
              to start off with. Typically it will contain garbage values from
              previous computation.

              Calloc "zeroes out" the newly created memory, replacing all of 
              the bits stored in the defined block of memory with 0's. 

            - Calloc is slower than malloc in terms of performance.
        
        So in short, calloc allows us to define multiple blocks of memory
        of a specified size in one fell swoop, and initalises these blocks
        of memory so that each bit is set to 0 when the memory is
        initialized. 

        Despite these differences, calloc is used in exactly the same way
        as malloc. Calloc returns a void pointer which needs to be cast
        to the type you expect to store at the allocated block/s of memory.

        The function signature for calloc is as follows:

        void *calloc(size_t count, size_t byte_size)

        Let's now take a look at calloc:
   */

  int *callocPointer = (int*) calloc(1, sizeof(int));
  printf("\nMemory Address of New Calloc Memory Block: %p\n", callocPointer);
  printf("Size of Calloced Memory Location @%p is: %d Bytes\n", callocPointer, _msize(callocPointer));
   
  //   Define a block of memory big enough for 10 ints
  int *callocPointerToMultipleInts = (int*) calloc(10, sizeof(int));
  printf("Memory Address of Calloced New Ten Int Memory Block: %p\n", callocPointerToMultipleInts);
  printf("Size of Calloced Ten Int Memory Location @%p is: %d Bytes\n", callocPointerToMultipleInts, _msize(callocPointerToMultipleInts));


  /*
        Let's now take a look at memory reallocation!

        There may be instances where a block of memory we allocate needs 
        resizing. This could be to either make more room for other values
        in memory, or that a block of memory is no longer big enough to
        store the values we need and needs expanding to provide enough
        space for more values. 

        In either case, we can use realloc to change the size of block of
        memory that has been allocated using either malloc or calloc.

        realloc works by taking in a pointer to the the memory block we wish to
        resize and a second parameter which represents the new size we want the
        memory block to take. 

        The arguments are as follows:

        - void *ptr - A void pointer to the block of memory to resize.

        - size_t byte_size - The size that the memory block is to be resized to.

        Realloc returns a void pointer to the start of the resized block of
        memory. As with malloc and calloc this needs to be recast to the type
        the memory block is expected to store.

        The function signature is as follows:

        void *realloc (void *ptr, size_t byte_size)

        Again, always bare in mind that realloc can only point to memory blocks
        that have been dynamically created on the heap via malloc or calloc!
  */

   //   Increase the size of the callocPointerToMultipleInts from 10 ints to 15.    
   int *reallocedPointer = (int*) realloc(callocPointerToMultipleInts, 15 * sizeof(int));
   printf("\nMemory Address of Realloced New Ten Int Memory Block: %p\n", callocPointerToMultipleInts);
   printf("Size of Realloced Ten Int Memory Location @%p is: %d Bytes\n", callocPointerToMultipleInts, _msize(callocPointerToMultipleInts));

   /*
        Finally we come to one of the most important aspects of memory 
        management which is deallocation!

        Always make sure that when you're finished with memory, it gets 
        deallocated with a call to the free function! Otherwise your
        code will spring a memory leak! That means you'll have memory
        floating around that the operating system believes is still in
        use and will no longer be able to use for the duration of the 
        program's lifespan. If the leak is significant (i.e. think of
        a huge recursive loop that allocates huge swathes of memory)
        then you run the risk of crashing your program through a
        memory overflow.

        The free function is simple enough to use and requires one argument.

        This argument is:

        - void *ptr ptr: A pointer to the block of memory you want to
          free.

        When called, the C library free function goes to the start address
        of the memory block that ptr points to and releases the entire
        block of memory so that it can be reallocated by another call
        to one of the allocation functions or the realloc function. 

        In doing so, we have not wasted memory and are able to re-use 
        it for future dynamic memory management.

        The signature for the free function is simple enough:

        void free(void *ptr)

        Let's deallocate some memory!
   */
    free(pointer);
    free(pointerToMultipleInts);

    /*
        Note that checking memory has been freed in C is impossible using C
        library functions! You need to do your own bookkeeping when checking
        that memory has been freed up! 

        Also note that _msize is a Windows API extension used to debug memory
        management. It is not suitable for production code! Make sure you
        maintain your own memory bookkeeping when allocating, reallocating 
        and deallocating memory.
    */
    return 0;
}