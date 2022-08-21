#include <stdio.h>
int main()
{
    int vowel = 0, consonent = 0;
    char str[20];
    printf("Enter string: ");
    fgets(str, 20, stdin);
    char *ptr = str;
    for (int i = 0; *(ptr + i); i++)
    {
        if (*(ptr + i) == 'a' || *(ptr + i) == 'e' || *(ptr + i) == 'i' || *(ptr + i) == 'o' || *(ptr + i) == 'u' || *(ptr + i) == 'A' || *(ptr + i) == 'E' || *(ptr + i) == 'I' || *(ptr + i) == 'O' || *(ptr + i) == 'U')
            vowel += 1;
        else
            consonent += 1;
    }
    printf("\nGiven string, total vowel - %d, total consonent - %d", vowel, consonent - 2); // becuase space and \n neglegct
    return 0;
}