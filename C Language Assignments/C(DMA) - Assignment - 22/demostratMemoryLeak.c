#include <stdio.h>
#include <stdlib.h>
void memoryLeak()
{
    int *ptr = (int *)malloc(sizeof(int)); // ptr contain address of 4 bytes memory
    // here we performs operator in ptr
    // but we don't realise ptr contain memory so it's called memory leak because after functione end ptr will be destroy so dma memory is avaiable but we don't access becuase we don't havae address of dma memory
    // here we use free(address) function or we return address
}
int main()
{

    memoryLeak();
    return 0;
}