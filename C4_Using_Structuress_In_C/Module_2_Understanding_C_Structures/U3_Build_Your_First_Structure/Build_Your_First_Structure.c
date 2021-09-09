#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    We'll jump straight into examples so we can quickly see how we can build
    structures. As we can see below, we've constructed a new player struct
    which acts as a type to represent an entity in our business logic.

    In this example, our entity will represent a football player and will
    act as a container for information about their age, height and position
    on the pitch!

    As we already know, the below definition is the simplest means of declaring
    a struct. 

    Our struct of name "player" has a block of memory allocated with enough 
    memory inside to contain one integer variable, a float variable and a char
    array of length 8 (7 characters and the '\0' null terminator).

    Remember however that the C compiler allocates memory based on 8 byte 
    word boundaries for structs in order to ensure a consistent size
    for structs and reduce fragmentation of memory. 

    So in total we have:

        - 2 bytes allocated for int values (16bits).
        - 2 bytes allocated for float values (16bits).
        - 8 Bytes allocated for char values (8 * 8 bits (1 byte) = 64 bits 
          (8bytes))

    So we have 8 + 2 + 2 = 12 bytes.

    So in total we have:

    1 full 8 byte word boundary allocated for our struct PLUS 4 bytes of a 
    second 8 bytes boundary allocated for data with 4 bytes of padding to
    fill the remainder of the second 8 byte word boundary.

    As we've not used a typedefined struct delceration, we must define 
    player struct variables by first calling the struct keyword followed
    by the name we gave our struct ('player') and finally the name we want to
    give our new variable of type player.
*/
int main (int argc, char* argv)
{
    //  Remember, struct is locally scoped. We'll only be able to access this 
    //  in the main function!
    struct player
    {
        int age;
        float height;
        char position[8];
    };

    struct player kane;
    struct player sterling;
    struct player maguire;

    //  Here we assign values to our struct to represent Harry Kane. Here, as
    //  we have a player type that isn't a pointer, we can use the '.' notation
    //  to read and write values to our struct's members.  
    kane.age = 28;
    kane.height = 187.96;

    //  Remember! We can't directly assign a value to a C string! Instead, we 
    //  need to take the bit value of a string literal and copy it to the 
    //  address of a char array.
    strcpy(kane.position, "FW");

    sterling.age = 26;
    sterling.height = 170;
    strcpy(sterling.position,"MDF");

    maguire.age = 28;
    maguire.height = 194;
    strcpy(maguire.position, "DEF");

    //  Print out all of our footballer stats!
    printf("\nHarry Kane \nAge: %d, Height: %.2fcm, Position: %s", kane.age, kane.height,
    strcmp(kane.position, "FW") == 0 ? "Forward\n" : "NA\n");

    printf("\nRaheem Sterling \nAge: %d, Height: %.2fcm, Position: %s", sterling.age, 
    sterling.height, strcmp(sterling.position, "MDF") == 0 ? "Midfield\n" : "NA\n");

    printf("\nHarry Maguire \nAge: %d, Height: %.2fcm, Position: %s", maguire.age, 
    maguire.height, strcmp(maguire.position, "DEF") == 0 ? "Defence\n" : "NA\n");
    printf("\n");
    
    return 0;
}