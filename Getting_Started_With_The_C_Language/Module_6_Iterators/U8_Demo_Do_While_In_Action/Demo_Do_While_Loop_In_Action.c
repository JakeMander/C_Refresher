/*  
    In this demo, we demonstrate a do while loop that 
    asks for user input and evaluates the recieved 
    string to determine whether or not the loop
    should continue.

    As this is a do while loop, the code in the
    do-while's block will run AT LEAST once.
*/

#include <stdio.h> // Gives us printf.
#include <string.h> // Gives us strcmp.

int main(void) 
{
    char answer[10];

    int iterator = 0; // Keep tabs on the number of times we iterate the loop.

    do 
    {
        iterator++;
        printf("We Have Iterated %d Times\n", iterator);
        printf("Would You Lke To Keep Looping (Enter \"NO\" To Quit: )");
        scanf("%9s", answer);
    } while (strcmp(answer, "NO") != 0);
    printf("Goodbye!\n");
}