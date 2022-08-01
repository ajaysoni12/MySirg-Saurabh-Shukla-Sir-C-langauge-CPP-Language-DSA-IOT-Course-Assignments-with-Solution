#include <stdio.h>
#include <string.h>

void strLowercase(char str[])
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    strLowercase(str);
    printf("\nLowercase string: %s", str);

    return 0;
}