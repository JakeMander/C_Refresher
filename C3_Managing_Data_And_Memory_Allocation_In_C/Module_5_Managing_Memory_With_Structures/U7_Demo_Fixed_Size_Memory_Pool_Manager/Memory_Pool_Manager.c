#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Memory_Pool_Manager.h"

MemoryPoolStatus MemPoolInit(MemoryPoolManager **pool, size_t memBlockSize,
                            long int memBlockCount)
{
    if (memBlockCount <= 0)
    {
        return MEMORY_POOL_INIT_ERROR;
    }

    /*  
        Allocate memory for the pool itself. 
        
        We need to use a ptr to a ptr 
        here so we don't end up with a dangling pointer! Remember, the local
        pool variable only has scope for this function! If we just use a 
        pointer, we assign the malloced pointer that refers to our new
        MemoryPoolManager to the LOCAL VARIABLE and not the original pointer
        in the calling code. This pointer then goes out of scope and we end
        up with a memory leak, thus we dereference a pointer which pointers
        to the address of a pointer in the calling code so we can directly
        assign the value of our new pointer to that variable. 
    */
   *pool = (MemoryPoolManager*) malloc(sizeof(MemoryPoolManager));

    //   Allocate memory for each block. This will be a single contiguous block
    //   for each block. Each MemoryPoolBlock is a structure that represents
    //   a block of data that is comparable to calling "malloc"
    MemoryPoolBlock *blocks = (MemoryPoolBlock*) malloc(sizeof(MemoryPoolBlock) * 
                                                        memBlockCount);
    
    // Allocate the chunk of memory to be managed by the pool.
    size_t poolSize = memBlockSize * memBlockCount;

    //  Void ptr: Just store the address of where our pool of memory starts.
    void *start = (void*) malloc(poolSize);

    //  Catch any instances where there is not enough memory to allocate the
    //  Pool Manager, the Memory Pool Blocks or the memory we'll use to
    //  store data in the blocks.
    if (pool == NULL || blocks == NULL || start == NULL)
    {
        printf("Unable To Allocate Memory For The Pool\n");
        return MEMORY_POOL_INIT_ERROR;
    }

    /*  
        Update the pool metadata including how many memory blocks we are 
        creating, how big each block is, the total amount of memory used
        in the memory pool (i.e. cumulative total of all the blocks) and 
        a pointer to the start of the memory used to hold the data for
        all of our blocks so we can update the blocks with new data
        when required. 
    */
    (*pool) -> memoryBlockCount = memBlockCount;
    (*pool) -> memoryBlockSize = memBlockSize;
    (*pool) -> poolSize = poolSize;
    (*pool) -> head = blocks;

    /*
        We need to point each MemoryBlock to the starting address of each
        chunk of memory it is managing in the single block of allocated
        memory we set up in "start".

        To begin with, start at the begining of the block, set a pointer to
        the starting memory address of the block of memory that the current
        Memory Block will store it's data to, and then increment the pointer
        by the designatated amount of memory each block is to hold so we 
        can move to the starting address of the next memory block's data.

        We also need to move to the next MemoryPoolBlock in memory so we can
        update it's struct members with the provided data as well as link
        it to it's starting address in memory. 

        Finally, we update our memory block linked list node with all the 
        member data it needs including pointing it to the next memmory 
        block in the list as well as the size of each block and a flag
        to check if the memory block has been allocated. 
    */
    void *current = start;
    void *next = NULL;

    MemoryPoolBlock *currentBlock = blocks;
    MemoryPoolBlock *nextBlock = NULL;

    for (int i = 0; i < memBlockCount; i++)
    {
        currentBlock -> data = current;

        /*  
            If i is equal to the last memory block (if we zero out our block
            count), we are at the end of our blocks. Therefore set the next
            block to NULL so we know when to stop looking for more blocks in
            our linked list.
        */
        if (i == memBlockCount - 1)
        {
            next = nextBlock;
        }

        else
        {
            // Void ptr arithmetic illegal in standard C! Cast to int to
            // increment!
            next = (int*)current + memBlockSize;
            nextBlock = currentBlock + sizeof(MemoryPoolBlock);
        }

        currentBlock -> next = nextBlock;
        currentBlock -> size = memBlockSize; 
        currentBlock -> isAlloc = false;

        //  Increment to next data storage starting address for the next memory
        //  block.
        current = next;

        //  Point us to the next block ready to set up the next metadata to track
        //  another memory block to be managed by the memory pool.
        currentBlock = nextBlock;
    }

    return MEMORY_POOL_OK;
}

/*
    Perform clean up on our Memory Pool Manaager and ensure all components
    are cleaned up correctly in order to prevent a memory leak.

    This method must be called in order to properly deallocate all memory
    associated with the memory pool manager.

    As the memory pool manager is made up of three components that have
    all been dynamically allocated, all three need to be freed to avoid
    a memory leak.

    These three components are:

        - The block of memory responsible for storing each blocks data as a
          single contiguous block of memory.

        - The block of memory responsible for storing each MemoryBlock struct
          and it's associated meta-data.

        - The Memory pool itself, a struct used for tracking the head of the
          MemoryBlocks linked list as well as how many/how big each Memory
          Block should be in the pool.
*/
MemoryPoolStatus MemPoolDestroy(MemoryPoolManager *pool)
{
    if (pool != NULL && pool->head != NULL)
    {
        free(pool -> head->data);
        free(pool->head);
        free(pool);
    }
    return MEMORY_POOL_OK;
}

/*
    Iterate over each Memory Block tracked by the Memory Pool until we hit the
    first available block that is unallocated. Set this block to allocated and
    then set the block pointer to the newly allocated block in the memory pool.

    Note how no calls to malloc take place here! Memory allocation is done via
    boolean flags! So there are no system calls made! This is the power of a
    memory pool!
*/
MemoryPoolStatus MemPoolAlloc(MemoryPoolManager *pool, MemoryPoolBlock **block)
{
    if (pool == NULL || block == NULL)
    {
        printf("Memory Pool Alloc Error\n");
        return MEMORY_POOL_ALLOC_ERROR;
    }

    if (pool -> head != NULL)
    {
        //  Point us to the start of the memory pools tracked list of Memory 
        // Block's. 
        MemoryPoolBlock *current = pool -> head;

        //  If we reach a NULL Ptr, we've hit the last node. Whilst we're not 
        //  at the end, continue to iterate over the memory blocks.
        while (current)
        {
            if (current-> isAlloc == false)
            {
                //  Set the pointer to the memory block that was passed in to 
                //  point to the memory block that has just been allocated.
                *block = current;
                current -> isAlloc = true;
                return MEMORY_POOL_OK;
            }

            else
            {
                current = current -> next;
            }
        }
    }
}


/*
    This function traverses the MemoryPool's MemoryPoolBlock linked list
    until it hits the address of the block that was passed in as the
    second parameter.

    When hit, the block has it's allocation set to false and, for security,
    has it's previous stored data zeroed ready for reallocation.
*/
MemoryPoolStatus MemPoolFree(MemoryPoolManager *pool, MemoryPoolBlock *block)
{
    MemoryPoolBlock *current = pool -> head;

    while (current)
    {
        if (current == block)
        {
            current -> isAlloc = false;
            memset(current -> data, 0, pool -> memoryBlockSize);
            return MEMORY_POOL_OK;
        }

        else
        {
            current = current -> next;
        }
    }
    return MEMORY_POOL_DESTROY_ERROR;
}

void PrintMemBlocks(MemoryPoolManager *pool)
{
    if (pool == NULL)
    {
        return;
    }

    MemoryPoolBlock *current = pool -> head;

    while (current != NULL)
    {
        PrintBlock(current);
        current = current -> next;
    }

    printf("\n");
}

/*
    Prints a block including it's total size in addition to wether it has
    been allocated or not in memory (1 is allocated, 0 is unallocated).
*/
void PrintBlock(MemoryPoolBlock *block)
{
    MemoryPoolBlock *nextBlock = block -> next -> data;
    printf("[%td | %d] => ", block -> next && block -> next -> data ? 
    &(block -> next -> data) - &(block -> data) : block -> size, block -> isAlloc); 
}