#include <stdio.h>
#include <string.h>

void strSort(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        for (int j = 0; str[j]; j++)
        {
            if (str[i] < str[j])
            {
                int temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void reapetedChar(char str[])
{
    strSort(str);
    int i = 0, j, flag;
    while (i<strlen(str))
    {
        flag = 1;
        for (j = i + 1; str[j]; j++)
        {
            if (str[i] == str[j])
                flag = 0;
            else
                break;
        }
        if (flag == 0)
            printf("%c ", str[i]);
        i = j;
    }
}

int main()
{
    char str[100];

    printf("Enter first string: ");
    fgets(str, 100, stdin);

    printf("\nAvailable reapted character in given string- "); 
    reapetedChar(str);
    return 0;
}