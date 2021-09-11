#include <stdlib.h>
#include <stdio.h>

/*
    In the previous unit it was noted that 'structure padding' happens by 
    default by C in an attempt to minimise wasting CPU time and resources.

    Because of this however, memory consumption is higher which may be a 
    concern if you're program is being built for a system with not a lot
    of memory.

    Instead, we can use "structure packing" to tell C not to pad our
    structures and allow for struct members to cross word boundaries
    as we saw in the last unit. 

    We can enable this via the pragma pack preprocessor directive:
*/

#pragma pack(1) //  Preprocessor directives will be explained later on!

int main (int argc, char* argv)
{
    struct manUtdShirt
    {
        char size;
        char colour;
        int number;
    } manUtdShirt;  // 8 - 6 = 2 bytes of RAM wasted. 

    struct arsenalShirt
    {
        char size;
        int number;
        char colour;
    } arsenalShirt; // 12 - 6 = 6 bytes of RAM wasted.

    printf("\n\tSize of manUtdShirt: %d", sizeof(manUtdShirt));
    printf("\n\tSize of arsenalShirt: %d", sizeof(arsenalShirt));
    return 0;
}