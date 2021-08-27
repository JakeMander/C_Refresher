
#include <stdlib.h>
#include <stdio.h>

/*
    In this example, we'll explore how we can use dynamic memory to manage
    arrays on the fly. So far we've only seen static based arrays. As we've
    already seen, these elements are declared and initalised with the array
    bracket syntax. The memory required for these variables is determined at
    compile time by the compiler and stored on the stack.

    In this section, we'll explore their dynamic equivalent.

    The memory for dynamic arrays is stored on the heap. This gives you a 
    flexible alternative compared with statically allocated arrays - which
    are of fixed size (Remember, you can't resize arrays you allocated with
    the array syntax! C won't let you!).

    With dynamically allocated arrays however, arrays can be resized on the
    fly at runtime with realloc. All elements in the array are maintained, 
    but the arrays are resized to the new specified size. 

    This resizing occurs at runtime. The program will determine what the new
    memory block size should be as it runs.

    This is incredibly useful! It enables us to confidently define or resize
    arrays on the fly. If we don't know how big an array is then we don't 
    need to guess (prone to error!) or assign a really big array to account for
    the possiblity of extra values (really inefficient!).

    Instead, we can figure all this out at runtime and then use dynamic memory
    allocation to build an array on the heap that is big enought to house all
    of the elements we know we have. If the situation changes later on, that's
    fine! We can just resize the array!

    This is really useful for large arrays! With static arrays, it can be really
    difficult to specify the exact number of elements we'll need for an array.

    This tends to result in us either coming up too short (i.e we need more space
    for elements we've accidentally missed out), or we end up allocating too much
    memory with some of this never actually being used or needed - not good for
    program performance!
*/

/*
    Function Prototypes
*/
int* CreateVLAExample(size_t size);


int main (void) 
{
    /*
        Example: Let's imagine we've declared an array which we think will need
        to store only 3 values. 
        
        What happens when we realise we need 4?

        Well we can try and assign a fourth element using index 3, but this is
        a REALLY BAD thing to do. You've left the array bounds and entered
        memory that is not allocated for that array!

        That memory could have been used for another variable, and you've just
        overwritten some of it's data which will cause undefined behaviour
        in the program somewhere, or, when you initalize a variable later on
        in the program, it will be allocated to the memory used to your 4th
        element as that block of memory hasn't been flagged as used by your 
        array, and the OS thinks it's free memory!
    */
    int array[3] =  { 0, 1, 2 };
    array[3] = 3; 
    array[4] = 4;

    /*
        If we recap to the following module, the following code should look
        very familiar:
    */
    int *arr = (int*) malloc(4 * sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    /*
        The above code has allocated a block of memory on the heap large 
        enough to contain 4 integers.

        If we look at the in memory representation of this, we get:

                    0       1       2       3
        ________________________________________________
        |       |       |       |       |       |       |
        |       |       |       |       |       |       |
        |       |       |       |       |       |       |
        |_______|_______|_______|_______|_______|_______|  
                   100     104     108     112

        We have a single contiguous block of memory which has been assigned
        dynamically... this looks familiar! It's essentially an array we have
        declared!

        The numbers at the top of each segment of memory consitute the array
        indexes.

        When accessing the dynamic memory, we can use array indexes and pointer
        arithmetic to access elements inside a dynamically allocated array.

        However, as mentioned previously, the array notation should always be
        favoured over pointer arithmetic except in exception cirucmstances.
    */

    printf("Dynamic Array Pointer Arithmetic (index 0): %d\n", *(arr));
    printf("Dynamic Array Pointer Arithmetic (index 1): %d\n", *(arr + 1));
    printf("Dynamic Array Pointer Arithmetic (index 3): %d\n\n", *(arr + 3));

    printf("Dynamic Array Array Index (index 0): %d\n", arr[0]);
    printf("Dynamic Array Array Index (index 1): %d\n", arr[1]);
    printf("Dynamic Array Array Index (index 3): %d\n\n", arr[3]);

    /*
        Now let's say we want to expand the allocated memory we've assigned
        for "arr" by two integeers. We can do so with realloc like so:
    */

    arr = (int*) realloc(arr, 6 * sizeof(int));
    arr[4] = 5;
    arr[5] = 6;

    /*
        The above realloc has now resized the original "arr" block of memory
        into the following:

            0       1       2       3       4       5
        ________________________________________________
        |       |       |       |       |       |       |
        |       |       |       |       |       |       |
        |       |       |       |       |       |       |
        |_______|_______|_______|_______|_______|_______|  
            100    104     108     112     116     120
    */
    
    printf("Dynamic Realloced Array Array Index (index 4): %d\n", 
    arr[4]);

    printf("Dynamic Realloced Array Pointer Arithmetic (index 5): %d\n", 
    *(arr + 5));

    /*
        Before we move on, let's quickly take a look at variable-length arrays.

        The C99 standard saw a brand new addition in the form of 
        "variable-length arrays" (VLA's). 

        These are automatically allocated stack based arrays whos size is 
        computed at runtime instead of compile time.

        Here we can see an example of a function that creates a variable length
        array:

        It's been commented out here because VSCode and the C extension uses the
        MSVC compiler which doesn't use the C99 standard. If you're using a C99 
        compiler, uncomment it out and give it a try!
    */
    
    // int *variableLengthArray = CreateVLAExample(5);

    /*
        With VLA's covered, we can now look at how we can go about dynamically
        allocating multidimensional arrays. 

        The introduction of VLA's has allowed us to perform a really handy 
        trick when dynamically attempting to allocate multidimensional arrays.

        The traditional problem was, C goes out of it's way to make dynamic
        allocation and the handling of pointers really easy by automatically
        figuring out how big the types are for you, and handling the pointer
        arithmetic required for you to add, subtract, multiply and divide 
        such address values by other pointers, and by numbers that represent
        the number * sizeof type.
        
        For example, let's say we have just allocated a dynamically assigned
        block of 4 integer values. 
        
        If C didn't do the heavy lifting for us, if we wanted to shift the 
        pointer to the third integer,  we would have to increment our pointer
        like so:

        int *intPointer = malloc(4 * sizeof(int));
        int thirdValue = intPointer + sizeof(3 * int)

        Thankfully, Dennis Ritchie and Ken Thompson knew programmers were lazy
        and wouldn't like having to repeat the sizeof operator call! So they
        built C to know what size the types need to be for the targetted 
        system... As a result, you can get away with the following:

        int thirdValue = intPointer + 3;

        Another interesting quirk of C is that pointer arithmetic ended up 
        making C's arrays and pointers closely interrelated concepts. 

        Notice how in C, a reference to a single dimension array like so:

        array[2];

        Essentially equates to the dereferencing of a pointer like so:

        *(array + 2)

        That's really useful for dynamically allocating a single dimension
        array, because, even though we're using pointers, we can treat it as if
        it were a single dimensional array, complete with boundaries by using
        the array index notation (which is essentially the same as pointer
        arithmetic). This is really a nice C feature! Array notation is simple
        and intuitive. It really compliments the single contiguous block of 
        memory! 

        I just have to go:

        float *a;
        a = malloc (n * sizeof(float))
        for (i = 0; i < n; ++i)
        {
            a[i] = 1.0
        }

        And I now have a a dynamically allocated block of n elements all 
        initialized to 1.0... Really easy to do. Really easy to read.

        This works nicely because we don't need to know the size of the array
        to index into it. We just need to know the size of the element!
        
        Because the a pointer knows it's handling floats, it knows that each
        element is of size 4 bytes and we can just use n to provide the index
        via our nice clean array notation.

        But what if i want to do something similar with a dynamically allocated
        two-dimensional array?

        Well we then start to lose out on all the hard work C has put in to make
        pointer arithmetic and array access nice an intuitive. Why? Well it goes
        back to the Row Major approach C takes to laying out multidimensional
        arrays.

        Let's go back to our earlier tabular data example:

            Downloads       Age
            245             38
            78              27
            89              26
            25              43
            10              55
        
        Due to the Row Major memory allocation, in memory our 5 x 2 table 
        actually looks like this in memory:


                    1 Row = 8bytes (2 x 4 byte columns)
                              |
                    _____________________
         ________________________________________________________________________________________
        |          |          |          |          |          |          |          |          |                                                               |
        |  Blank   |   R0C0   |   R0C1   |   R1C0   |   R1C1   |   R2C0   |   R2C1   |   Array  | 
        |   Mem    |   245    |    38    |    78    |    27    |    89    |    26    | Continues| 
        |__________|__________|__________|__________|__________|__________|__________|__________|
                        0          1          2          3          4           5
        So to essentially traverse the rows in the above memory representation
        of our 2D array, we need to increment a pointer by i x n, where i
        is the row index we want, and n is however many columns are in each 
        row.

        It works like so:
        Row 0 = 0 x 2 = 0 (Index 0: arr[0] = First element of row 0).
        Row 1 = 1 x 2 = 2 (Index 2: arr[2] = First element of row 1).
        Row 2 = 2 z 2 = 4 (Index 4: arr[4] = First element of row 2).

        Now to select whatever column we want, we just need to add an offset to
        the above starting row index value we calculated to get the row we were
        after. For example, let's say we want the second column on row index one.

        Row 1 = 1 x 2 = 2.
        Column 1 = (1 x 2) + 1 = Index 3: arr[3] = Second Element of row 1.

        Or, if we want the first value of the second row:

        Row 2 = 2 x 2 = 4.
        Column 0 = (2 x 2) + 0 = Index 4: arr[4] = First element of row 2.

        A simpler expression for this is:

        a[i x n + j]

        Where:
        i = index of the row we want to access.
        n = the number of columns there are to a row.
        j = the column index we want to access. 

        But in code, this looks something like this:

        float *a;
        a = (float*) malloc(m * n * sizeof(float));
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i*n+j] = 1.0;
            }
        }

        Oh no! All of C's nice, succint array notation has become bloated with 
        verbose and unintuitive arithemtic!

        (See more at this really useful article by Randy Meyers: https://www.drdobbs.com/the-new-cwhy-variable-length-arrays/184401444)

        Instead, there are two alternative approaches we can use. These are:

            - Malloc a block of memory containing pointers to other malloced
              memory blocks. We end up with an array of arrays.
            
            - Use variable length arrays.

        To create a dynamically allocated multi-dimensional array, we can perform the following:
        
    */
    int numberOfRows = 5;
    int numberOfColumns = 5;
    int **arrayRowsPointer = (int**) malloc(numberOfRows * sizeof(int*));

    for (int i = 0; i < numberOfRows; i++)
    {
        arrayRowsPointer[i] = malloc(numberOfColumns * sizeof(int));
    }

    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            /*  
                Equivalent to the following pointer dereference: *(*(arrayRowsPointer + i) + j).
                I.e.  Derference the starting address of each element in the row tp get the
                starting address containing our column elements. Then increment the memory
                address that points to the start of each column by whatever column we want
                to read.
            */
            arrayRowsPointer[i][j] = i * j;
            printf("Value at Dynamic 2D Array, Index (%d, %d): %d\n", i, j, arrayRowsPointer[i][j]);
        }
    }

    //  Now don't forget! We now need to deallocate each malloced set of column
    //  values to stop memory leaks!
    for (int i = 0; i < numberOfRows; i++)
    {
        free(arrayRowsPointer[i]);
    }

    //  Finally, free the memory containing our pointers to the columns!
    free(arrayRowsPointer);

    /*
        The above code works, but is slightly long winded! It also requires you
        to go back through all of your pointers and deallocate them!

        If you're using the C99, a much simpler approach is to use variable 
        length arrays.

        The decleration below can get a bit confusing, so let's break it down:

        int (*arr)[rows][columns] = malloc(sizeof(int[rows][columns]))

        First off the right side.

        Here, via malloc, we create a pointer to a block of memory of the size
        of a variable length array. This size will be determined at run time,
        but is essentially the size of 4 * number of rows * number of columns.

        The pointer returned from malloc points to the starting address of the
        memory block which has the size of our defined VLA.#

        Now the left side of the expression.

        Here we have a complex declerator (i.e. lots of things going on in our
        decleration). The brackets simply tell C to look at this part of the
        declerator first. 
        
        Here we have our variable identifier "arr". We prefix this with a 
        * to tell the compiler that arr is a pointer.

        But a pointer to what? Well we take whatever is on the right of
        the brackets which is a VLA! So arr is a pointer to a VLA.

        But now we're left with int. That evaluates to the type decleration
        which is int! So we can say:

        "variable arr is a pointer to a VLA of integers!" 

        It's worth noting you may also see 
        
        int (*arr) [columns] = malloc(sizeof(int[rows][columns]))

        This should be the same as the above initalization. The number of 
        columns tells C all it needs to know on how to conduct pointer
        arithmetic. If it knows this, it can determine how to increment
        on a row by row basis with an index of arr[i][j].

        Say [columns] ends up being 4 (i.e. 4 columns per memory block in
        our contiguous set of memory). Then C knows it needs to increment
        by 4bytes x 4 to move between rows!

        More details on complex declerators can be found here:
        - https://docs.microsoft.com/en-us/cpp/c-language/interpreting-more-complex-declarators?view=msvc-160
        - C99 standard (Section 6.7.5) http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf


        By using this syntax, we essentially create in memory a block of
        memory that conforms to the Row major memory layout.

        The advantage to this approach is, because we have the row major
        layout but can access our memory block using arr[i][j] syntax,
        we have a simple format that can be deallocated as a single
        block of memory. If we use an arry of pointers, our memory
    */


    return 0;
}


/*
    Note this function will not work in VSCode/ Visual Studio if they are set 
    up to use the MSVC compiler. MSVC IS NOT a C99 standard compiler and 
    therefore does not support VLA's. 

    Because this array is statically allocated (i.e. stack allocated). It will
    be deallocated once the function is completed.

    There is a problem with VLA's. In the below example, what's keeping myArray
    from being initalized to a huge value that wipes out a good chunk of our 
    program's available memory?

    Nothing! If size ends up being a huge number, the array's size will be huge
    too.

    As such, use VLA's with caution. Guards should be put in place before 
    initalizing a VLA to make sure it's initalised within a sensible range of 
    size values!

    If you're using a compiler that supports C99, uncomment the function and try
    it out!
*/

/* int* CreateVLAExample(size_t size)
{
    double myArray[size];

    for (int i = 0; i < size; i++)
    {
        myArray[i] = i;
    }

    return myArray;
} */
