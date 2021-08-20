/*
    In this exercise we'll be looking at some of the pitfalls to be aware of 
    when managing memory dynamically and some of the most common forms of 
    memory misuse that occur when allocating and deallocating memory using
    the C standard dynamic memory functions. 

    As we've previously mentioned, dynamic memory can be a powerful tool in
    C and can greatly improve performance when used correctly.

    However, misusing the dynamic memory allocation tools can cause all sorts
    of problems such as memory leaks which significantly reduce performance
    and cause all manner of undefined behaviour in your applications.

    The key here is not to panic when handling dynamic memory. Yes, you can
    cause some big issues if you don't handle dynamic memory in the proper
    manner, but avoiding these issues can be simple to achieve if you know
    how memory mismanagement occurs and some of the tell-tale signs of bad 
    memory management!

    In this section, we'll explore some of the most common indications that
    memory has been misused in C, and explain how to avoid these instances
    occuring in the first place!
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct Person
{
    int age;
    char* name;
} Person;


int main(void)
{

    /*
        There are four main causes of memory mismanagement in C. These are:

        - Dangling Pointers
        - Double Frees.
        - Forgetting to use "sizeof" when calling calloc/malloc/realloc
        - Not checking for NULL pointers returned from calloc/malloc/
          realloc functions. 

          The following code will demonstrate the above bad practices and
          explain each one in greater depth:
    */


    /*
        Example 1: Dangling Pointer

        A dangling pointer results in you losing access to an allocated block
        of memory on the heap.  This is typically caused by overwriting or
        allowing a reference to an allocated block of memory to go out of
        scope. 

        The pointer then "dangles" as, though it still exists in your program,
        there is no means to reference it, and therefore, no means by which
        you can ever locate the memory address of the memory in the heap it
        points to. Therefore the memory can no longer be deallocated and will
        not be reassignable for the remainder of the program!

        Takes the example below. As we know, malloc returns a void pointer which
        we cast to a typed pointer in order to reference the new block of memory
        in the heap, and define the type of value stored at that location.

        If we then overwrite this value with NULL, we have in essence, permenantly
        removed the reference to the memory address that is the start of our newly
        created memory block on the heap. As a result, we now have a memory leak!
    */
   Person *person1 = (Person*)malloc(sizeof(Person));
   person1 = NULL;

   /*
        Example 2: Double Frees

        Double frees happen when you attempt to free and already freed block of
        memory. This can result in undefined behaviour occuring in your program
        (i.e. behaviour that is unexpected and indeterminate of a C function's 
        expected behaviour.).

        As we can see in the example below, we call the free deallocation function
        twice on the person2 pointer to a new block of memory on the heap. In doing
        so, we have freed person2 twice and may have caused a memory leak or 
        introduced undefined behaviour!

        Just know that any code now written after the second free has the potential
        to be highly unstable! There is no telling wether the second free caused a
        memory leak or not! 

        The best way to get around this issue is to assign the value NULL to a
        pointer whenever it has been freed. In doing this, any accidental attempt
        to free an already freed memory block will be prevented if you first check
        to see if a pointer is pointing to a NULL reference or not.
        
        This goes back to the idea that with dynamic memory management, YOU ARE 
        RESPONSBILE FOR THE BOOKKEEPING.

        That means you need to keep tabs on the memory you have allocated and
        deallocated. C isn't going to do this for you!
   */
   Person *person2 = (Person*)malloc(sizeof(Person));
   free(person2);
   free(person2); // Bad move! Double free prone to undefined behaviour!

   /*
        Example 3: Forgetting to use "sizeof"

        Forgetting to use the sizeof operator can introduce a number of issues with
        dynamic memory allocation including:

        - Loss of cross platform capabilities (i.e. data types are different sizes on
          different systems. Static byte sizes may not be large enough to contain
          data types on some systems, or too big and wasteful on others!)

        - The introduction of huge security vulnerabilities. If you use the wrong size
          memory blocks for the types you dynamically want to store, you run the risk
          of buffer overflows and the accidental overwriting of memory. 

          If you're memory block is too small to hold a value, C will stil try to store
          a value of a defined type at the starting memory address pointed to by the
          returned pointer! If the values you then store in that memory block are too
          big for the memory block in question, then that's too bad. 

          C will simply start at the memory address pointed to by the pointer and keep
          writing data in the heap until it finishes... even if that means going in to
          memory that lives outside the size of the memory block we just allocated.
   */
   int *int_ptr = (int*)malloc(2); // 2 bytes is too short for an int on a windows 64 bit OS! Undefined behaviour!
   free(int_ptr);

   /*
       Example 4: NULL Pointer returned from malloc, caloc or realloc.

       Remember, if malloc, calloc or realloc fails to successfully
       allocate a block of memory due to an error or a shortage of
       heap memory, then a NULL reference is returned!

       To avoid errors that can occur by accidentally attempting to
       dereference or handle a null pointer, it's always best practice
       to first check if the pointer returned by a call to malloc, calloc
       or realloc and then handle the situation appropriately if the 
       returned pointer is NULL, and therefore the memory allocation has
       failed.

       For example, the below code is risky (i.e. we might not have
       100000000 bytes available on the heap for the program). If we
       a null pointer get's returned, but we still try to 
       dereference the pointer in order to get full access to the 
       memory block it points to so we can change the name value to
       'A', then we most likely will end up with undefined behaviour.

       A better approach would be to implement the following:

       char *name = (*char) malloc(100000000);

       if (name)
       {
            *name = 'A';
       }

        In C, NULL evaluates to 0. In addition, a conditional statement will
        always evaluate to false if the condition evaluates to 0, or true if
        the condition evaluates to a non-zero value.

        In the above example, we only dereference the pointer returned from 
        malloc if the pointer is non-null (i.e. a non zero value in the if
        statement). If the value is null, then don't do anything! Otherwise
        we'll end up with undefined behaviour!
   */

  char *name = (char*)malloc(100000000);
  *name = 'A'; // We could be dereferencing an invalid pointer here!
    
    return 0;
}