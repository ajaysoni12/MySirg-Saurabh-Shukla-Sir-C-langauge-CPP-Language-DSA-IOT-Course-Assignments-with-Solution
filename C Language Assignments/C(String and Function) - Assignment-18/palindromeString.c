#include <stdio.h>
#include <string.h>

int strPalindrome(char str[])
{
    for (int i = 0; i < strlen(str) / 2; i++)
        if (str[i] != str[strlen(str) - 2 - i])
            return 0;

    return 1;
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    if (strPalindrome(str))
        printf("\nString is Palindrome!");
    else
        printf("\nString is Not Palindrome!");

    return 0;
}