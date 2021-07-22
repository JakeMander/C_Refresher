#include <stdlib.h>
#include <stdio.h>  //  For printf
#include <stdint.h> //  For integral types
#include <stdbool.h> // For boolean types

/*
    One of the first main type groupings in the C language is
    the "integral" types. These are numeric values that exist
    WITHOUT  fractional part (i.e. Whole numbers!).

    In this module we'll explore these values in more detail.
*/
int main(void)
{

    /*
        The first integral type we'll explore is "int". We've used
        this plenty already in the previous examples:

            -   Integers can be signed (+ or -) or unsigned!

            -   Integers can be short (16 bits: signed & unsigned).

            -   Integers can be long (32 bits: signed and unsigned).
                
            -   Integers can be long long (64 bits: signed and unsigned).

            -   Some CPU/OS architectures may have different bit lengths
                when handling integral values (Maybe you write a C program
                for a micro-controller that can only handle 8-bit integers). 
                C offers the fixed width integral type to allow you to define
                a specfic size used for a type to allow you to be
                able to run a C program on different systems.

            -   All of these types are available in the stdint.h or the
                inttypes.h (C99) library.

            Its worth noting there is no gaurantee what type of int 
            the keyword "int" will compile to. On my system, "int"
            is a long (32 bit) value. 
    */

    int unsignedInt = 100;
    int signedInt = -256;
    short int shortInt = 100;
    long longInt = 2147483000;
    long long longLongInt = 9223372036854775000;

    puts("The Integral Types");
    printf("Size of unsigned int: %zu bytes (%i bits)\n", sizeof(unsignedInt), sizeof(unsignedInt) * 8);
    printf("Size of signed int: %zu bytes (%i bits)\n", sizeof(signedInt), sizeof(signedInt) * 8);
    printf("Size of short int: %zu bytes (%i bits)\n", sizeof(shortInt), sizeof(shortInt) * 8);
    printf("Size of long int: %zu bytes (%i bits)\n", sizeof(longInt), sizeof(longInt) * 8);
    printf("Size of long long int: %zu bytes (%i bits)\n", sizeof(longLongInt), sizeof(longLongInt) * 8);

    /*
        The next type we'll cover is the char type!

        The char type can be:

        -   char (8-bits).

        -   Unsigned char (8-bits, 0 to 255).

        -   Signed char (8 bits, -127 to 127).

        The char type, when assigned letter values,converts them to their 
        corresponding integer ASCII values. So 'A' = 65 and 'z' = 122.
    */
    puts("\nThe Char Type");
    char A = 'A';
    char z = 'z';

    printf("Value of A is %c\n", A);
    printf("ASCII Value of A Is %i\n\n", A);

    printf("Value of z is %c\n", z);
    printf("ASCII Value of z Is %i\n", z);

    /*
        The Boolean type was added in the C99 standard.
        In essence, the boolean type allows you to store
        one of two values:

            - True (Equivalent integer value of 1)
            - False (Equivalent integer value of 0)

        These are useful for conditional logic, where
        your program needs to test for a particular
        condition being either true or false.

        The boolean library will actively convert 
        True and False to it's equivalent integer
        values and vice versa. 

        To use these types, the <stdbool.h> library
        needs to be imported.

    */
    puts("\nThe Boolean Type");
    bool isTrueBoolValue = true;
    bool isFalseBoolValue = false;
    bool isTrueIntValue = 1;
    bool isFalseIntValue = 0;

    if (isTrueBoolValue)
        printf("Is True Bool Value %d\n", isTrueBoolValue);

    if (isTrueIntValue)
        printf("Is True Int Value %d\n", isTrueIntValue);

    if (!isFalseBoolValue)
        printf("Is False Bool Value %d\n", isFalseBoolValue);

    if (!isFalseIntValue)
        printf("Is False Int Value %d\n", isFalseIntValue);

    /*
        To define and use static values, we can use enumeration.

        Enumeration allows us to assign integer values to defined
        name identifiers. 

        Enumeration helps make code readable by using easily
        identifiable names.  

        For example:

        SMALL = 1;
        MEDIUM = 2;
        LARGE = 3;

    */

   puts("\nThe Enum Type");
   enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

   enum week today;
   
   today = Wednesday;
   printf("Day is %d\n", today);

   today = Saturday;
   printf("Day is %d\n", today);
   
   /*
        C supports the use of "Bit Fields" in conjuntion with
        integral types to manually define the lengths of an 
        integral type variable. 

        For example, we could use a bit field to define an int
        variable of length 1 bit (0 or 1) to manually set up
        our own boolean flag.

        Bitfields can be appended to fields in a struct by
        appending a colon and an integer value to define
        the new bit size of the field. 

        In the below example, we can create a struct that takes
        up less space by explicitly setting the bit length of 
        fields to 1 bit.
   */
    puts("\nThe Bit Field");
    
    struct 
    {
        unsigned int boolFlag;
        unsigned int boolFlag2;
    } struct1;

    struct 
    {
        unsigned int boolFlag: 1;
        unsigned int boolFlag2: 1;
    } struct2;

    // Struct takes up 8 bytes - Two 4 byte long ints.
    printf( "Memory size occupied by status1 : %d\n", sizeof(struct1));

    //  Struct takes up 4 bytes - Two for struct, two 1 byte blocks for each 
    //  variable (but only 1 bit used in each block)
    printf( "Memory size occupied by status2 : %d\n\n", sizeof(struct2));

    /*  
        Finally we have the "void" type. As we've already seen, functions
        use this to define that no value is being used (i.e. the function
        does something but doesn't return a value or type, or that the
        function takes in no arguments.)

        I.e. 

        void testFunction (void)
        {
            // returns nothing, takes no parameters.
        }

        Also used in defining pointers.
    */

   /*
        C integral types have a set of format specifiers to define
        how they are output when used with the printf function.

        These are:
        %d - Decimal (signed int, short, char).
        %c - Char (in character format).
        %u - Decimal (unsigned int, unsigned short, unsigned char).
        %x - Hexadecimal (int, short, char).
        %o - Octal (int, short, char).
        %ld - decimal (signed long).
        %lu or %lx or %lo (as above but for longs, i.e
        long decimal, long hexadecimal, long octal.)
   */

    puts("Format Specifer Example");
    int num = 10;
    printf("%d\n", num);
    printf("Enter A New Value: ");
    scanf("%d", &num);
    printf("%d\n\n", num);

    /*
        As discussed earlier, C supports the use of the fixed width
        integer type which allows the developer to define integer
        types of different sizes so programs can be portable to 
        different system architectures.

        This functionality was introduced as part of the C99 spec
        and can be accessed using either the <inttypes.h> or
        <stdint.h> libraries.

        With fixed width types, we can define exact width variables:
            - int8_t (8 bit)
            - int16_t (16 bit integer)
            - int32_t (32 bit integer)
            - int64_t (64 bit integer)
            - uint8_t (8 bit unsigned integer)
            - uint16_t (16 bit unsigned integer)
            - uint32_t (32 bit unsigned integer)
            - uint64_t (64 bit unsigned integer)

        We also have the minimum width types, which defines an integer
        with a width of at least n-bits, where n is the number of bits
        defined in the type name. The available types are:

            -   int_least8_t (min 8-bit width integer).
            -   int_least16_t (min 16-bit width integer).
            -   int_least32_t (min 32-bit width integer).
            -   int_least16_t (min 64-bit width integer).
            -   uint_least8_t (min 8-bit width unsigned integer).
            -   uint_least16_t (min 16-bit width unsigned integer).
            -   uint_least32_t (min 32-bit width unsigned integer).
            -   uint_least64_t (min 64-bit width unsigned integer).

        We also have the high performance fast variants like so:
            - int_fast8_t (8 bit)
            - int_fast16_t (16 bit integer)
            - int_fast32_t (32 bit integer)
            - int_fast64_t (64 bit integer)
            - uint_fast8_t (8 bit unsigned integer)
            - uint_fast16_t (16 bit unsigned integer)
            - uint_fast32_t (32 bit unsigned integer)
            - uint_fast64_t (64 bit unsigned integer)

        The above can be used when the width of an integer needs to
        be specifed for a different system, but performance needs to
        be a consideration.

        Finally, when we want to use the maximum number of bits
        supported on the system for an integer type, we can use
        the greatst-widt integer types:

        - intmax_t
        - uintmax_t

        Next up, we have the Floating types!

        The simplest float decleration we have is with
        the "float" type. Float's are numbers that support
        a decimal value. Floats can be declared like the
        example below:
    */
    puts("\nThe Float Type");
    float floatOne = 22.5678;
    float floatTwo = 126789.54;

    /*
        If you assign a float value to an integer variable,
        the int will truncate the decimal! Always make sure
        you use float's for decimal values!

        The format specifier for floats is %f

        Float values in C are 32 bits (4-bytes) long! 1 Bit for the sign,
        8-bits for the exponent and 23 for the value (mantissa). 
    */
    printf("Float One Is: %f\n", floatOne);
    printf("Float Two Is: %f\n", floatTwo);
    printf("Length Of Float One Is: %d Bytes\n", sizeof(floatOne));
    printf("Length Of Float Two Is: %d Bytes\n", sizeof(floatTwo));

    /*
        We also have "double" for storing larger values. 
        Double values are 64 bits (8 bytes) long.

        %f can still be used as the format specifer to 
        handle 
    */
    puts("\nThe Double Type");
    double doubleOne = 2222222243.4329111;
    double doubleTwo = 328493221938.11132;
    printf("Double One Is: %f\n", doubleOne);
    printf("Double Two Is: %f\n", doubleTwo);
    printf("Length Of Double One Is: %d Bytes\n", sizeof(doubleOne));
    printf("Length Of Double Two Is: %d Bytes\n", sizeof(doubleTwo));

    /*
        Finally, we have the biggest floating type
        "long double". Long double float sizes depend on the system.
        They typically have between 64 to 128 bits in size. 

        You'll use these when you need the most precision when handling
        decimal values.

        The format specifier for these values is %lf
    */
   puts("\nThe Long Double Type");
   long double longDoubleOne = 2392239821.392839283213;
   long double longDoubleTwo = 3243294384.273821738781;

    printf("Long Double One Is: %lf\n", longDoubleOne);
    printf("Long Double Two Is: %lf\n", longDoubleTwo);
    printf("Length Of Long Double One Is: %d Bytes\n", sizeof(longDoubleOne));
    printf("Length Of Long Double Two Is: %d Bytes\n", sizeof(longDoubleTwo));


    return 0;
}