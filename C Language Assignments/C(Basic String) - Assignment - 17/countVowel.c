#include <stdio.h>
int main()
{
    char str[100];
    int countVowel = 0;
    printf("Enter String: ");
    fgets(str, 100, stdin);

    for (int i = 0; str[i]; i++)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            countVowel++;

    printf("\nGiven string total vowel is: %d", countVowel);
    return 0;
}