#include <stdio.h>
int main()
{
    char str[100], copyString[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);

    for (int i = 0; str[i]; i++)
        copyString[i] = str[i];

    printf("\nCopy string: %s", copyString);

    /*
    strcpy(copyArray,str);
    */
    return 0;
}   