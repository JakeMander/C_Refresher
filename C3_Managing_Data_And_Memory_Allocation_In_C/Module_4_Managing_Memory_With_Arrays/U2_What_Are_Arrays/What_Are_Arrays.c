#include <stdlib.h>
#include <stdio.h>
/*
    In this set of units, we'll be exploring how we can dynamically
    manage memory in C with arrays.

    Much like pointers, C arrays tend to get a lot of flak for being
    complex  and difficult to grasp, but they're foundational to writing
    well structured C code.

    Arrays can be used to manage data and memory efficiently!

    Once you're done here, you should be confident in handling arrays
    of both single and multiple dimensions, handling arrays of pointers
    and dynamically allocated arrays.

    But let's first start off by asking ourselves what an array is
    in the C language.

    The first thing to note is, if you've had expirience of other, more higher
    level languages in the past, C arrays function differently to arrays of
    higher level languages!

    In short, a C array is a container that houses elements of a single type
    within a single contiguous block of memory (i.e. the memory that houses
    all of these values is unbroken! It exists as a single chunk and all 
    elements live together side by side).

    It is a data structure used to store multiple values in sequence!

    Why do we need arrays?

    Without them, programmers would end up creating variable after variable to
    store the values we need. This wouldn't be practical! Lots of variables bloat
    code and make it difficult to maintain.

    With arrays, we can store multiple, commonly grouped values in a single 
    variable that can be indexed with different values to return different
    values!

    Arrays provide the added benefit of performing these reads and
    writes very quickly! Fast access is vital in program performance and 
    programmer convinience. As mentioned previously, this fast access is
    provided via the index operator!

    In addition, arrays are memroy efficient! As elements are stored in a 
    single contiguous block of memory, handling lots of memory stored in
    an array much quicker and reduces the complexity of handling vast
    qunatities of grouped data!

    Finally, arrays can also be multidimensional. This essentially means
    arrays can be composed together to form arrays of arrays. This provides
    the programmer the benefit of being able to strucutre data and enabling 
    them to represent structures such as matricies and tabular data in code.
    You'll typically come across these constructs in databases and game engines!

    We've covered arrays in course 2, but let's recap with an example:
*/

int main(void)
{
    /*  
        Here we declare a one dimensional array! We've done this before but
        let's just make sure we're clear on a few things:

            1. This array allocation is static. Why? It's inside a function (in
               this case, "main") and the initalization is not done using a
               dynamic allocation function like malloc, calloc or realloc.
               Therefore, this memory is allocated on the stack at compile time!
            
            2. We've defined an array of ints because we have defined the type 
               of 'int' and a name with a set of brackets. 

            3. The compiler determines the size at compile time based on how
               many elements we initalize the array with. This is because the
               brackets have no number provided by us!
    */
    int arr[] = {1, 2, 3, 5};

    /*
        So what does the above array look like in memory?

        Index:          0           1          2         3      
        __________________________________________________________________
        |          |          |          |          |          |          |                                                                 |
        |  Blank   |    Val   |    Val   |    Val   |    Val   |  Blank   | 
        |   Mem    |     1    |     2    |     3    |     4    |   Mem    | 
        |__________|__________|__________|__________|__________|__________|
    
        Address         100        104        108        112

        So on the stack, we now have a statically allocated block of memory
        that has been handled for us by the compiler. 

        Our set of indexes start with a zero index (i.e. the first index has)
        an index of 0, each element is an int and so takes up 4 bytes of 
        memory on a 64-bit Windows system, and each of our memory block 
        addresses that the elements are stord in are sequential! They live
        next to one another in stack memory! We are guaranteed that the first
        element lives next to the second element in memory.

        Finally, we'll end this unit with a rather confusing concept that
        you'll need to get your head around with arrays.

        This is the relationship between Arrays vs pointers.

        When you're reading C code, you'll often see an array being passed
        to a function with a signature that takes in a parameter of type 
        pointer. 

        This looks like the types don't match and should thus not be allowed by
        the compiler! But the compiler ends up being happy to let you pass an 
        array of a specified type in the parameter which is explicitly defined
        as a pointer of the same specified type.

        Why is this?

        The answer we have actually covered before in chapter 2! 

        ARRAYS DECAY TO POINTERS!

        By calling the name of an array, you are actually decaying an array 
        into a pointer! That is to say, calling the name of an array causes the 
        program to return the a pointer to the starting address of the block of 
        contiguous memory that forms your array!

        Because calling the name of an array gives you a pointer, passing the 
        name of an array as a parameter expecting a pointer to a value of a 
        specified type is valid in C! Calling the array name essentially 
        provides the pointer that the function is expecting!

        But take care not to get confused! An array is not the same as a 
        pointer! 

        Let's take a look at an example:

        void IterateThroughArray(int *arr, size_t size);
        int myArray[] = {1, 2, 3, 4, 5};
        IterateThroughArray(myArray, 5)

        In the above example, we can quite happilly pass in the array 
        "myArray" as the first parameter, because calling the array name causes
        the array to decay into a pointer that points to the array's starting
        address.

        Therefore in practice, we can say that:
        myArray == &myArray[0]
    */
}