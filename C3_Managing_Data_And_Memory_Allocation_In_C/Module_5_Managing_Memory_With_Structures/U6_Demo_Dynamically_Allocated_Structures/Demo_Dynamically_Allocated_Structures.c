#include <stdlib.h>
#include <stdio.h>

/*
    In this demo we'll see dynamically allocated structures in action through
    the implementation of a working linked list data structure.

    In this demo, we will:

    - Define types for the linked list dynamic data structure.

    - Dynamically allocate and free structure memory.

    - Write and read values to and from structures using pointers.

    - Become familiar with the linked list data structure.
*/

//  Struct to represent a node in a linked list.
typedef struct LinkedListNode 
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

//  Struct to track the start of the LinkedList and the number of elements in
//  a linked list.
typedef struct LinkedList 
{
    int count;
    LinkedListNode *head;
    LinkedListNode *tail;
} LinkedList;

/*
    Function Prototypes: Linked List Behaviour
    Function declerations to define Linked List behaviour. 

    InitLinkedList - Creates a new linked list and returns a pointer to the new
    allocated memory storing the list data including where the head and tail 
    is.

    DestroyLinkedList - Iterates through the list, deallocates the memory allocated
    for each node then deallocates the list itself. 

    PrintLinkedList - Prints out the data and index of each node stored in a linked list.

    InsertNode - Add's a node with it's data set to the provieded parameter to the tail of the 
    LinkedList

    RemoveNode - Removes a node from the linked list based on a provided LinkedList node reference. 
*/
LinkedList* InitLinkedList();
void DestroyLinkedList(LinkedList*);
void PrintLinkedList(LinkedList*);
void PrintNode(LinkedListNode*);
void InsertNode(LinkedList*, int);
void RemoveNode(LinkedList*, LinkedListNode*);

int main(int argc, char* argv[])
{
    LinkedList *myList = InitLinkedList();

    //  If the memory allocation for the linked list fails, exit the program 
    //  gracefully.
    if (!myList)
    {
        return 1;
    }

    InsertNode(myList, 1);
    PrintLinkedList(myList);

    InsertNode(myList, 2);
    PrintLinkedList(myList);

    InsertNode(myList, 3);
    PrintLinkedList(myList);

    RemoveNode(myList, myList -> tail);
    PrintLinkedList(myList);

    DestroyLinkedList(myList);

    return 0;
}

LinkedList* InitLinkedList()
{
    LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));

    if (list != NULL)
    {
        list -> count = 0;
        list -> head = NULL;
        list -> tail = NULL;
    }

    return list;
}

void DestroyLinkedList(LinkedList *list)
{
    if (list == NULL)
    {
        return;
    }

    LinkedListNode *current = list -> head;

    while (current != NULL)
    {
        //  Store a reference to the next node we need to traverse to
        //  so we can still move after our current node is deleted!
        LinkedListNode *next = current -> next;
        RemoveNode(list, current);
        current = next;
    }

    free(list);
    printf("List Destroyed\n");
}

void PrintLinkedList(LinkedList *list)
{
    if (list == NULL)
    {
        return;
    }

    LinkedListNode *current = list -> head;

    while (current != NULL)
    {
        PrintNode(current);
        current = current -> next;
    }
    printf("\n");
}

void PrintNode(LinkedListNode *node)
{
    //  If next value is not null, print an empty string, otherwise print NULL.
    printf("[%d] -> %s", node -> data, node -> next ? "" : "NULL");
}

void InsertNode(LinkedList *list, int data)
{
    if (list == NULL)
    {
        return;
    }

    LinkedListNode *newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    newNode -> data = data;
    newNode -> next = NULL;

    //  The old tail is no longer the tail, so first update the list's tail
    //  reference to our newly inserted node, and then replace the lists old
    //  tail node with the newly inserted node.

    if (list -> tail == NULL)
    {
        list -> head = newNode;
        list -> tail = newNode;
    }

    else
    {
        list -> tail -> next = newNode;
        list -> tail = newNode;
    } 
    list -> count++;
}

void RemoveNode(LinkedList *list, LinkedListNode *node) 
{
    if (list == NULL || list -> head == NULL || node == NULL )
    {
        return;
    }


    /*
        Here we have a special case. If we attempt to delete the node that is
        the head we may run into a case where we attempt to delete the head but
        still have nodes linked to it. In this case, we need to repoint the 
        list's head to the node that the head currently points to, otherwise
        we'll lose the pointer which takes us to our next sequence of nodes
        and we'll end up with a load of hanging pointers

        Also, in the event we remove our last node from the list, we need to 
        update the List struct so that it's head is set to null. 
    */
    if (list -> head == node)
    {
        printf("Destroying: [%d]\n", node -> data);
        LinkedListNode *next = list -> head -> next;

        if (next == NULL)
        {
            list -> tail = NULL;
        }

        free(list -> head);
        list -> count--;
        list -> head = next;
        return;
    }

    LinkedListNode *current = list -> head;
    LinkedListNode *previous = NULL;

    while (current != NULL)
    {   
        //  If we've navigated to the node we need to delete, deallocate the node
        //  and repoint the previous node to the tail of the list (or next available
        //  node if one exists).
        if (current == node)
        {
            printf("Destroying: [%d]\n", current -> data);

            //  Stop gaps appearing after we remove a node by connecting the
            //  previous node to the current node's neighbour (Or by setting it
            //  to NULL if no neighbout exists).
            previous -> next = current -> next;

            if (current -> next == NULL)
            {
                list -> tail = previous;
            }
            free(current);
            break;
        }  

        //  We've not yet found the node we need to delete in the list... so 
        //  move to the next node.
        else
        {
            previous = current;
            current = current -> next;
        }
    }
    list -> count --;
}

