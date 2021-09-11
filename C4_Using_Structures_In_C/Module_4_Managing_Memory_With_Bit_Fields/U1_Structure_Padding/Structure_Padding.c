#include <stdlib.h>
#include <stdio.h>

/*
    In this module we'll be learning all about bit fields and how they are used
    with structs and memory management in C.

    To start off, we'll explore structure padding in a little more depth. We've
    already gone over this in brief but we'll recap here.

    As we already know, when we create an object based on a structure, wether 
    this is done dynamically or statically, the memory is contiguously 
    allocated to the members of the structure in THE ORDER THEY APPEAR.

    So for example:
*/

struct footballtShirt 
{
    char size;
    char colour;
    int number;
};


/*
    Is ordered as:
         ________ ________ ________
        |  Pos1  |  Pos2  |  Pos3  |  
        |  char  |  char  |  int   | 
        |  1byt  |  1byt  |  4byt  |
        |________|________|________|

    THIS IS IMPORTANT IN TERMS OF HOW MEMORY IS ALLOCATED IN A STRUCT so please
    make a mental note of this for this demo.

    So with this in mind, let's re-ask ourselves a question we touched on in the
    last module.

    How big is the footballShirt struct?

    6 bytes you say!? That's INCORRECT!

    It's actually 8 bytes! Why? As you may remeber, this is all down to something
    called "structure padding"! 
    
    This is something the C language performs when handling structs in an 
    attempt to minimise wasted processor cycles during a calculation (i.e. how 
    many times it has to read different blocks of memory to complete a single
    calculation/expression). Essentially, our struct is being ran on a 64
    bit archtiecture that operates to a word boundary of 8 bytes...

    So this means C is most efficient when it works in chunks of 8 bytes. 

    Because the struct is only 6 bytes, C will fill the struct with two
    bytes of empty space to make up the difference. 

    Why is this important? Well it comes down to how computers process
    and organise memory.

    In computer science, the currency of processing and calculations on the 
    processor level is the "word". This is essentially the maximum number
    of bits/bytes that can be transferred or operated on at once as part of
    a single operation. 

    So for example, a 64-bit operating system will run in tandem with a 64
    bit processor. This processor has a word length of 64 bits, and will
    read, process and store data in chunks of 64 bits (8 bytes). 

    To put this into perspecitve, this means the largest address/integer value
    you can store in memory is 18,446,744,073,709,551,615 
    (-1 because 0 is counted as well).

    A 32-bit operating system however, has a word length of 32 bits, and
    can only read, write and process values in blocks of 32 bits. 

    To that end, the CPU doesn't read one byte at a time, it reads memory
    as "words".

    So why is that important? Let's say we're running our program on a 
    32-bit computer. So at a maximum, the CPU can only process a maximum of
    32-bits (4 bytes) at a time (or more specifically, per cycle of the 
    processor).

    So in memory, our struct logically looks like this:

    __________ __________ __________ __________ __________ __________ __________ __________
    |   Byt1   |   Byt2   |   Byt3   |   Byt4   |   Byt5   |   Byt6   |   Byt7   |   Byt8   |  
    |   size   |  colour  |  PADDING | PADDING  |  number  |  number  |  number  |  number  |
    |   1byt   |   1byt   |          |          |   4byt   |   4byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|__________|__________|__________|__________|

    Notice the padding has been added after the "colour" variable. The reason
    for this is that's the most efficient way for the processor to use it's
    cycles.

    Let's see an example.

    Without padding, we'd have:

    __________ ___________ __________ __________ __________ __________
    |   Byt1   |   Byt2   |   Byt5   |   Byt6   |   Byt7   |   Byt8   |  
    |   size   |  colour  |  number  |  number  |  number  |  number  |
    |   1byt   |   1byt   |   4byt   |   4byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|__________|__________|     

    If we the x84CPU needs to access "size" or "colour", that's fine... The
    CPU will just load this chunk of memory in ONE cycle:

    Cycle 1 loads:

      Loads to CPU in one
         |          |
         |          |
         V          V
     __________ __________ __________ __________ 
    |   Byt1   |   Byt2   |   Byt3   |   Byt4   |  
    |   size   |  colour  |  number  |  number  |
    |   1byt   |   1byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|

    Then it can directly take the bits from Byt1 and Byt2, load them into a
    register and process them straight away as the CPU has the full set of data 
    it needs to represent either variable.

    The issue starts when we need to access number. Why? Because we can only 
    load half of the variable per cycle! For instance:

    Cycle 1 loads:
                 
                 Loads first half of number variable to CPU
                            (Still 2 bytes left)
                                |          |
                                |          |
                                V          V
     __________ __________ __________ __________ 
    |   Byt1   |   Byt2   |   Byt3   |   Byt4   |  
    |   size   |  colour  |  number  |  number  |
    |   1byt   |   1byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|

    Cycle 2 loads:

Loads second half of number variable to CPU
        |          |
        |          |
        V          V
     __________ __________ __________ __________ 
    |   Byt5   |   Byt6   |   Byt7   |   Byt8   |  
    |  number  |  number  |  Garbage |  Garbage |
    |   1byt   |   1byt   |   value  |   Value  |
    |__________|__________|__________|__________|

    Then our CPU has a big problem! Not only does it have to waste time doing
    two cycles to get the full value, the CPU then needs to implement some 
    means of merging our unaligned data into a single, processable value, which
    again, is a big performance hit!

    So C, quite kindly, goes out of it's way to play nice with word boundaries
    and will pad out structures with space to ensure that variables do not
    overflow into other words!

    This is why, after size and colour, C has kindly aded two bytes of padding!

    In doing so, Our memory (in words) is now:

    Word 1

     __________ __________ __________ __________ 
    |   Byt1   |   Byt2   |   Byt3   |   Byt4   |  
    |   size   |  colour  |  PADDING |  PADDING |
    |   1byt   |   1byt   |          |          |
    |__________|__________|__________|__________|

    Word 2

     __________ __________ __________ __________ 
    |   Byt5   |   Byt6   |   Byt7   |   Byt8   |  
    |  number  |  number  |  number  |  number  |
    |   4byt   |   4byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|

    This is great news!

    Want size? No problem. CPU can load that value in one cycle as it's 
    contained within a single word.

    Want colour? No problem. CPU can load that value in one cycle as it's 
    contained within a single word.

    Want number? No problem. CPU can load that value in one go cycle it's 
    contained within a single word.

    Need to access the whole structure? We're going to need two cycles for that
    still... but that's no worse than what we had before!

    Because we save on cycles, the CPU can complete operations quicker!

    The only downside to this approach is, more memory is consumed in applying 
    the padding, so if your program is running on a limited memory system, 
    you may need to bear this in mind.

    For example, our 32-bit system now uses 8 bytes to store our struct.

    It's important to note that this is C's default approach to managing memory
    in structs so unless specified, it will always add padding when it notices
    structure members crossing word boundaries.

    As we've mentioned before, as a direct consequences of structure padding, 
    the order in which you declare your member variables in a struct matters!

    For example the following will really mess up our memory:

    struct footballtShirt 
    {
        char size;
        int number;
        char colour;
    }

    Why? Because size takes one byte leaving only 3 bytes of the first word
    left for number which would cause an overflow into the next word! 

    So to get around this, C needs to allocate another 4 bytes to fit number
    in entirely!

    But then we still have to sort our colour member! But remember, we can't
    just allocate one byte for it! It needs to be padded out!

    So in total we end up with:

    Word 1
     __________ __________ __________ __________ 
    |   Byt1   |   Byt2   |   Byt3   |   Byt4   |  
    |   size   |  PADDING |  PADDING |  PADDING |
    |   1byt   |          |          |          |
    |__________|__________|__________|__________|

    Word 2
    __________ __________ __________ __________ 
    |   Byt5   |   Byt6   |   Byt7   |   Byt8   |  
    |  number  |  number  |  number  |  number  |
    |   4byt   |   4byt   |   4byt   |   4byt   |
    |__________|__________|__________|__________|

    Word 3
     __________ __________ __________ __________ 
    |   Byt9   |   Byt10  |   Byt11  |   Byt12  |  
    |  colour  |  PADDING |  PADDING |  PADDING |
    |   1byt   |          |          |          |
    |__________|__________|__________|__________|

    That's 12 bytes! Because of the order, we've just lost 4 extra bytes of 
    free memory!

    It might not seem like much but that soon adds up if you create
    multiple wasteful structs!

    Don't forget, the CPU access the entire word! Even if you've only got 
    one byte in a word, the whole word get's loaded by the CPU!

    Let's now have a look at an example:

*/


int main (int argc, char *argv)
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
    printf("\n");
    return 0;
}