#include <stdio.h>
#include <string.h> 
void reverseStringPrint(char *ptr)
{
    int length = strlen(ptr)-1; 
    for(int i = length; i>=0; i--)
        printf("%c", *(ptr+i)); 
}
int main()
{
    char arr[20];
    printf("Enter string: "); 
    fgets(arr, 20, stdin); 
    reverseStringPrint(arr);
    return 0;
}