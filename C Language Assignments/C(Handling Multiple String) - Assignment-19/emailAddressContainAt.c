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

    printf("\nnot @ contain Email\n\n");
    for (int i = 0; i < noOfString; i++)
    {
        int flag = 0;
        for (int j = 0; str[i][j]; j++)
        {
            if (str[i][j] == '@')
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%s", str[i]);
        ;
    }

    return 0;
}