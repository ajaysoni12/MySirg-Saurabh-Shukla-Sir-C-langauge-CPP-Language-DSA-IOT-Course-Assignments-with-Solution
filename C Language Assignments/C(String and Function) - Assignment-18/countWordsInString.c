#include <stdio.h>
#include <string.h>

int strCountWord(char str[])
{
    int countSpace = 1;
    for (int i = 0; str[i]; i++)
        if (str[i] == ' ')
            countSpace++;
    return countSpace;
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    printf("\nTotal words in given string: %d", strCountWord(str));
    return 0;
}