#include <stdio.h>
int strLength(char str[])
{
    int i;
    for (i = 0; str[i]; i++); 
    return i;
}
int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    printf("Length of given string is: %d", strLength(str));
    return 0;
}