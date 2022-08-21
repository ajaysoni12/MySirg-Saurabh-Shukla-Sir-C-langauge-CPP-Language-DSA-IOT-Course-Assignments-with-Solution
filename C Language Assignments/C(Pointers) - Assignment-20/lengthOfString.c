#include <stdio.h>
int length(char *ptr)
{
    int i;
    for (i = 0; *(ptr + i); i++)
        ;
    return i-1; // becuase fgets function contain \n extra
}
int main()
{
    char str[20];
    printf("Enter string: ");
    fgets(str, 20, stdin);
    int l = length(str);
    printf("length of string: %d", l);
    return 0;
}