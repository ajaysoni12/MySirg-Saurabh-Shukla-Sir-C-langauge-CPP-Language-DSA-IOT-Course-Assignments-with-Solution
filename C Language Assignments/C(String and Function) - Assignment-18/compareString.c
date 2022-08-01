#include <stdio.h>
#include <string.h>

int strCompare(char str1[], char str2[])
{
    for (int i = 0; str1[i] || str2[i]; i++)
    {
        if (str1[i] != str2[i])
            return 0;
    }
    if (strlen(str1) == strlen(str2))
        return 1;
    return 0;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, 100, stdin);

    printf("Enter second string: ");
    fgets(str2, 100, stdin);

    if (strCompare(str1, str2))
        printf("\nString is equal");
    else
        printf("\nString is not equal");

    return 0;
}