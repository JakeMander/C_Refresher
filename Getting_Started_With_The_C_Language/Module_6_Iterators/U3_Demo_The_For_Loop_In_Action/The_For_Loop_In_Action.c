// The following provides another demo of the for loop in action

#include <stdio.h> // Gives us printf

int main(void) 
{
    for (int i = 0; i < 10; i++) {
        //  Print out the number of iterations we've carried out
        //  compensating for the 0 index we start with!
        printf(" Iteration %d \n", (i+1));
    }

    return 0;
}