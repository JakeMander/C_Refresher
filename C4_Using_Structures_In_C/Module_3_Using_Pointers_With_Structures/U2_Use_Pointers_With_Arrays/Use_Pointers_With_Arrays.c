#include <stdio.h>

/*
    In the last unit we were reintroduced to using pointers.

    In this unit we'll be reintroduced to using pointers with arrays.

    Here we have a simple array of prime numbers. Below, we iterate through the
    array and print our all of it's stored elements. Nothing special here.

    However, what happens if we try and use a pointer to access our primeNumbers
    array?
*/

void main (int argc, char* argv)
{
    int primeNumbers[] = {3, 7, 11, 17, 19};

    for (int count = 0; count < 5; count++)
    {
        printf("\n\t #%d: %d", count + 1, primeNumbers[count]);
    }
    printf("\n\n");

    //  Declare a pointer that points to a prime number.
    int *primePtr;

    //  Declare a pointer that points to the first element of an array
    //  but which will not be edited.
    int* readonlyPrimePtr;

    /*  
        What happens if we use a pointer with an array?

        In the below section we should notice that we don't need to use the '&'
        when assigning an array to a pointer. If you cast your mind back to the
        some of the work we've done before, you'll remember that C implicitly
        implements arrays through pointers and pointer arithmetic. 

        So making a call to the primeNumbers array will cause the program, 
        behind the scenes, to decay the array into a pointer which points
        to the memory address of the first element. More specifically, arrays
        will DECAY into pointers when called.

        Notice how our pointer when assigned the array returns the same value
        as indexing the first element directly.
    */
    int *decayedPointer = primeNumbers;
    printf("\n\t#%d: %d\t%d", 1, primeNumbers[0], *decayedPointer);
    printf("\n\n");

    /*

        Also remember that in C, because arrays and pointers are closely 
        related (they are not, however, the same thing!), we can iterate
        through them using either the array notation and the pointer,
        or we can use pointer arithmetic.

        Why? Because:
        
        primePtr[2];

        Is essentially the same as calling

        *(primePtr + 2)

        Which is essentially the same as doing:

        primePtr + (sizeof(int) * 2);
    */
    primePtr = primeNumbers;
    readonlyPrimePtr = primeNumbers;

    //  This loop demonstrates how array index notation and pointer arithmetic
    //  yield the same results when accessing an array.
    for (int count = 0; count < 5; count++)
    {
        printf("\n\t#%d: %d\t%d", count + 1, readonlyPrimePtr[count], *primePtr);
        //  Increment our writeable pointer by the size of an integer (2 bytes) each time.
        primePtr++;
    }
    printf("\n\n");

    /*
        There is one final way we can use pointers to access elements in an 
        array.

        As we know, the array index notation looks up the memory address 
        found by jumping across however many memory steps implied by the
        index (for example, an index of 1 for an array (2nd element when
        non zeroed) implies to C that we should move 8 bytes to get to
        the second element in an array of integers) AND dereferences the
        value stored there.

        In some instances, we may want to store the address of the element
        we iterate to using our index. To do this, we need to store the 
        address of the returned value we indexed using the array notation
        (we undo the automatic dereference to just give us the address).

        For example:
    */

    for (int count = 0; count < 5; count++)
    {
       //   Stores the address of whatever element is at index "count".
       primePtr = &primeNumbers[count];

       //   Compare the dereferencing of a pointer pointing to each element
       //   via the '&' assignment against a direct index of each element.
       printf("\n\t#%d, %d\t%d", count + 1, primeNumbers[count], *primePtr);
    }
    printf("\n\n");

    /*
        Finally, let's directly extract our result by dereferencing the result
        of some pointer arithmetic where our pointer points to the start of
        the array, but the amount we increment by changes.
    */
    for (int count = 0; count < 5; count++)
    {
        printf("\n\tPointer + %d: %d\t%d", count, primeNumbers[count], 
        *(readonlyPrimePtr + count));
    }
    printf("\n\n");
}