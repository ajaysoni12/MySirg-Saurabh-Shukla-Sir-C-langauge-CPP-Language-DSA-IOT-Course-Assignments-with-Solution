#include <stdio.h>
#include <string.h>
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

    char search[100];
    printf("\nEnter Search string: ");
    fgets(search, 100, stdin);

    int flag = 0;
    for (int i = 0; i < noOfString; i++)
    {
        if (strcmp(str[i], search) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("Yes!, we got'it string");
    else
        printf("No!, we don't got'it");

    return 0;
}