#include <stdio.h>
#include <string.h>

void factorial()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int fact = 1;
    for (int i = 1; i <= num; i++)
        fact *= i;
    printf("Factorial is: %d", fact);
}

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

    char user[100];
    printf("\nEnter Username- ");
    fgets(user, 100, stdin);
    int flag = 0;
    for (int i = 0; i < noOfString; i++)
    {
        if (strcmp(str[i], user) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
        factorial();
    else
        printf("Error!");

    return 0;
}