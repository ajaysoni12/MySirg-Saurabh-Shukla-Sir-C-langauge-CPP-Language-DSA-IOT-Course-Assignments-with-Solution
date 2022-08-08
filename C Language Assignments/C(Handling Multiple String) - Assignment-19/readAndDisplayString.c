#include <stdio.h>

int main()
{
    int noOfString;
    printf("How many string u want to enter: ");
    scanf("%d", &noOfString);
    printf("Enter %d String: ", noOfString);
    fflush(stdin); // for clear buffer
    char str[noOfString][100];
    for (int i = 0; i < noOfString; i++)
        fgets(str[i], 100, stdin);

    printf("Strings: \n");
    for (int i = 0; i < noOfString; i++)
    {
        printf("%d String - %s", i + 1, str[i]);
    }

    return 0;
}