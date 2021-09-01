#include <stdio.h>
#include <stdlib.h>

/*
    So far, we've taken a look at statically allocated structures.

    In this unit, we'll focus on dynamically allocated structures, and this
    simple equation:

    Structures + Dynamic Memory Allocation =
    Dynamic Data Structures

    The memory for statically allocated structures is allocated on the stack, and is
    of a fixed size. 

    Dynamically allocated structures however are allocated on the heap, which means
    we have full control over their lifespan. 

    As such, we can dynamically allocate and resize structures on the heap. A 
    good example of such behaviour is the "Linked List" data structure.

    The "Linked List" is a dynamic data structure that can grow or shrink in 
    size at runtime.

    When compared to a static array of fixed size, a linked list is a flexible,
    non-contiguous alternative.

    To model the Linked List data structure, we can create a Structure for a 
    Linked List node like so:

*/

typedef struct LinkedListNode
{
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

/*
    In our new Linked List Node, we track:

        - A generic pointer to any type of data.
        - A pointer to another LinkedListNode which, when followed, takes us to
          the next node in the list.

    To model our Linked List, we need a starting node which is referred to as 
    the head. This is the first initialized node in the list. This node's 
    associated next pointer takes us to the next node in the list.

    To indicate the end of the list, we have a tail node whose next pointer is
    set to NULL. This indicates the current terminus of the list, as no 
    additional nodes have been linked.

    By dynamically allocating this strucutre, a linked list that can grow or
    shrink in size based on the needs of the application can be constructed.

    How can we go about dynamically allocating our nodes? The solution lies in
    Example 1 in our main function!
*/

int main (void)
{
    /*
        Example 1: Dynamicallly allocating a Structure.
        
        This snippet of code has allocated enough memory for one LinkedListNode
        on the heap. 

        Now we have a reference to our new node established through our node 
        pointer, we now need to assign values to the node's structure members.
    */
    LinkedListNode *head = (LinkedListNode*) malloc(sizeof(LinkedListNode));

    /*
        Example 2: Accessing Structure members via pointers.

        The thing to note with Structures is, if we have a pointer to a 
        Structure, we CANNOT use the dot notation to access the struct's 
        members.

        Why? Because a pointer needs to be dereferenced to gain access to the
        actual values stored at the targetted address! The dot notation is
        not configured to do this!

        Instead the C language kindly provides arrow notation to read and 
        write directly to structure members via a pointer!

        In essence, the arrow syntax will dereference each member for us
        without us having to explicitly use longwinded star notation to 
        do it. 

        For example, we can use:

        head -> data = VALUE TO STORE

        instead of:
        
        *(head).data = VALUE TO STORE

        Notice above how we dereference the structure first in order to get
        our reference to the struct, and then access it's member.

        The arrow function just simplifies this whole process and cleans up our
        code!
    */

    int data = 42;
    head -> data = &data;

    printf("\nHead's Data Address: %p\n", head -> data);
    printf("Head's Data Value: %d\n", *(int*) (head -> data));

    /*
        The above is the same as the longwinded:
        (*head).data = &data;

        Always prefer the arrow syntax!
    */


    return 0;
}