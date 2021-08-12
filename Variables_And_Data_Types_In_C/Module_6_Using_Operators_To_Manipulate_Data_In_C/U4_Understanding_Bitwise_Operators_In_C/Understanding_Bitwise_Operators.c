#include <stdio.h>
#include <stdlib.h>

/* 
    In this demo, we'll be looking at the bitwise operators. We'll typically
    use these when we want to manipulate variables on the bit level. This could
    be used in things such as encryption, bit arithmetic or networking to name
    but a few use cases.
*/
int main(void)
{
    /*
        Bitwise operators enable us to perform bit operations on data, that is
        to process a value bit by bit.

        Before we explore the C bitwise operators, let's explore the concepts
        behind them first.

        As we know, the size of datatype varies depending on the operating 
        system the program is running on, and how those types are implemented.

        On a 64 bit Windows operating system, an int is typically represented
        by a 32 bit value. A char is 8 bits and a long long is 64 bits.

        If we do the following:
    */

   int number = 11;

   /*
        Then the binary representation is:
        00000000 00000000 00000000 00001011 

        Note that the full number of bits are used to help the system identify
        the lenght of the variable being handled and provide the full set of
        data that represents the type.

        To compare, let's have a look at us defining a char instead...
   */

  char letter = 'A';

  /*
        The binary representation of ASCII A is:

        01000001 (8 bits = char | A has an ASCII decimal value of 65)

        By using bitwise operators, we can process the bits contained in these
        variables bit by bit! The result will be determined by the operation
        once it's finished processing the bits in the variable/s.

        Now, let's start exploring some of the Bitwise operators available in 
        C.

        The Bitwise operators are:
            - Bitwise AND (&)
                - Compares operand's bits and returns one if BOTH bits are one, 
                  else it returns 0.
                - Returns a value that is composed from the comparison of each 
                  bit.
                - For example:

                OPERATION    &
                Decimal 12 = 00001100
                Decimal 21 = 00010101
                Result =     00000100

                OPERATION    &
                Decimal 11 = 00001011
                Decimal 15 = 00001111
                Result =     00001011

            - Bitwise Inclusive OR (|)
                - Compares operand's bits and returns one if EITHER bit is one,
                  otherwise the bit is set to 0.
                - Returns a value that is composed from the comparison of each 
                  bit.
                - For example:

                    OPERATION    |
                    Decimal 12 = 00001100
                    Decimal 21 = 00010101
                    Result =     00011101

                    OPERATION    |
                    Decimal 11 = 00001011
                    Decimal 15 = 00001111
                    Result =     00001111
            
            -   Bitwise Exclusive OR - XOR (^)
                - Compares operands' bits and returns one if only one of the 
                  bits is one, else it returns zero.
                - Returns a value that is composed from the comparison of each 
                  bit.
                - For example:

                    OPERATION    ^
                    Decimal 12 = 00001100
                    Decimal 21 = 00010101
                    Result =     00011001

                    OPERATION    ^
                    Decimal 11 = 00001011
                    Decimal 15 = 00001111
                    Result =     00000100

            -   Bitwise NOT (~)
                - Flips operand's bits, converting ones to zeros and zeros
                  to ones. 
                - For example:

                    OPERATION    ~
                    Decimal 12 = 00001100
                    Result =     11110011

                    OPERATION    ~
                    Decimal 21 = 00010101
                    Result =     11100110

                    OPERATION    ~(&)
                    Decimal 11  = 00001011
                    Decimal 15  = 00001111
                    Result &    = 00001011
                    Result ~(&) = 11110100
            
            -   Left Shift (<<)
              - Move operand's bits to the left N Positions.
            
            -   Right Shift (>>)
              - Move operand's bits to the right N positions. 

      Let's now run an example using our previous letter variable.
  */

  /*  
      Essentially, a negative ASCII value is used to index the extended
      ASCII table but in reverse. For example:
        
        -1 (i.e. 256 - 1 = 255 in Extended ASCII) = nbsp
        -2 (i.e. 256 - 2 = 254 in Extended ASCII) = ■
        -3 (i.e. 256 - 3 = 253 in Extended ASCII) = ²

        -128 (i.e. 256 - 128 = 128 in Extended ASCII) = Ç 
        -127 (i.e. 256 - 127 = 129 in Extended ASCII) = ü
        -126 (i.e. 256 - 126 = 130 in Extended ASCII) = é  
        
        Use the following ASCII table as your reference:
        https://coding.tools/ascii-table
  */
  signed char notLetter = ~letter; // Evaluates to -66 ( 256-66 = 190 (¥))
  printf("Char Value Is %d : Char Letter Is %c\n", notLetter, notLetter);

  /* 
    Now let's have a look at some excamples of bit shifts:
  */

 int num = 65; // Binary Representation : 00000000 00000000 00000000 01000001
 
 /*
    In this example we shift ALL OF the bits in the num variable by one to the
    left. In doing so, we are essentially shifting each bit up by a factor
    of two (in big-endian binary, the value of each bit doubles as we move up to 
    the left of our bytes because we raise 2 to the power of n where n is the
    number of bits to the left we have gone).

    Conversely, if we shift to the right, we end up halving our values, as each
    bit has essentially been halved during the shift right!

    It is IMPORTANT TO NOTE that if you shift a value off the end of your 
    bytes for the variable (i.e. say we shift 65 to the right twice and our 1 
    falls off the end of the least significant byte) then that bit is now
    gone! Any attempt to shift the 1 back on will not work! It has been lost, 
    and the value will now remain 0 giving us 64!
 */
 int numShiftLeftOne = num << 1; 
 int numShiftRightTwo = num >> 2;

 printf("Shift Left One = %d\n", numShiftLeftOne); // One shift. So double!
 printf("Shift Right Two = %d\n", numShiftRightTwo); // Two shifts. So half twice!
}