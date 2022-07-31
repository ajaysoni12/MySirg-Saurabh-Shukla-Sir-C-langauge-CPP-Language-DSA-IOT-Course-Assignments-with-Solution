#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);

    int alphabets = 0, digit = 0, specialCharacter = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit++;
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            alphabets++;
        else
            specialCharacter++;
    }

    printf("\nTotal no. of Digit is %d\nTotal no. of Alphabets is: %d\nTotal no. of Special Character(consider null character) is: %d", digit, alphabets, specialCharacter);

    return 0;
}