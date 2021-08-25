#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
    We'll finish this section off with a demo!

    Here we'll cover all of the core aspects of memory management with pointers
    that we've covered so far.

    Wired Brain Coffee have been working on their new coffee machine firmware
    but the team have identified the existence of a memory leak.

    In this exercise, we'll hunt down the memory leak and fix it! It's suspected
    to be a dangling pointer!

    But first, let's get an overview of the program and see what it does.
*/

/*
    Globals
*/

int metricCount = 0;


/*
    Function/Structure Declerations
*/

/*
    As coffee pours, it periodically creates and logs metrics to track the 
    power consumption of the machine (and leaves space for us to add more if
    we want in future.). 
    
    The sequence number identifies the order in which the metric was logged and
    is generated in conjunction with the "metricCount" counter. 

    Each coffee machine will be represented by a CoffeeMachine structure. This will
    track an array of metrics via a pointer to a Metric pointer.
*/
typedef struct Metric 
{
    int sequenceNumber;
    float powerUsed;
} Metric;


/*
    The CoffeeMachine strcuture is designed to encapsulate the functionality of a
    WiredBrain coffee machine,  as well as it's metric logging. 

    This structure consists of:

        - The pour mode currently selected by the user. The function assigned to 
          handle the call to "pour" will be dynamically assignable by the user
          via command line arguments.

        - A pointer to a set of metrics that are logging for the current call
          to a pour method. This will act as a dynamically allocated array, 
          with it's size based on the "duration" of the pour provided by the 
          user via the command line. 
          
          As each pour runs, the duration will be represented by the number of
          iterations through a while loop (this is to simulate time passing).

          For each run of the loop a metric is created and added to the 
          metrics block of memory using pointer arithmetic.
          
          When the pour is finished, the metrics are sent off to another 
          metrics API that is still a work in progress by the Wired Brain
          dev team.

        - Pour duration is a value which simulates the passing of time as the 
          machine carries out a pour and will be used to simulate how long a
          pour runs for. 

          Each pour function has a while loop which handles the pour logic. In
          our case, duration represents each iteration of then while loop and is
          used to signal that a metric should be created each iteration. In a 
          real world scenario this would be a time value. 

          Pour duration is defined by the user as part of the command line 
          arguments.         
*/
typedef struct CoffeeMachine 
{
    int (*pour) (int, struct CoffeeMachine*);
    Metric **metrics;
    int pourDuration;

} CoffeeMachine;

//  CoffeeMachine Create/Destroy API
int InitCoffeeMachine(CoffeeMachine**);
void CleanupMachine(CoffeeMachine*);

//  Different PourHandler Function Declerations
int PourDecaf(int, CoffeeMachine*);
int PourClassic(int, CoffeeMachine*);
int PourRich(int, CoffeeMachine*);

//  Metric API
Metric* CreateMetric(float);
int SendMetrics(Metric**, size_t metricSize);

int main(int argc, char *argv[])
{
    // Instantiate a test coffee machine
    CoffeeMachine *myMachine;
    if (InitCoffeeMachine(&myMachine)) 
    {
        printf("System does not have enough memory to allocate a CoffeeMachine structure\n");
        return 1;
    }

    printf("\nMachine Activated\n");

    // A pour mode (one of 'decaf', 'rich', or 'classic') is required along with a pour duration.
    if (argc > 2) 
    {
        char *userPourMode = argv[1];
        int duration = strtol(argv[2], NULL, 10);

        myMachine->pourDuration = duration;

        // Set the 'pour' function pointer based on the pour mode argument
        if (!strcmp("decaf", userPourMode)) 
        {
            myMachine->pour = PourDecaf;
        } 
        
        else if (!strcmp("rich", userPourMode)) 
        {
            myMachine->pour = PourRich;
        } 
        
        else 
        {
            myMachine->pour = PourClassic;
        }

        printf("\nBeginning Pour With Duration: %d\n", duration);

        myMachine->pour(duration, myMachine);

        printf("\nPour Complete. Sending Metrics...\n");
        SendMetrics(myMachine->metrics, duration);

        printf("\nPerforming Cleanup...\n");
        CleanupMachine(myMachine);
    } 
    
    else 
    {
        printf("Please pass pour mode and pour duration arguments!\n");
        return 1;
    }



    return 0;
}

/*
    Wired Brain Coffee API Functions
*/

/*  
    Dynamically Allocates Enough memory For A CoffeeMachine type.

    If we successfully allocate a new block of memory for our coffee 
    machine, assign the value of our pointer to pointer as the
    pointer to our new block of memory and return 0 to signal a
    success
*/
int InitCoffeeMachine(CoffeeMachine **machine) 
{

    if (*machine = (CoffeeMachine*) malloc(sizeof(CoffeeMachine)))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//  Pours a decaf cup of coffee - Mid power draw.
int PourDecaf(int duration, CoffeeMachine *machine) 
{
    int start = 0;
    Metric **metricsPtr = (Metric**) malloc(duration * sizeof(Metric));

    machine -> metrics = metricsPtr;

    while (start < duration)
    {
        //  Do some processing of pouring here...
        float powerUsed = 4.4;
        Metric *metric = CreateMetric(powerUsed);

        /*
            Add the newly created metric to our array of metrics using pointer
            arithmetic. The offset will be how many times start has been 
            incremented which should start as 0 and always be lower than the 
            duration thus ensuring we stay in the bounds of the dynamic
            memory.
        */
        *(metricsPtr + start) = metric;
        start++;
    }
    return 0;
}

// Pours a classic cup of coffee - Highest power draw.
int PourClassic(int duration, CoffeeMachine *machine) {
    int start = 0;
    Metric **metrics_ptr = (Metric**) malloc(duration * sizeof(Metric));
    machine->metrics = metrics_ptr;

    while (start < duration) {
        // Do some processing of pouring here....
        float power_used = 5.6;

        Metric *metric = CreateMetric(power_used);
        *(metrics_ptr + start) = metric;
        start++;
    }

    return 0;
}

//  Pours a rich cup of coffee - lowest power draw.
int PourRich(int duration, CoffeeMachine *machine)
{
    int start = 0;
    Metric **metrics_ptr = (Metric**) malloc(duration * sizeof(Metric));
    machine->metrics = metrics_ptr;

    while (start < duration) {
        // Do some processing of pouring here....
        float power_used = 3.7;
        Metric *metric = CreateMetric(power_used);
        *(metrics_ptr + start) = metric;

        start++;
    }
    return 0;
}

Metric* CreateMetric(float powerUsed)
{
    Metric *metric = (Metric*) malloc(sizeof(Metric));
    metric -> sequenceNumber = ++metricCount;
    metric -> powerUsed = powerUsed;

    return metric;
}

int SendMetrics(Metric **metrics, size_t metricCount)
{
    if (metrics == NULL)
    {
        return 1;
    }

    for (int i = 0; i < metricCount; i++)
    {
        Metric *metric = metrics[i];
        printf("\n Metric Count: %d\n", metric -> sequenceNumber);
        printf("Metric Power Used: %.2f\n", metric -> powerUsed);

        //  Here we could send each metric to the cloud via a web service/API.
    }
    return 0;
}

//  Frees up resources that were allocated when the CoffeeMachine was created.
void CleanupMachine(CoffeeMachine *machine)
{
    /*  
    
        BUG WAS HERE!

        The original body was simply:

        free(machine);

        The problem with this is, yes, you have removed the memory that stores
        the references to the metrics, pour function and pour duration, but
        in doing so, you've only removed the pointers to those components we
        dynamically created, not the components themselves!

        This isn't Java or C#! There is NO GARBAGE COLLECTION to take care of
        that for you!

        As a reuslt, you've ended up with a memory leak!

        The solution is to make sure you go over your structure and dive down
        into each of your pointers, clearing memory as you go. 

        In this instance, we need to go through the metrics double pointer
        array, and pass each pointer to the metric to free in order to 
        deallocate each metric that was created! Otherwise we lose the 
        pointer to each metric without deallocating and can thus never
        find that memory again!

        After this, we then need to deallocate the array containing
        the double pointers! Again, this is it's own individual component
        that we allocated memory for and needs to be freed just like any
        other piece of memory! 

        Once we've done this, we reach the top level of our chain of
        pointers. There are no more pointers inside our CoffeeMachine
        struct left to handle, so we can now dispose of the CoffeeMachine
        itself!
    */
    //  Iterate over the total number of metrics that were produced.
    for (int i = 0; i < machine -> pourDuration; i++)
    {
        /*  
            Remember, "metrics" is a dynamically allocated array of pointers to
            a pointer to metrics. In order to free our metric from memory, we 
            need to extract that pointer and pass it to free via an array index.
        */
        Metric *metric = machine -> metrics[i];
        printf("\n Freeing Metric At Count: %d\n", metric -> sequenceNumber);

        //  
        free(metric);
    }

    //  Free up the memory containing the pointers to the pointers to metrics!
    free(machine -> metrics);

    //  Free up the memory we allocated for our CoffeeMachine structure as a
    //  whole. 
    free(machine);
}


