#include <stdio.h>
int main()
{
    char str[100];
    printf("Enter String: ");
    fgets(str, 100, stdin);

    // sort
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
    // Count Freq
    int count, i = 0, j;
    while (str[i])
    {
        count = 0;
        for (j = i; str[j]; j++)
        {
            if (str[i] == str[j])
                count++;
            else
                break;
        }
        printf("\n%c Character Frequency is: %d", str[i], count);
        i = j;
    }

    return 0;
}