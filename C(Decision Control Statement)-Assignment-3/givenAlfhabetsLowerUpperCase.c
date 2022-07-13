#include <stdio.h>
int main()
{
    char ch;
    printf("Enter any alfhabet: ");
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z')
        printf("UpperCase!");
    else
        printf("LowerCase!");
    return 0;
}