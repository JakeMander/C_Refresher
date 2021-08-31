/*
    Wired Coffee have been in touch again. They've been having trouble with a
    stack overflow error and they've isolated the problem to variable length
    arrays being initalised with values that are too big! This is causing 
    our arrays to take up memory outside the allocated stack space and
    they're running into all kinds of undefined behaviour!

    Lets start off by diagnosing the problematic VLA. From there, let's replace
    these memory hungry VLA's with dynamically allocated arrays instead. The
    heap tends to be of larger size and is more suitable for larger data
    structures!#
    
    Once we've done that, let's provide safe fallbacks in the case that there is
    not enough memory on the heap to allocate.

    Please note, the demo uses VLA's to start with an will not run if compiled 
    using a compiler that does not suppport C99 or C11
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
    Defines a safe default amount of memory to allocate for metrics in the
    event the user attempts to allocate more memory than the system has
    available for our metrics.
*/
#define DEFAULT_SIZE 1000


/*
    Function Prototypes

*/
double GetRandomNumber();
void GatherMetrics(size_t size, double *metricArray);
 
int main(int argc, char*argv[])
{

    //  Set a safe default size for our metrics to be stored in, then check for
    //  valid user arguments that define a size and attempt a conversion. 
    int arraySize = DEFAULT_SIZE;

    if (argc > 1)
    {
        arraySize = strtol(argv[1], NULL, 10);
    }

    /*
        Original approach to handling metrics. Dangerous as it allows for user 
        to assign a discrete amount of memory to a VLA on the stack. This is 
        asking for stack overflow errors! Using malloc and checking for a
        successful malloc call is a much safer and efficient approach for 
        storing the coffee machine metrics!
    
    double heatDitributionMetrics[arraySize],
                   grinderMetrics[arraySize],
                      pourMetrics[arraySize];

    */

    /*
        FIX: New and improved dynamic array creation!
        
        Allows us to track our metrics on the heap! Malloc will only allocate
        the memory for our metrics if the system has enough free memory
        available! A null pointer will be returned otherwise!

        With a VLA, we can't check for this as this is all automatically 
        performed on the stack and we cant interfere if there isn't enough
        system memory available!

        By using dynamic memory allocation, we can both check we have enough 
        memory, and heandle the instance we don't have enough and end up
        with a null pointer!
    */
    double *heatDistributionMetrics = (double*) malloc(arraySize * sizeof(double));
    double *grinderMetrics = (double*) malloc(arraySize * sizeof(double));
    double *pourMetrics = (double*) malloc(arraySize * sizeof(double));

    /*
        If the user specifies a size for the metrics which exceeds the total
        available memory, we need to handle this by allocarting a safe amount
        of memory to store a reduced set of metrics.

        The following section handles this by checking for null pointers in
        our metrics variables. If a null pointer is recieved, then not
        enough memory was available when the user specified a metrics size.

        Instead, assign arrays of a safe, default size instead.
    */
    if (!heatDistributionMetrics)
    {
        heatDistributionMetrics = (double*) malloc(DEFAULT_SIZE * sizeof(double));
    }

    if (!grinderMetrics)
    {
       grinderMetrics = (double*) malloc(DEFAULT_SIZE * sizeof(double));
    }

    if (!pourMetrics)
    {
        pourMetrics = (double*) malloc(DEFAULT_SIZE * sizeof(double));
    }

    /*
        Generate and assign simulated metrics from the coffee machine and
        assign them to the arrays we have created.

        Currently, three calls to "Gather Metrics" isn't the most efficient
        or readable way of handling our calls to the "GatherMetrics" function.

        Instead, it would be better if we could store our metric arrays in
        an array (essentially a 2D array), and then iterate over the 2D
        array, passing in each array's starting address to our gatherMetrics
        function as a pointer.

        GatherMetrics(arraySize, heatDitributionMetrics);
        GatherMetrics(arraySize, grinderMetrics);
        GatherMetrics(arraySize, pourMetrics);
    */

   /*
        We need an array of pointers to double's here. Our array is going to be
        made up of references to other arrays which we will then reference
        with an iterator. As we know, a call to an array name gives us the 
        address of the first element. So we can use this to return the starting
        point of each array and then use the index notation to iterate over it.
   */
   double *metricsMatrix[3] = 
   {
       heatDistributionMetrics,
       grinderMetrics,
       pourMetrics
   };

   for (int i = 0; i < 3; i++)
   {
       GatherMetrics(arraySize, metricsMatrix[i]);
   }

    // Loop to print out the row, column and metric value
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            printf("Row/Column: %d/%d - Value %f\n", i + 1, j + 1, metricsMatrix[i][j]);
        }
        printf("\n");
    }


   //   Don't forget. Whenever we malloc memory, we have to free it after we're
   //   done!
   for (int i = 0; i < 3; i++)
   {
       free(metricsMatrix[i]);
   }

    return 0;
}

/*
    Method to simulate gathering of complex metrics from the coffee machine. 
    Iterates through the provided array and assigns a randomly generated number
    to each element.
*/
void GatherMetrics(size_t size, double *metricArray)
{
    for (int i = 0; i < size; i++)
    {
        metricArray[i] = GetRandomNumber();
    }
}

/*
    Method to handle the generation of our simulated metrics through the use
    of RNG. 
*/
double GetRandomNumber()
{
    return rand() / (RAND_MAX / 2.5);
}