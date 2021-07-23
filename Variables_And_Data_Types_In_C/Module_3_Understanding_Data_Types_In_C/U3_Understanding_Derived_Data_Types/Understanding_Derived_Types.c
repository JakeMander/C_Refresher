#include <stdlib.h>
#include <stdio.h>   //  For printf
#include <stdint.h>  //  For integral types
#include <stdbool.h> // For boolean types
#include <string.h> //  For strcpy

/*
   We'll now look at some of the derived types that
   are available to us in C and how they can be used.
*/

//  Function prototype for a later function demo.
//  We need to define our function's signature
//  first so the C Compiler knows to expect a
//  function of this type somewhere in the code.
//  Otherwise the C compiler won't know the
//  function exists when it comes to calling it
//  in main!
int CalculateSum(int x, int y);

int main(void)
{
    /*
        First up, let's take a look at Arrays.

        Arrays are a collection of values that share the
        same type. They are represented by a single name, and
        can be accessed with an index to retrieve individual members.

        Arrays are 0 indexed, so the first element is 0, the second
        is 1 and n is n - 1.

        An array of dimension 100 has an index which goes from
        0 to 99.

        Let's take a look at an example.
    */

    int array[5] = {1, 2, 3, 4, 5};

    /*
        An array decleration is broken down into three parts:
        1.  First, the type of value the array will store.
        
        2.  The name of the array and how many elements will be
            stored in it.

        3.  The values to be stored are placed inside the curly
            braces.

        Now let's try accessing some values from the array
        using the bracket notation to provide an index:
   */
    puts("Arrays!");
    printf("Index 0 (Position 1): %d\n", array[0]);
    printf("Index 3 (Position 4): %d\n", array[3]);

    /*
        C also supports multidimensional arrays! So a single
        dimension array is a single row of blocks to store things.

        A two dimensional array can be declared like so:
        int twoDimensionalArray[3][3] = ...

        This mean we have an array that looks like this:

        []  []  []
        []  []  []
        []  []  []

        In essence, we have an array which has 3 rows and 
        3 columns.

        We can also have a three dimensonal array. 

        For example:
        int threeDimensionalArray[2][3][3] = ...

        Which would be two sets of 3x3 arrays!

        Think of it in terms of X, Y and Z. 

        A length of 3, a height of 3 and a width of 2!

        We can have as many dimensions as we want for an array!
    */

    //  Intialise Array Using [Row][Column]
    int twoDimensionalArray[3][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    //  Access the 2nd Row, Third Column
    printf("\n2D Index [1][2]: %d\n", twoDimensionalArray[1][2]);

    int threeDimensionalArray[2][3][3] =
        {
            {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}},

            {{10, 11, 12},
             {13, 14, 15},
             {16, 17, 18}},
        };

    //  Second box, Third Row Across, Third column down.
    int value = threeDimensionalArray[1][2][1];
    printf("\n3D Index [1][2][2]: %d\n", threeDimensionalArray[1][2][1]);

    /*
        Note that in C, you can't initalise Arrays with
        a variable dimension size! The diemnsion size needs
        to be a concrete value that can be evaluated at
        COMPILE TIME!

        The commented code below is INVALID! and will throw 
        an error!
    */

    // const int x = 12;
    // char variableSizedArray[x];

    /*
    
        Another derived type is the "pointer" type which
        we have overed previously. Pointers store the memory
        address of another variable.

        For example:
    */

    puts("\nPointers");
    //   Declare a normal variable to point to.
    float var1 = 5;

    //   Declare our pointer which points to var1's address
    //   in memory.
    float *p = &var1;

    //   Print without derferencing the pointer value.
    //   This will be the address pointer p points to!
    //   We'll use the pointer format specifier for this!
    printf("Address Is: %p\n", p);

    //   Dereference pointer p. That is, go to the address
    //   that pointer p points to and retrieve the value
    //   stored there.
    printf("Value Is: %.2f\n", *p);

    /*
        Let's now have a recap on functions! 

        Functions are not a derived type, but will often
        implemenent them as part of their operation.

        A function simply represents a group of instructions
        to perform a given task. 

        As a bare minimum, every C program is expected to have
        at least one function, which is the main function - 
        The entry point for a C program!

        Remember the steps for using a function:
            - A function protype describing:
                - The function name.
                - The return type.
                - The required function parameters.
              Should be declared above the main function
              call inside your C file, or as part of a C
              header file (covered later).
            
            - The function body should be declared outside
              main using the previously defined prototype.

            - The function should be called inside main.
   */
    puts("\nFunctions");
    int sumCalculation = CalculateSum(5, 7);
    printf("Result Output: %d\n", sumCalculation);

    /*
        Now let's have a look at "structures" (or struct's).

        A structure represents a collection of members
        (variables) of possibly different types bundled together
        in a single user defined type. 

        In laymans terms, they're a block of memory that hold
        a number of different variables (of similar or different
        types). 

        The following example demonstrates how to define a struct
        and access it.
   
   */
    puts("\nStructures");

    /*  
        We can declare a struct inside our outside of main.
        Outside of main will have global scope (i.e accessible
        from anywhere in our program) whereas if defined inside
        main it can only be accessed from inside. 
   
        Here we define a struct to bundle together different
        variables that form up an address.
    */
    struct address
    {
        char name[100];
        char street[100];
        char cityOrTown[50];
        char county[50];
        char postcode[15];
    };

    /*   
        To initialise a struct of type address, we first
        need to call the "struct" keyword to tell C we want
        a struct, then call the name of the struct we want, 
        and finally, we give our new struct a name to identify
        it. 
   
        We then use curly braces to assign values to each
        member variable in the order they appear in the
        struct definition.
    */
    struct address newAddress =
        {
            "Bob's House",
            "42 Bobington Lane",
            "Bobton",
            "Bobshire",
            "BB24 B7L"};

    //   To access members of a struct, we can use the '.' notation
    //   like so:
    printf("Address Name: %s\n", newAddress.name);
    printf("Address Street: %s\n", newAddress.street);
    printf("Address Postcode: %s\n", newAddress.postcode);

    //   Alternatively, use the arrow notation '->' to access
    //   variables from a struct when accessed via a struct pointer.

    struct address newAddressTwo =
        {
            "Tim's House",
            "42 Timington Lane",
            "Timton",
            "Timshire",
            "TT24 T7L"};

    //   Here we define a pointer to an address struct called
    //   "newAddressPtr".
    struct address *newAddressPtr = &newAddressTwo;

    puts("\nAccessing Structs With Pointers");
    printf("Address Name: %s\n", newAddressPtr->name);
    printf("Address Street: %s\n", newAddressPtr->street);
    printf("Address Postcode: %s\n", newAddressPtr->postcode);

    /*   
        Finally, we also have the "union" type which represent
        a collection of members (variables), of the same or
        different type into a singe user defined type, but 
        stored in the SAME memory location.

        The union works in a similar way to the struct.

        You can DECLARE many different member variables
        of different types.

        However, the catch with the Union type is only
        one of those variables can contain a value
        at any given time. 

        In essence, the union defines the set of types you
        COULD possibly use for the an instantiated variable,
        but allows you to only use one at once!

        Union members are accessed using the '.' and '->'
        notations as per struct's.

        Let's look at an example:
    */

    puts("\nUnions");
    union addressUnion
    {
        char name[100];
        char street[100];
        char cityOrTown[50];
        char county[50];
        char postcode[15];
    };

    //   Struct Like Assignement:  We create using curly brackets.
    //   As "name" is the first member, "Charles" is assigned to that.
    union addressUnion addressUniOne = {"Charles"};

    /*  
        Notice how our only one defined value becomes the 
        accessed value regadless of what member we try to
        access. That's because addressUniOne references
        the first member variable inside the union with
        an assigned value.
    */
    printf("Union One Name: %s\n", addressUniOne.name);
    printf("Union One Street: %s\n", addressUniOne.street);
    printf("Union One Postcode: %s\n", addressUniOne.postcode);

    //  An alternate approach to intialising a union.
    //  Declare first then assign!
    union addressUnion addressUniTwo;

    //  Remember, we can't assign a string in C, so memcpy it!
    strcpy(addressUniTwo.postcode, "ZZ24 Z72");
    printf("Union Two Name: %s\n", addressUniTwo.name);
    printf("Union Two Street: %s\n", addressUniTwo.street);
    printf("Union Two Postcode: %s\n", addressUniTwo.postcode);

    //  What happens if we try and assign multiple values to a union
    //  and attempt to access them all...?

    strcpy(addressUniTwo.name, "Mike Stipe");
    strcpy(addressUniTwo.cityOrTown, "Atlanta");
    strcpy(addressUniTwo.postcode, "RE21 M92");

    printf("\nUnion Two Name: %s\n", addressUniTwo.name);
    printf("Union Two Street: %s\n", addressUniTwo.cityOrTown);
    printf("Union Two Postcode: %s\n", addressUniTwo.postcode);

    //  ... The last assigned union value will always occupy the
    //  union variable, which in our case was the postcode!
    return 0;
}

//  Define the body of our function that we earlier
//  defined in the protype at the top of our code.
int CalculateSum(int x, int y)
{
    return x + y;
}