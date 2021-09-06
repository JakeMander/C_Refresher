#include <stdlib.h>
#include <stdio.h>
#include "Memory_Pool_Manager.h"
/*
    WiredBrain coffee needs our help one last time!

    Their coffee machine code is currently expiriencing poor performance due to
    excessive calls to malloc and they need our help reimplmenting the
    existing code to be more performant!

    In the final demo, we will:

    -   Diagnose calls to malloc causing slow performance.
    -   Introduce a fixed-size memory pool manager.
    -   Replace calls to malloc with calls to our custom memory pool management
        functions.

    Here we're going to explore a new concept. That is the use of header files 
    to declare our function prototypes in, thus seperating out the decleration
    and implementation of our functions. 

    This will be explored in greater depth in a later chapter. For now, you 
    just need to know that a convention for declaring functions and global
    variables is to stick them in a header file which is included in 
    a ".c" file which contains the implemntation of our code and functions.

*/

typedef struct TestMetrics
{
    int pourMode;
    int pourDuration;
    float flow;
    double heat;
} TestMetrics;

int main (int argc, char* argv[])
{
    MemoryPoolManager *myMemPool = NULL;
    MemPoolInit(&myMemPool, 2000000 * sizeof(TestMetrics), 5);

    printf("Blocks After Instantiation\n");
    // PrintMemBlocks(myMemPool);

    MemoryPoolBlock *block;
    MemoryPoolBlock *block2;

    MemPoolAlloc(myMemPool, &block);
    printf("Blocks After 2nd Alloc\n");
    PrintMemBlocks(myMemPool);

    MemPoolAlloc(myMemPool, &block2);
    printf("Blocks After 2nd Alloc\n");
    PrintMemBlocks(myMemPool);

    TestMetrics *blockOneData = block -> data;

    TestMetrics metricOne = { 200, 300, 2.3, 23.4345 };
    TestMetrics metricTwo = { 100, 268, 5, 72.578 };

    blockOneData[0] = metricOne;
    blockOneData[1] = metricTwo;

    printf("\nTest Data [Block1]:\n");
    printf("First Element PourMode: %d\n", blockOneData[0].pourMode);
    printf("Second Element PourMode: %d\n", blockOneData[1].pourMode);

    MemPoolFree(myMemPool, block);
    printf("Blocks After 1st Free\n");
    PrintMemBlocks(myMemPool);

    MemPoolDestroy(myMemPool);
    myMemPool = NULL;

    return 0;
}

int SendMetrics(TestMetrics *metrics)
{
    free(metrics);
    return 0;
}