#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    In this program we are going to build a system that can read data from
    structs and save them as raw binary data. You won't be able to read
    the output in the file that gets produced! In the next unit, we will build
    a program that will read the data and output the values! 

    In this exercise we will have our first encounter with basic file handing.  

    This will be explained in greater detail in a later module.

    In the example, we'll write sprinter data to a data file.
*/

//  Lanes run from 1 through 8 (4 bits required).
//  Distances are 50m, 100m, 150m, 200m (8bits needed)

struct Sprinter 
{
    unsigned int lane: 4;
    unsigned int distance: 8;
    char name[32];
};

int main() 
{
    /*
        Set up the variables we'll need to manage our created file. This includes:
            - The name of the file we'll want C to store our values in.
            
            - A File pointer so we can keep track of the file via the pointer 
              that is returned by C's standard file functions.
    */
    const char filename[] = "race.dat";
    FILE *fh;

    unsigned int lane;
    unsigned int distance;
    char name[32];

    /* 
        Open and create the file. Run fopen in "append" mode. This means if a 
        file can't be found in the root directory with the same name as the 
        provided filename parameter, a new file is created. Otherwise, the new
        data is appended to the end of the existing file.

        We assign our file pointer to the returned file pointer that comes from
        the fopen function.
    */

   fh = fopen(filename, "a");

   /*
        If the system cannot open/create the file, the pointer returned is 
        NULL. Handle this occurance with a message and exit with an error code.

        We'll print this out to the systems stderr stream. Typically, this is
        just the user's terminal screen (as is the standard output (stdout)).
   */

    if (fh == NULL)
    {
        fprintf(stderr, "\nError Opening File.\n");
        exit(1);
    }

    //  Prompt for input.
    printf("\n\t Name?: ");
    scanf("%31s", name);

    printf("\n\t Lane (1-8)?: ");
    scanf("%1d", &lane);

    printf("\n\t Distance (50-200)?: ");
    scanf("%1d", &distance);

    //  Declare and initalize our sprinter.
    struct Sprinter athlete;
    strcpy(athlete.name, name);
    athlete.lane = lane;
    athlete.distance = distance;

    //  Write the file.
    fwrite(&athlete, sizeof(struct Sprinter), 1, fh);
    fclose(fh);

    /*
        The data file should appear in the same folder that our executable 
        appears. But when opened we should see garbage values. This is because
        the file has been written as binary data and cannot be fully decoded.

        In the next exercise, we'll build the component that reads the data.
    */





}
