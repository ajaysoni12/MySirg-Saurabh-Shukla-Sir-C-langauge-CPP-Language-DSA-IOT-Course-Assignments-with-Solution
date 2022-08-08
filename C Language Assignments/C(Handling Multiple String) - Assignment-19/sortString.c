#include <stdio.h>
void strSort(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        for (int j = i + 1; str[j]; j++)
        {
            if (str[i] > str[j])
            {
                char ch = str[i];
                str[i] = str[j];
                str[j] = ch;
            }
        }
    }
}
int main()
{
    char str[10][100];
    for (int i = 0; i < 10; i++)
        fgets(str[i], 100, stdin);

    printf("Sorted string: \n");
    for (int i = 0; i < 10; i++)
    {
        strSort(str[i]);
        printf("%s", str[i]);
    }

    return 0;
}