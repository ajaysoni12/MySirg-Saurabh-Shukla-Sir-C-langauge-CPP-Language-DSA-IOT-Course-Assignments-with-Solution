#include <stdio.h>
int main()
{
    char str[] = "Ajay Soni";
    int i; 
    // Count Length of String
    for(i=0; str[i]; i++); 
    printf("\nLength of String: %d",i); 

    // We Use Built-in method - strlen(); 
    return 0;
}