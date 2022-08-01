#include <stdio.h>
#include <string.h>

void strUppercase(char str[])
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    strUppercase(str);
    printf("\nUppercase string: %s", str);

    return 0;
}