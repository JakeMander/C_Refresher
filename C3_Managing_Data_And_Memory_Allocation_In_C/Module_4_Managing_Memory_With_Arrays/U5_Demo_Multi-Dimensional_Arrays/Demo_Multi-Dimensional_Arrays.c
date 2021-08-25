#include <stdlib.h>
#include <stdio.h>

/*
    The following demo is similar to the "One Dimensional Array" demo!

    Here we'll be looking at how to declare and initalize multi-dimensional
    arrays as well as how to read and write to them.  
*/

#define ROWS 10
#define COLUMNS 4

int main(void)
{
    //  Declare and initalize a multidimensional array containing ten rows and
    //  four columns.
    int matrix[ROWS][COLUMNS] = 
    {
        { 1, 0, 1, 0 },
        { 0, 0, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 0, 1, 1 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 1, 0, 0, 1 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 },
    };


    //  Loop over each column within each row.
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("Array Value (Row %d, Column %d) Was: %d\n", i, j, matrix[i][j]);
            //  Perform the XOR bitwise operator on each value stored in the 2D
            //  array. Essentially flips the bits. 1 is now 0, 0 is now 1!
            matrix[i][j] = matrix[i][j] ^ 1;
            printf("Array Value (Row %d, Column %d) Is Now: %d\n\n", i, j, matrix[i][j]);
        }
    }

    return 0;
}
