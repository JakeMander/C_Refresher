#include<stdlib.h>
#include<stdio.h>

/*
    In this unit we'll take a look at using bit fields with structs and how 
    they can be used to more efficiently manage memory allocation for structs
    and minimise on the padding applied. 

    So what do they do?

    A bit field enables access to specific bits of a struct's member variables.
    As mentioned previously, this is really useful for memory management in 
    structs as it means we can work with values that take up less than a byte
    of memory. 

    For example, for an int, we're going to use 4 bytes of storage by default 
    (or a word of memory). By using bit fields, we could specify that we only
    want to use 5 of those bits. That means we'd limit our range of values for
    that variable to 32 values (0 - 31 or 2^5 - 1). As we're only using 5 bits,
    C can optimise it's padding for the new int variable by assigning only
    one byte to contain all the values we need.

    This is really useful in situation where we can say with certainty what the
    range of values for a particular entity in our business logic will be.

    Why waste precious bytes of memory when we know our variable will never exceed
    a particular range of values!

    It's important to bear in mind that bit fields cannoy be used for variables
    that are of type char or float.

    Let's look at an example!
*/

struct {
    int shirtNumber; // 4 bytes
    int approximateHeightInFt; // 4bytes
} michaelOwen;

struct {
    int shirtNumber; // 4 bytes
    int approximateHeightInFt; // 4 bytes
} davidBeckham;



int main (int argc, int argv)
{
    /*
        What is the size of the following structs?

        4 + 4 bytes = 8 bytes = 2 words exactly! So no padding!
    */
    printf("\n\tMichael Owen: %ld bytes", sizeof(michaelOwen));
    printf("\n\tDavid Beckham: %ld bytes", sizeof(davidBeckham));

    /*
        But realistically, we can assume we have a solid understanding of the
        business logic surrounding our footballer business logic.

        A shirt number will never exceed 25 (that's the maximum number of
        players you can register in a team).

        A quick google will also show us that there are currently no 
        profesional footballers currently taller than 7 foot. 

        So with some quick binary algebra we can calculate some bit fields
        to reduce the amount of memory used for our structs:

        25 = 2^5 (max value of 31 (2^5 - 1))
        7 = 2 ^ 3(max value of 7 (2^3 - 1))

        The syntax for a bitfield is to follow the variable name with a ":"
        followed by the number of bits we want to limit for that variable.

        A special case to this is the ':0' bit field which can only be used
        with as am UNNAMED (i.e. just declare ':0' with no name as a member).

        This will essentially pad out the struct with space so that next
        bit field variable appears on the next word boundary.
    */

    struct footballer {
        int shirtNumber: 5; // 4 bytes
        int approximateHeightInFt: 3; // 4 bytes
    } wayneRooney;

    /*
        All being well, Wayne Rooney should be allocated only 4 bytes of
        memory. This is because rather than allocating two individual integer
        values (which would take us to 8 bytes), C can get away with 
        initalizing one, and using 8 of these bits to represent both values! 

        Thus we have saved on 4 bytes of data!
    */
    printf("\n\tWayne Rooney: %ld bytes", sizeof(wayneRooney));

    /*
        However, there is a subtle bug with our program at present... the issue
        is our member variables are SIGNED integers!

        You need to be careful with signed integers however! Remember the first
        bit for signed integers is always signed! So in actual fact we have:
        
        shirtNumber = 1 bit for sign + 4 for the value (our range is actually 0
        - 15 (2^4 - 1))

        approximateHeightInFt = 1 bit for sign + 2 for the value (our range is
        actually 0 - 3).

        Let's initalize wayne rooney's value and see what happens.
    */

   wayneRooney.shirtNumber = 17;
   wayneRooney.approximateHeightInFt = 5;

   printf("\n\twayneRooney: Shirt No. : %d \t Height: %d", 
   wayneRooney.shirtNumber, wayneRooney.approximateHeightInFt);

   /*
        What happens here is, we have 17:

        17 in binary is:

        00010001

        But computer's when dealing with signed numbers stores them as a 2's
        complement representation!

        If the Most significant bit (left most bit) is 0, C treats the binary 
        as a normal postive number.

        However, if the value is negative, C stores the value in a special way to 
        ensure certain quirks of signed binary artihmetic are bypassed.

        This approach stores the binary value as a the "two's complement" 
        representation.

        That is to say a binary number with it's MSB set to 1 will:

        -   First have all it's bits flipped to the opposite value. (1s complement)
        -   Have one added to the least significant bit (right most bit) (2scomplement).

        So C when we save -17, we expect:

        Binary:         00010001
        1s complement:  11101110
        2s complement:  11101111

        But the issue here is we only have 5 bits to play with. So really, 
        Wayne Rooney's shirt number is represented as the following:

        Binary 10001

        Thats the first five bits of 17!

        But that means we our new representation of 17 starts with a 1! So the
        C compiler treats it as if it's a negative value in it's twos complement
        form!

        So how do we find it's decimal representation?!

        Just run the two's complement again!

        Binary (twos complement):   10001
        1s complement:              01110
        2s complement:              01111

        1111 is 15! So C thinks we have -15!


        To get around this, there are two solutions:

        -   Increase the size of our values by one bit to account for the sign 
            bit. I.e. wayneRooney becomes:
   */

    struct footballerExpanded 
    {
        int shirtNumber: 6; // 4 bytes
        int approximateHeightInFt: 4; // 4 bytes
    } wayneRooneyExpanded = {17, 5};

    printf("\n\twayneRooneyExpanded: Shirt No. : %d \t Height: %d\n", 
    wayneRooneyExpanded.shirtNumber, 
    wayneRooneyExpanded.approximateHeightInFt);

    /*
        Alternatively, discard the signed bit and treat it as a value bit by 
        explicitly defining our ints as unsigned!

        This is perhaps the more intuitive approach for this problem as we don't
        expect either of those members to ever be negative values!
    */

    struct footballerUnsigned
    {
        unsigned int shirtNumber: 6; // 4 bytes
        unsigned int approximateHeightInFt: 4; // 4 bytes
    } wayneRooneyUnsigned = {17, 5};

    printf("\twayneRooneyUnsigned: Shirt No. : %d \t Height: %d\n", 
    wayneRooneyUnsigned.shirtNumber, 
    wayneRooneyUnsigned.approximateHeightInFt);

    printf("\n");
    return 0;
}