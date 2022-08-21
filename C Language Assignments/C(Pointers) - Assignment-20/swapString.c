#include <stdio.h>
#include <string.h>
void swapString(char *, char *);
int main()
{
    char *ptr = "Hello"; 
    char *str = "Welcome"; 
    swapString(ptr, str);
    printf("\nAfter Swapping, a = %sb = %s", ptr, str);
    return 0;
}
void swapString(char *ptr, char *str)
{
    char *temp = ptr; 
    ptr = str; 
    str = temp; 
}
