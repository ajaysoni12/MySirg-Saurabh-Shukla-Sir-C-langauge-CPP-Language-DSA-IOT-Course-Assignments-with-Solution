#include <stdio.h>
#include <string.h>

int strAlphaNumeric(char str[])
{
    int digit = 0, alphabet = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9')
            digit = 1;
        else if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            alphabet = 1;

    if (digit && alphabet)
        return 1;
    else
        return 0;
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    if (strAlphaNumeric(str))
        printf("\nString is Alphanumeric!");
    else
        printf("\nString is Not Alphanumeric!");

    return 0;
}