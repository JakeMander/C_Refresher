#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
    In this lesson we'll explore how to use structures with pointers.

    In the example below we have a person struct made up of two member 
    variables.

    After our decleration of the person struct, we then create a variable
    of the "person" struct type followed by a pointer to a struct variable.

    We can then initalize our ptr variable with the address of the 
    "myPerson" variable using the '&' (address of) operator.
*/

int main()
{
    struct person 
    {
        char name[32];
        int age;
    };

    struct person myPerson;
    struct person *ptr; 

    ptr = &myPerson;

    /*
        With our pointer to the "person" type set up, we can now use pointers
        to set the member variables of the person variable.

        To do this, we use the arrow operator ('->').

        As we've covered before, when accessing a struct directly, we typically
        use the '.' notation to access member variables. However, with a 
        pointer, in order to gain direct access to the variable we first have to
        dereference the pointer. If we did this in code, it would look like this:
        
        (*ptr).name;

        This is a bit long winded, so Dennis Ritchie kindly gave us the '->'
        operator as a shortcut.  
         
        Just remember, the arrow operator dereferences a pointer to a struct 
        and then accesses the struct variable member represented by the right 
        hand side of the arrow.

        Remember, ptr points to the memory location. So when -> dereferences it, 
        we are actually changing the values of the myPerson struct.
    */

   strcpy(ptr->name, "MANDER, Jake");
   ptr -> age = 25;

   printf("\n\tName: %s \tAge: %d", ptr -> name, ptr -> age);

   //   And to compare, let's use the dot notation on our normal struct variable. 
   printf("\n\tName: %s \tAge: %d", myPerson.name, myPerson.age);

   return 0;
}