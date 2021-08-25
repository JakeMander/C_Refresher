#include <stdlib.h>
#include <stdio.h>

/*
    In order to fully understand arrays, you'll need to understand what
    multidimensional arrays are, and why/how they're used.

    Multidimensional arrays can be incredibly useful when used to solve
    particular problems. In this section, we'll mainly be focused on 2
    dimensional arrays (2D arrays).

    There's nothing stopping you from creating as many dimensions as you
    like (except maybe memory!), but it's worth noting that the more
    dimensions you have, the more complicated, confusing and unwieldy 
    your array is likely to become.

    Here's an example of a 2D array.


    Downloads       Age
    245             38
    78              27
    89              26
    25              43
    10              55

    A 2D array is essentially a table (much like you've probably come across
    already in maths or statistics). 

    In a 2D array, the rows are represented by the first dimension of the array
    and the columns are represented by the second dimension!

    Let's create our above table in a C multidimensional array (2D specifically).

*/

int main (void)
{
    /*
        The below example represents the table we created in the above comment.

        We've been able to map the table by declaring a 2D array! How did we do 
        this?

        Fairly similar to a normal 1 dimensional array! Only we provided a 
        second set of brackets initalized to a length of 2!

        Why 2?

        Because the number of columns we have in the table is 2! Downloads and
        Age!

        We leave the first dimension blank as we don't know how many rows we'll
        have! We'll let C figure that out when our code is compiled!

        If we compare our array to the table above, we'll see that it maps 
        identically. We have 5 rows and two columns for each!
    */
    int twoDimensionalArray [][2] =
    {
        { 245, 38 },
        { 78, 27 },
        { 89, 26 },
        { 25, 343 },
        { 10, 55 },

    };

    /*
        In order to access values stored in a multi-dimensional array, we can
        chain the array index access notation.

        For example, to access the first column, of the first row (245), we can
        do the following (remember, both are zero indexes! We start at 0 for 
        both rows and columns!):
    */
    printf("First Row, First Column = %d\n", twoDimensionalArray[0][0]);

    /*
        Above we are saying, for the first row found in our array,
        take the value found in the first column!

        Now to get the value stored at the second column of the first tow, we
        can do the following:
    */
    printf("First Row, Second Column = %d\n", twoDimensionalArray[0][1]);

    /*
        Third row, first column?

        Easy peasy:
    */
    printf("Third Row, Second Column = %d\n", twoDimensionalArray[2][1]);

    /*
        So how does this all look in memory?

        If we recall, C stores it's arrays in a single block of contiguous 
        memory. The same applies to multi-dimensional arrays!

        Different languages use different memory layouts for multi-diemnsional
        arrays. C adhered to the ROW MAJOR layout.

        How does the look in memory? Well the first row, first column takes the
        first block, then the first row second column takes the second block,
        then the second row, first column takes the third block and the 
        second row second column takes the fourth block... so on so forth.

        Essentially, memory is strucutred in order of rows, with each column
        element populating a block of memory. Rows and their values are 
        located sequentially! 

        The 'twoDimensionalArray' would look like this in memory:

         ________________________________________________________________________________________
        |          |          |          |          |          |          |          |          |                                                               |
        |  Blank   |   R0C0   |   R0C1   |   R1C0   |   R1C1   |   R2C0   |   R2C1   |   Array  | 
        |   Mem    |   245    |    38    |    78    |    27    |    89    |    26    | Continues| 
        |__________|__________|__________|__________|__________|__________|__________|__________|
    
        It's worth remembering that C uses the row major layout in memory, as
        this can have a number of performance impacts when performing 
        certain calculations on matrices. 

        So when should we use multi-dimensional arrays?

        As touched on previously, multidimensional arrays are great for 
        representing or working with tabular data in a C program.

        In addition, multidimensional arrays are great for providing a space
        efficient means of operating on data in memory. Applying calculations
        or business logic to tabular data, or data that can be transformed into
        tabular data, multidimensional arrays are really useful for this.

        Finally, any arithmetic that needs to be applied to matrices is easilly
        implemented with multidimensional arrays. If you need to calculate 
        transormation matrices in a graphics/game engine, chances are you'll
        use a multidimensional array to do this!

    */


    return 0;
}