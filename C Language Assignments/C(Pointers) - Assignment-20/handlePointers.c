#include <stdio.h>
int main()
{
    int var;
    int *ptr;

    printf("\nWithout Assignemnt values of ptr");
    printf("\nAddress of ptr - %d", &ptr); // address of ptr 
    // printf("\nContent of ptr - %d", *ptr); // program terminate because ptr not contain any variable address 

    ptr = &var;
    printf("\n Assign variable in ptr pointer, variable contain garbage value");
    printf("\nAddress of ptr - %d", &ptr); //address of ptr 
    printf("\nContent of ptr - %d", *ptr); // randome value 

    var = 10;
    printf("\n Assignet variable in ptr pointer, variable contain 10 value");
    printf("\nAddress of ptr - %d", &ptr); // address of ptr 
    printf("\nContent of ptr - %d", *ptr); // randome value  

    *ptr = 20;
    printf("\n Assignet 20 in ptr pointer");
    printf("\nAddress of ptr - %d", &ptr); // address of ptr 
    printf("\nContent of ptr - %d", *ptr); // 20 

    return 0;
}