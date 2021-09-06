#include <stdlib.h>
#include <stdio.h>

/*
    There are a number of issues a C app which utilises dynamic memory
    allocation can run into.

    In this demo, we'll cover some common pitfalls and look at how we can avoid
    them appearing in our own apps.

    In this unit, we'll also look at the role memory pools and custom memory 
    managers play when it comes to dynamic memory allocation in a C app.

    As a starting example, let's say we have a C app that makes calls to the 
    dynamic memory functions of C to allocate memory on the heap.

    When our application is a C app that places a high valoue on performance,
    and thus makes a small number of calls to malloc, and allocates memory on 
    the heap in small batches at a time, everything should appear to run fine.

    However, as the number of calls to malloc increases, performance will 
    decrease. This is because each subsequent call to malloc will causes
    a degredation in performance. 

    This is because each call to malloc invokes a system call to the OS for
    more memory. If the system calls are too numerous, we end up with a 
    phenomenon known as "heap fragmentation".

    Fragmentation occurs when you have free memory available in your programs
    total allocated memory, but the address space of each remaining chunk of 
    memory is so small and fragemented that the OS cannot allocate blocks
    of memory big enough for your application to practically use.

    This can result in out of memory errors! But that's not all. The large 
    number of calls to malloc can introduce latency to your program.

    So how can we solve this issue?

    One solution to the problem of memory fragmentation and slow performance
    due to excess malloc calls is the implemntation of a construct known as a
    "memory pool".

    Let's take the above example, where we make multiple calls to malloc and take
    the performance hit as a result. For this, we can introduce a memory pool which
    is essentially built from a custom memory manager structure.

    This memory manager then makes a single call to malloc for the entirity of the
    applications memory needs. In essence, the memory manager requests a single
    big block of memory from the OS off the bat, and then handles the distribution
    of this to the application's needs internally!

    If you make a call to one big block of memory, you avoid fragmentation! Why?
    Because you now have a single contiguous block of memory to play with that
    you have full control over. By using a manager, you can make sure memory is
    allocated from the tail end of the already allocated memory from your pool,
    thus preventing the emergence of gaps in your memory!

    In addition, as you only make one call to the OS, you improve peformance by
    avoiding the need to constantly badger the OS for memory, thus bypassing
    the performance hit encountered through such an approach.

    So when might we need a memory pool? Well, we could use a memory pool for:

        - Fixing performance issues in apps making large numbers of calls to 
          malloc/realloc.

        - Providing tigher control over memory allocation.

        - Provides less fragmenration when allocating lots of objects.

        - Customised memory allocation. In some instances, you may need a fine 
          grained approach to handling your memory needs. Malloc offers a great
          general purpose approach to handling memory management, but it may
          not suit every app's needs! Sometimes calls to malloc are best 
          managed in your own way.

    Let's now take a look at some of the inner workings of a memory pool. Here,
    we'll cover Fixed-size memory pools. 
    
    These are memory pools where each chunk of memory contains a fixed size of 
    memory. For example, a fixed memory pool may contain five blocks of memory
    each which contain 4,096 bytes of memory. 

    To fulfil this memory pools needs, the program needs to make one call to 
    malloc for 20,480 bytes of memory (4 x 4096 bytes). The memory pool 
    manager then becomes responsible for allocating and freeing these five
    chunks of memory as the app requests them. 

    For example, instead of the app making calls to malloc, the application 
    allocates a chunk of memory from the pool. The benefit to this is,
    you can then customise the memory pool and memory pool manager to the
    specific needs of your application!

    For example, you may have a memory manager that works well on a 32-bit
    operating system using a 4-byte word boundary, or a memory pool
    manager that works with 8-byte boundaries on a 64-bit machine.

    The memory pool manager itself is a wrapper around a given memory pool
    and provides the API which handles the allocation and freeing of memory
    on the memory pool. A simple memory pool manager might contain:

        - A MemAlloc() function: For allocating a chunk of memory for the
          pool.

        - A MemRealloc() function: For a variable size memory pool in order to
          provide the ability to provide different sized chunks of memory to
          be allocated.

        - A MemFree() function: Allows for the freeing chunks of memory such 
          that chunks of memory inside the allocated memory pool are freed
          up and marked as available for reallocation for new values.

    The beauty of this approach is that no sytem calls are made to the OS (unless
    you specify that the memory pool should make a call to malloc or realloc after
    running out of memory! 
    
    This increases performance by reducing the latency incurred as a result of calls
    to the OS but also provides fine tuned control over how your application consumes
    memory during as it runs. 
*/

int main (int argc, char* argv[])
{

}