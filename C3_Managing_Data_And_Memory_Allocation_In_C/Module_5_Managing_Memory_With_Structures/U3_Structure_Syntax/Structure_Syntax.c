#include <stdio.h>
#include <stdlib.h>

/*
    So we're now familiar with what structs are and the use cases for them
    in the C programming language. But how do we go about implementing them in 
    code?

    To start off, let's look at how we might go about defining a structure 
    so that C knows what new type we want and what types we're grouping as
    part of it.

    There are three different ways of defining a structure in C. 

    The simplest approach is the following:
*/

struct Grade 
{
    char letter;
    int rank;
};

/*
    Here we use the struct keyword followed by the name we want to assign to 
    our new type. The structure we have here models a "Grade" entity so we'll
    want to populate it with members that will represent what it means to be
    a "grade".

    Above, we populate it with two members. That is a single character which
    is typically used to represent a grade (i.e. 'A', 'B', 'C' etc.) as well
    as a rank (different grades typically represent different levels of 
    achicement and thus can be ranked in significance!).

    The above definition defines the "Grade" structure but doesn't create any
    variables.

    If we want to declare variables after defining the structure itself, we
    can do the following:
*/

struct GradeWithDefinition
{
    char letter;
    int rank;
} grade1, grade2;

/*
    The above approach to declaring structures is useful if you want to declare
    globally available variables right after the structure definition 
    (...though global variables are typically a bad idea for numerous reasons
    that go beyond the scope of this intro to C).

    Finally, we can also define a structure in combination with the C typedef 
    keyword like so:
*/

typedef struct TypedefGrade
{
    char letter;
    int rank;
} TypeDefGrade;

/*
    Typedef'ing a struct is useful and can be achieved by prefixing the 
    "struct" keyword with "typedef", and by following the closing curly brace
    with the name to assign that you want to assign the new struct type.

    The benefit of type defining a structure is that initializing variables 
    to our new type becomes much easier.

    Without typedef, we initalize a variable like so:
*/
int main(void)
{
    struct Grade newGrade = {'A', 1};

/*
    With typedef, we don't need to type "struct [struct name]" which cleans up our
    code!

    It's recommended you define structs using typedef as it simplifies structure
    initalization and saves on repeating "struct" all the time.
*/

    TypeDefGrade typeDefinedNewGrade = {'B', 2};

/*
    As we saw with our previous example, structure definition looks like
    the following: 
*/

    TypeDefGrade studentGrade;

/*
    But as with any C variable, once we've declared a variable, we need to
    initalize it so it has value and meaning!

    With C structures, we can intialize each member variable individually using
    the "dot notation". By calling the name of the struct followed by a dot 
    ('.') and the name of the member variable to initialize, we can assign values
    to a structure and it's grouped types:
*/

    studentGrade.letter = 'A';
    studentGrade.rank = 1;

/*
    Structure initalizaton can also be performed through use of curly brackets
    as demonstrated when we first looked at type defined structs.

    Please note, that when you initalize a structure variable using this 
    approach, the structure's members need to be intialized in the correct
    order (i.e. for sudentGrade, letter needs to be the first value, and rank
    should be second as that's the order they were declared in the struct
    definition). For example:
*/

    TypeDefGrade studentGradeTwo = {'C', 3};

/*
    To get around the need to specifically pass in member variables in the 
    order they were declared, C provides another initialization syntax. 
    This is "designated intitilization". 
    
    This allows you to initalize structure member's in any order provided the
    name of the member is prefixed with a '.'. 
    
    For example:
*/
    TypeDefGrade studentGradeThree = {.rank = 4, .letter = 'D'};

/*
    So how is a structure represented in memory?

    Well this all depends on what members the structure contains, and the 
    system your C code is compiled in.

    You should always bare this in mind and understand the memory layout of a
    structure as the quirks of how structure memory is handled in different
    archtiectures and systems can make all the difference if you're building
    apps for systems that don't offer an abundance of memory to play with.

    As we've seen previously, our Grade structure is built like so:

    typedef struct Grade
    {
        char letter;
        int rank;
    } Grade;

    We've two member variables! A char (1 byte) and an int (4 bytes).

    With a bit of intuition, we might boldly assume that our Grade structure,
    with it's constituent parts summed, takes up a total of 5 bytes of memory
    which would be a good guess!

    ...but a WRONG one!!!

    The actual size of this struct is 8 bytes. Why?

    Because, assuming we have compiled our struct on a 64-bit, with a bit of 
    Computer Science digging, we'd know that the word size (that's the maximum
    number of bits the system can handle at once for a byte of memory) is 64
    bits (8-bytes!).

    So the CPU and OS typically likes to process things in chunks of 8 bytes if
    possible. 

    So C, being a low level language, will try and play nice with the CPU and OS
    by making up the deficit of a struct if it's not quite 8-bytes and pad out
    the allocated memory for each variable of the struct so that it fills 8 bytes
    of memory. 

    So in reality, our Grade struct looks more like the following in memory:

                 Padding
                    |
        ____________|______________________
        |     |           |               |
        |  1  |     3     |       4       | 
        |     |           |               |
        |_____|___________|_______________|
           |                      |
           |                      |
         Letter                  Rank

    So thats:
        - 1 Byte for letter.
        - 4 bytes for rank.
        - 3 bytes of additional padding to take us up to 8 bytes of allocated
          memory.

    Why do this? It's to do with the alignment of memory along word boundaries!

    ...But that goes beyond the scope of C!

    Just remember that the C compiler needs to align structures on 64 bit 
    architectures along 8 byte word lines and will do so by padding out
    structures with additional allocated memory to round up the memory
    used to 8 bytes if, when declared, the struct takes up less than 8 bytes.

    Understanding this is important in understnaindg how structures are 
    allocated in memory. If you know this, you can optimise structures
    with regards to their structure and footprint to take up less memory!
*/
}