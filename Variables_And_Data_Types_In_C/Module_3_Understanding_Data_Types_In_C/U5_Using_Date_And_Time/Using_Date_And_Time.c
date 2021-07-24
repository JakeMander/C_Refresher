#include <stdlib.h>
#include <stdio.h>   //  For printf

/*
   We'll now look at how to cast values to other types
   and how qualifiers can be used in C.
*/

int main(void)
{
    /*
        We'll start by covering type casting.

        Type casting is the process of converting one data
        type into another.

        Type casting in programming typically happens via
        two approaches:

            -   Implicit.
            -   Explicit.
        
        Implicit is "implied" casting. It's where the language
        will automatically convert one type to another, because
        your code implies that's what you want to do (i.e. taking
        a variable of type int and assinging it to a variable of type
        float or double).

        In cases such of these, a lot of programming languages 
        handle this behind the scenes without warning you or throwing
        an error. That's because you're taking a type of 16 bits
        (in C) and trying to reassign that values to variable that
        can handle 32 or 64 bits. 

        There's no issue there. No precision is lost because the 
        integer can be rejigged into the larger memory size without
        having to trim it down or lose any bits.

        This is typically refered to as "type promotion".

        Alternatively, you may attempt an operation such as 
        dividing two integers which produce a floating point
        result. 

        i.e. 10/3 (two ints, floats would be 10.0 and 3.0)

        The compiler looks at the two values and, becuase
        in memory the two integers have no manitssa or exponent,
        does the next best thing and simply truncates the value.

        This is implied behaviour. It's what the C compiler knows
        what to do in instances such as these when they arise.

        When integers are divided together, the C compiler will 
        always truncate the remainder (the fractional part) because
        it doesn't have the memory structure to handle it! 

        Explicit casting however is instructing the compiler to 
        perform a type converson (if it can).

        For example, take the following:
    */

    float a = 35;
    float b = 17;

    float resultOne = 35 / 17; // Implicit Conversion. Remainder dropped!
    float resultTwo = (float) 35 / 17; // Explicit (cast operator used) - Keep the remainder!

    printf("Result: %f\n", resultOne);
    printf("Result: %f\n", resultTwo);

    /*
        Our first conversion which relies on division of two
        integers returns a non fractional value despite our
        recieving variable being of type float. It should be 
        able to handle the decimal! But why doesn't it?

        Well the operation returns the result of a division 
        between two integers (which is a value of type integer).
        Because both types are integer, C is built to simply truncate
        the decimal and treat the result as an integer.

        Then, because the C compiler implictly knows how to convert
        an int to it's equivalent float value, C converts the
        truncated int value to it's equivalent floating point
        equivalent in memory... which remiains truncated.

        However, in the second example, we mangage to bypass this.

        The reason for this is in C, the division operator knows
        what to do when faced with a division between a float and an 
        int (that is, convert the int to a float and do the division
        between two floats!).

        In the second example, we explcitly tell C, "Treat 32 as if it
        were a floating point value". The C compiler then dutifully 
        converts 32 to it's floating point equivalent in memory. 

        When the fp 32 and integer 17 are passed to the division
        operator, the C compiler then goes "Okay, i know how to handle
        this" and performs the conversion on 17 to turn it into a 
        floating point value.

        No truncation occurs as both operands are now floats
        and the memory for both the result and the variable we
        assign the result to are large enough to handle the
        structure of a floating point value!

        Alternatively, we could have done:

        35.0f/17 (with f explcitly telling C to treat
        35 as a floating point value.)

        Let's have a look at how C handles the integral
        promotions.

        Integral promotions:
            -   Are performed by type rank (i.e. Char lowest,
            long long double highest).
            
            -   Happens when applying operation to a given
            integer type.

            -   Type is promoted if its rank is less than the
            int type rank.

            -   If values of the original type can be represented
            by an int, then the original type is converted to
            int, otherwise it is converted to unsigned int 
            (for example, operations between char values will
            promote their operands to ints)

            Let's have a look at the example below:
    */

    //  Signed char - values -128 to 127
    signed char cResult;
    signed char cResultOverflow;
    signed char c1 = 100;
    signed char c2 = 3;
    signed char c3 = 4;

    /*  
        In this operation, multiplying 100 by 3 gives us
        300. This is outside the range of the signed char
        values! 

        However, C will implicitly convert any operations
        between char values to int, then convert them back
        to the signed char (original type) when the operation
        is finished. 

        This means that in our example below, we get:
        300 / 4 (because some special behind the scenes
        conversion is going on, BODMAS is not followed)
        which equals 75. 

        Once the operation is complete, C converts this 
        back to a signed char. 75 sits in the range of 
        -128 to 127 so all is good. 'K' is returned!

        However, if we changed C3 to 1, we'd end up with
        300 / 1 which is 300. 300 would be implicitly 
        converted back to char, despite being outside of the 
        char range of values, so overflow would occur.

        300 - 255 is 45 which in ASCII is 44 (ASCII
        stats from 0 so minus 1).

        The results from both operations are demonstrated 
        below.
    */


    cResult = c1 * c2 / c3;
    cResultOverflow = c1 * c2 / 1;
    puts("\nIntegral Promotion Demo");
    printf("cResult = %c\n", cResult);
    printf("cResult = %c\n", cResultOverflow);

    /*
        Let's now have a look at the usual arithmetic conversions
        for integral types. 

        In C these occur when an operation occurs between operands
        of different types. 

        When this happens, C will perform an automatic conversion to
        find a common type for all operands and the result of the 
        operation. This occurs for most operators that can be applied
        to integral types. 

        This is done to ensure operations are performed safely and produce
        a precise and logical output.

        Let's take a look at the example below.

        Here we have an int value and a char. What happens when we add the int
        to the char?

        As we know, a char is given by it's numeric code in the ASCII table, so
        C converts 'a' to it's integer ASCII value (97) and adds the two values
        together. As both int and char can be int's C will convert the output 
        value to int as well, which will then be assigned to x. It does this
        because, as mentioned before, C wants to find the common type for both 
        the operations and the returned value. 

        More details on the "airthmetic conversions" C performs behind the scenes
        by the C compiler can be found here:
        https://docs.microsoft.com/en-us/cpp/c-language/usual-arithmetic-conversions?view=msvc-160

    */
    puts("\nUsual Arithmetic Conversions");
    int intVal = 10;
    char charVal = 'a'; // ASCII is 97

    intVal = intVal + charVal;
    printf("Value of intVal (int) + charVal (char) Is: %d\n", intVal);

    /*
        Finally, let's take a look at some of the Type Qualifiers in C.

        In C, type qualifiers represent keywords which are used to
        modify the properties of a variable.

        For example:

        const - A keyword that makes a variable readonly. Once
        a const variable is  declared, that value 
        CANNOT CHANGE! Attempting to do so results in a compile
        time error!

        Subsequently, you should avoid initalising a const without
        any value... if you do that, the variable is initalised to
        null, but because it's const, you can't reassign it with
        anything!

        consts are useful for values that you know for absolute
        certainty should never change! For example, gravity 
        (9.81m/s) should never be altered by a program once
        defined. 

        Using const helps prevent your program from programmers
        coming along and attempting to rewrite varaibles that
        need to remain unchanged. 

        volatile - volatile variables are variables that can
        be modified by something outside of the context of 
        your program, but not modified explicitly by your
        program
    */

    //  The following is invalid. You can't change a const once it's assigned!
    //  const  int constVar = 42;
    //  constVar = 24; 

    return 0;
}