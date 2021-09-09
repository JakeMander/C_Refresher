#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    In this demo we'll pass a structure to a function in order to perform
    some processing on it's member variables.

    The first thing we'll need to do is move our player struct out of the
    main function. Why?

    Because of scope!

    At the minute, our player struct definition is only locally scoped to be
    usable in the "main" function. 

    As we're now buildinhg other functions with their own scope, we'll need to
    make player globally accessible like so:
*/

struct player
{
    char name[32];
    char position[32];
    char club[32];
};

/*
    Next, we'll define a function that takes the position from our struct and
    returns the full named description of the player's position. Here, we
    don't pass in the full struct! Only the struct's position member!
*/

char* DescribePosition(char *position);

/*
    Also define a function that takes the position by taking the full player
    struct as a parameter!
*/
char* DescribePositionByStruct(struct player footballer);


int main (int argc, char* argv)
{

   struct player englandPlayers[3] =
   {
       {"Harry Kane", "FW", "Tottenham Hotspur"},
       {"Raheem Sterling", "MDF", "Manchester City"},
       {"Harry Maguire", "DEF", "Manchester United"}
   };

    printf("\n\nA Selection of England Players (By Struct Pos):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Player: %s (Position: %s, Club: %s)\n", 
        englandPlayers[i].name, 
        DescribePosition(englandPlayers[i].position), 
        englandPlayers[i].club);
    }

    printf("\n\nA Selection of England Players (By Struct):\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Player: %s (Position: %s, Club: %s)\n", 
        englandPlayers[i].name, 
        DescribePositionByStruct(englandPlayers[i]), 
        englandPlayers[i].club);
    }

/*
    Sometimes however it might be more convienient to pass in the entire 
    struct. This might be true if a function needs to access multiple
    struct members at once. 

    To do this, we can simply change the parameter type expected by the 
    function to "player". The argument we pass in will then be passed by
    value (that is a copy of the original value stored will be made and
    assigned to a new variable identified by the parameter name).

    This is okay for small structs, but not ideal for large sturcts which are
    big and bulky. As we've already seen, for objects such as these, it's 
    preferable to use a pointer and pass the reference to the struct over
    instead. 

    This will be explored in the next section. 
*/

    return 0;
}

char* DescribePosition(char *position)
{
    if (strcmp(position, "GK") == 0)
    {
        return "Goalkeeper";
    }

    if (strcmp(position, "DEF") == 0)
    {
        return "Defence";
    }

    if (strcmp(position, "MDF") == 0)
    {
        return "Midfield";
    }

    if (strcmp(position, "FW") == 0)
    {
        return "Forward";
    }

    return "NA";
}

/*
    Retrieves the long position name by taking in an entire player struct, 
    looking up the players position and making the comparison.
*/
char* DescribePositionByStruct(struct player footballer)
{
    char* pos = footballer.position;

    if (strcmp(pos, "GK") == 0)
    {
        return "Goalkeeper";
    }

    if (strcmp(pos, "DEF") == 0)
    {
        return "Defence";
    }

    if (strcmp(pos, "MDF") == 0)
    {
        return "Midfield";
    }

    if (strcmp(pos, "FW") == 0)
    {
        return "Forward";
    }
    return "NA";
}