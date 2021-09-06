/*
    In the following file, we declare all of the structures and function 
    prototypes to be used by our source code (.c) file where we will 
    implement the implemntation of our code!

    Doing so seperates out our code definitions and implementations which
    cleans up code! 
*/

#include <memory.h>
#include <stdbool.h>

//  Prevents multiple header files from being imported.
#ifndef MEM_POOL_MANAGER_H
#define MEM_POOL_MANAGER_H

typedef struct MemoryPoolBlock 
{
    void *data;
    bool isAlloc;
    size_t size;
    struct MemoryPoolBlock *next;
} MemoryPoolBlock;

/*
    Essentially, our memory pool manager will be a Linked List which tracks
    nodes of MemoryPoolBlocks. The linked list suits the functionality of
    a memory pool manager well, and allows us to easilly distribute memory
    amongst new nodes in a simple manner.
*/
typedef struct MemoryPoolManager 
{
    size_t poolSize;
    size_t memoryBlockSize;
    long int memoryBlockCount;
    MemoryPoolBlock *head;
} MemoryPoolManager;

/*
    Enums to clearly identify the various status states of our memory pool's
    operations. Remember, using magic strings and values such as string 
    literals such as "memory_error" is bad practice and has little meaning
    in a program!

    Instead, enums provide discrete values that are easier to understand, 
    less prone to mutation, typos and a much stricter enforcement of constant
    values.
*/
typedef enum 
{
    MEMORY_POOL_INIT_ERROR,
    MEMORY_POOL_DESTROY_ERROR,
    MEMORY_POOL_ALLOC_ERROR,
    MEMORY_POOL_OK
} MemoryPoolStatus;

/*
    Function prototypes to define the behaviour of out memory pool manager and 
    how to handle the blocks of memory managed by it.
*/
MemoryPoolStatus MemPoolInit(MemoryPoolManager **pool, size_t memBlockSize, 
                             long int memBlockCount);

MemoryPoolStatus MemPoolDestroy(MemoryPoolManager *pool);

MemoryPoolStatus MemPoolAlloc(MemoryPoolManager *pool, MemoryPoolBlock **block);

MemoryPoolStatus MemPoolFree(MemoryPoolManager *pool, MemoryPoolBlock *block);

void PrintMemBlocks(MemoryPoolManager *pool);

void PrintBlock(MemoryPoolBlock *block);

#endif