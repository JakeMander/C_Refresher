#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    In this example we'll be taking a look at nesting structs within other
    structs.

    Sticking with the sports theme of the previous example, let's create a 
    structure called stadium. This will be used to represent the data used to
    model stadiums as an entity of our business logic. This will track data 
    such as when it was built, what it's capacity is and it's name.
*/
int main (int argc, char* argv)
{
    struct stadium
    {
        int capacity;
        int built;
        char location[32];
        char name[32];
    };

    /*
        Here we have our "team" struct. Notice the team struct nests a member
        of another struct type, "stadium". This is the power of structs. We
        can make elements of our business lofic reference other elements
        represented by structs!
    */
    struct team
    {
        struct stadium oldHomeGround;
        struct stadium homeGround;
        char owner[32]; 
        char manager[32];
        char nickname[32];
    };

    struct team arsenal;

    /*
        Here we define a team's struct's nested "homeGroud" stadium struct and
        it's member variables. We can do this by using the '.' notation much 
        like any other struct.
    */

    arsenal.oldHomeGround.capacity = 38419;
    arsenal.oldHomeGround.built = 1913;
    strcpy(arsenal.oldHomeGround.name, "Arsenal Stadium");
    strcpy(arsenal.oldHomeGround.location, "Highbury");

    arsenal.homeGround.capacity = 60260;
    arsenal.homeGround.built = 2004;
    strcpy(arsenal.homeGround.name, "The Emirates");
    strcpy(arsenal.homeGround.location, "Holloway");

    strcpy(arsenal.owner, "KSE INC");
    strcpy(arsenal.manager, "Mikel Arteta");
    strcpy(arsenal.nickname, "The Gunners");

    //  Let's print all that out, nested structures too!
    printf("\nClub Stats:\n\tNickname: %s, Manager: %s, Owner: %s", 
    arsenal.nickname, arsenal.manager, arsenal.owner);

    printf("\n\n\tCurrent Stadium: %s\n\t Location: %s, Capacity: %d, Built: %d", 
    arsenal.homeGround.name, arsenal.homeGround.location, 
    arsenal.homeGround.capacity, arsenal.homeGround.built);

    printf("\n\tOld Stadium: %s\n\t Location: %s, Capacity: %d, Built: %d",
    arsenal.oldHomeGround.name, arsenal.oldHomeGround.location, 
    arsenal.oldHomeGround.capacity, arsenal.oldHomeGround.built);
    printf("");

    /*
        It's worth noting we could use curly braces to initalise our structs and
        nested structs like so:

        struct team arsenal = 
        {
            {38419, 1913, "Arsenal Stadium", "Highbury"}, <- struct oldHome
            {60260, 2004, "Holloway, "Emirates"}, <- struct home
            "KSE Inc", "Mikel Arteta", "The Gunners" <- struct team
        }

        As we know from the previous chapter, this is value initialization, 
        where each member variable of the struct is initalized in order they
        appear in the struct definition. 

        This may be slightly more compact and concise a means of initalizing a
        struct but be careful! It's not the cleanest approach to initalization
        and can sometimes get confusing for larger structs with lots of 
        nesting!
    */
    return 0;
}