#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);

    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

    printf("Convert string in lowercase: %s", str);
    /*
    using Build-in Method
    printf("Convert string in uppercase: %s",strlwr(str));
    */
    return 0;
}