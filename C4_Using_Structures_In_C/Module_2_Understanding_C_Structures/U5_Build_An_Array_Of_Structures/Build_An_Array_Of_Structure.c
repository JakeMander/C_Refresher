#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    In this demo we'll make an array of structures. 

    Like before, we'll create a structure and declare it as "player".

    Next up, we'll declare an array that will hold 3 "player" structure 
    elements.
*/


int main (int argc, char* argv)
{
    struct player
    {
        char name[32];
        char position[32];
        char club[32];
    };

    //  Our array of three structs.
    struct player englandPlayers[3];

    /*
        Let's now initalize our array with some players! At each memory 
        location, we'll be storing a player struct, so by using the array
        bracket notation, and the struct '.' notation, we can move to each
        element in the array and set each member variable to some player stats.
    */ 

    strcpy(englandPlayers[0].name, "Harry Kane");
    strcpy(englandPlayers[0].position, "FW");
    strcpy(englandPlayers[0].club, "Tottenham Hotspur");

    strcpy(englandPlayers[1].name, "Raheem Sterling");
    strcpy(englandPlayers[1].position, "MDF");
    strcpy(englandPlayers[1].club, "Manchester City");

    strcpy(englandPlayers[2].name, "Harry Maguire");
    strcpy(englandPlayers[2].position, "DEF");
    strcpy(englandPlayers[2].club, "Manchester United");

    printf("A Selection of England Players:\n");

    //  Now we can iterate over our array and print the stats of each player!
    for (int i = 0; i < 3; i++)
    {
        printf("Player: %s (Position: %s, Club: %s)\n", englandPlayers[i].name, 
        englandPlayers[i].position, englandPlayers[i].club);
    }

    /*
        Alternatively, we could initalize our array of structs using value 
        initialization in conjunction with the curly brace array initalization.

        The first struct we initalize has index 0, the second index 1 and so
        on so forth!

        This saves on having to explicitly reference an index and assign each
        element's struct members manually!
    */

   struct player curlyBraceEnglandPlayers[3] =
   {
       {"Harry Kane", "FW", "Tottenham Hotspur"},
       {"Raheem Sterling", "MDF", "Manchester City"},
       {"Harry Maguire", "DEF", "Manchester United"}
   };

    printf("\n\nA Selection of England Players (Alternate Initalization):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Player: %s (Position: %s, Club: %s)\n", 
        curlyBraceEnglandPlayers[i].name, 
        curlyBraceEnglandPlayers[i].position, 
        curlyBraceEnglandPlayers[i].club);
    }

    return 0;
}