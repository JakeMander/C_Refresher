#include<stdlib.h>
#include<stdio.h>

//  Same as before. We need a struct to write the binary data to.
struct Sprinter 
{
    unsigned int lane: 4;
    unsigned int distance: 8;
    char name[32];
};

int main (int argc, char *argv)
{
    //  Same as before, variables to handle file access and management.
    const char filename[] = "..\\U4_Writing_Raw_Data\\race.dat";
    FILE *fh;

    //  Variable to hold an athlete's data as we read each one one by one
    //  until we reach the end of the file (EOF).
    struct Sprinter athlete;

    //  Open the file in "Read only" mode. 
    fh = fopen(filename, "r");

    //  Handle invalid files.
    if (fh == NULL)
    {
        fprintf(stderr, "\n\tError Opening File. \n\n");
        exit(1);
    }

    /*  
        Begin loop to extract data. Keep reading the number of bytes equal to
        the size of our Sprinter struct, but only increment the file pointer
        by this amount each time. The while loop will make sure we get all
        of our athletes. When we hit the end of the file, NULL is returned
        and false is returned, thus exiting the loop.
    */
   while(fread(&athlete, sizeof(struct Sprinter), 1, fh))
   {
       printf("\nName: %s\nLane: %d\nDistance: %d\n\n",
       athlete.name, athlete.lane, athlete.distance);
   }

   fclose(fh);
}