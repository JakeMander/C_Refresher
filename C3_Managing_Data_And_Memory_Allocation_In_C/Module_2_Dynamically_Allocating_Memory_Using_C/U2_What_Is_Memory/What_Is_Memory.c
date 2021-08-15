/*
    The power of C is it's a mid-level programming lanaguage that is easy to
    read and understand and abstracted away just enough from the hardware to
    provide a simple enough interface to write performant, portable code whilst
    being low level enough to provide direct access to a system's memory in
    order to allow the programmer to carefully control how their program 
    operates and manages memory under the constraints of a system. 

    Memory management in C is critical to being able to harness the power
    of the language.

    In this course we'll be exploring how to use memory management and the 
    various tools C provides the programmer to allow them to have control
    over how memory get's allocated, reallocated and freed. 

    Before we dive deeper however, we'll recap on how system memory works 
    in conjunction with our code. 

    First off, if you're not already clear, let's explore what RAM is.

    RAM is Random Access Memory. It's the high speed memory program's use
    to quickly store the inputs and outputs of computations that need to
    be read and written to quickly.

    Why not use the system's storage like a drive of some sort?

    Well that medium of storage is significantly slower than RAM 
    memory. With those mediums, the disk needs to be read, and the values
    we need located from a huge block of storage memory.

    Instead, RAM allows us to cache values close to the program and quickly
    load values to or from the CPU and it's registers for processing. This
    is important for program performance. IF the program has to wait for a 
    disk to find values, then program's will end up stalling until they have
    the values they need.

    Instead with RAM, the CPU spends less time idle waiting for the data it
    needs and can almost immediately pull in the values the program needs
    from the cached set of data in RAM. 

    There's a lot more to it than this. There's concepts such as Virtual memory,
    pages and paging and much more, the key is just know that RAM is key to
    how a C program stores things such as variables, globals and dynamically
    allocated memory and one of the reasons why C is considered to be so 
    powerful.

    Let's recap and build on some concepts discussed previously.

    A block of memory used for a C program is seperated into different
    segments used to handle different data. There are four in total.

    The first two we have covered before, these are:

        - The Stack: This is where all local variables and the argument
          variables for a function to run are stored. This portion of
          memory takes the form of a "stack" data structure, where new
          initalised function arguments and locally scoped variables 
          are placed onto the top of the stack in a "first in last out" 
          approach. Values are popped off the stack when needed. Due to this
          approach, memory access is quick! 

          The stack in memory consists of a contiguous portion of memory
          allocated by the OS for a specific running program. This block
          is typically shared with the heap section of memory. If you
          run out of room and try and allocate more variables to the
          stack, you end up with stack overflow.

          This is in part due to both the stack and heap growing when
          more values are added to each section. 

          Let's have a look at a diagram:

          --------------
          |            |
          |            |
          | The Stack  |
          |   Grows    |
          |   Down     |
          |            |
          --------------
          |            |
          |            |
          |  Free      |
          |  Memory    |
          |            |
          |------------|
          |            |
          |  The Heap  |
          |   Grows    |
          |     Up     |
          |            |
          |            |
          |            |
          --------------

          As we can see, the free space eventually get's consumed by
          the stack and heap as both sections have more data added to
          them by the program as it runs so it's important to manage
          memory carefully so as not to overflow memory.

          The stack is essentially managed automatically by C for us.
          We can't manually manipulate the data stored here. C adds
          data here for us when we create variables, and takes values
          off when they run out of scope. 

        - The Heap: Is a section of memory that resides in the same 
          block of free memory that the stack lives in. Whereas the
          stack is automatically managed by C to store the local 
          variables and function arguments, the heap handles all
          of the variables we dynamically assign (i.e. the variables
          we explicitly tell C we want to manage).

          In this course, the heap is the section of memory we'll
          be most concerned with.

          As mentioned, it's important to note that both the stack 
          and heap grow towards each other and consume resources
          from the same block of memory. So as both sections grow,
          the less memory your program will have to play with.

    In C there are also two different memory segments we've not yet
    come across. These are:

        - Code (Text): This segment is where the compiled machine code 
        lives. The CPU runs the machine code that is stored in this
        segment. Typically, the memory here is read only. The CPU will
        take whatever code is stored here and process it but will
        not write any output to this section. This is so your program
        is not modiofied after compilation.

        - Data: This segment can be broken up into smaller segments, but
        for the purposes of this unit, we'll keep things simple and classify
        it as a single block of memory.

        The data section is where all of the global variables are stored.

        These will be any variables that are declared outside of a function,
        or any variables that have been defined as static.

    With an understanding of the different memory segments C uses, let's
    move on to comparing how static and dynamic memory allocation compare
    against one another.
*/