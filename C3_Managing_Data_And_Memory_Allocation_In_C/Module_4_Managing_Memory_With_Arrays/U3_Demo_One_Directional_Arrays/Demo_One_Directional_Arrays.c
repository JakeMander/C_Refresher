/*
    Let's move on to our first demo for this module!

    Here we'll learn how to declare and initialize one-dimensional arrays on
    the stack, how to use array notation to read from and write to arrays and
    how arrays decay to pointers when called by name.


*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
/*
    Here we define a macro of name "ARRAY_SIZE". Macro's are something we've 
    not yet covered but will be discussed in depth in a later section.

    In essence, Macros are pre-processor directives, that is, something that is
    ran in our code before compilation takes place.

    When we "define" a value, whereever the defined macro name appears in our 
    code, it is replace with the value assigned to it in the define statement.

    In our case, the pre-processor iterates through our code and replaces all
    instances of "ARRAY_SIZE" with the value 4.

    We can use this to define the size of our arrays at runtime.

    But wasn't it illegal to declare an array in C with a variable name? Yes
    but Macro's aren't variable's! Because the name "ARRAY_SIZE" is replaced
    with the value of 4 prior to compile time, using macro's in an array 
    initalization is completely fine!!

    Why have we used this Macro then?

    Well in C, arrays do not automatically track the length of themselves like
    in other high level languages! So if you want to track the size of an
    array, you'll typically track this with a variable or a function which
    calculates the size of an array at runtime... This does however come with a
    number of gotchas you'll want to look out for.

    For simplicity, we'll keep track of the array sizes using this macro 
    definition.
*/
#define ARRAY_SIZE 4

typedef struct Person 
{
    int age;
    int id;
} Person;

int main(int argc, char *argv[])
{
    /*  
        Example 1: Declare and initalize the arrays we'll be using for this 
        demo. 

        In this example, declaring and initalizing arrays has been demonstrated. 
    */
    int numbers[] = { 1, 2, 3, 4 };
    const double floats[] = { 1.23f, 1.45f, 1.67f, 1.99f };

    /*
        Let's recap on what arrays of characters mean in C!

        As we've covered numerous times previously, an array of characters in C
        is a string! 

        Strings in C are delimitted (that is they have their end signposted) 
        with a null character ('\0') so that the compiler knows when it's
        reached the end of a string!

        When a character array is initalized, the C compiler will help us out by
        inserting this character for us at the end of the array. 

        So really, the "name" array is actually:
        name = {'J', 'a', 'k', 'e', '\0'};

        Our name array now has a size of 5! It's important not to forget
        that!

        Be careful when explicitly specifying the length of your array. If you
        assign a number of characters equal to the size of the array, then
        the null terminator is added outside of the array and is therefore
        at risk of being overwritten by other parts of your program,
        thus causing undefined behaviour!

        For example:

        char badString[5] = "Oppps";
        
        Becomes:

        |'O'|'P'|'P'|'P'|'S'| \\End Of Allocated Array Memory\\ |'\0'| 

        The null terminator is really important! Most C string processing
        functions rely on it being there to know when to stop!
    */
    const char name[] = "Jake";

    const Person people[] = 
    {
        { 47, 1} ,
        { 35, 2 }
    };

    /*  
        Example 2: Looping over array members using array notation.

        Here we use the ARRAY_SIZE macro to make sure we don't step outside the
        bounds of our array!

        It's important we stay inside our array size and keep track of the 
        lengths of our arrays in C, otherwise there isn't really anything 
        preventing us from skipping outside the bounds of our array
        and writing to or reading from memory we shouldn't have access to.
    */
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\nNumber: %d\n", numbers[i]);
        numbers[i] += 2;
    }

    /*
        Example 3: Proving Array Names "decay" To Pointers

        In this example, we use "assert" to prove that array names decay to 
        pointers.

        Assert will compare two values and determine if they are equal in 
        value. If not, then the program crashes. 

        Here we check to see if calling the "numbers" array by name gives
        us the same memory address pointed to when we reference the 
        address of index 0 in our numbers array.
    */
    
    assert(numbers == &numbers[0]);
    printf("\nStarting address of the 'numbers' array by array name: %p\n", numbers);
    printf("\nStarting address of the 'numbers' array by pointer to the first element: %p\n\n", &numbers[0]);
    return 0;
}

