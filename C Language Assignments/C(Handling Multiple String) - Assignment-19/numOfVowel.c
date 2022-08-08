#include <stdio.h>
int main()
{
    char str[5][100];
    for (int i = 0; i < 5; i++)
        fgets(str[i], 100, stdin);

    int count;
    for (int i = 0; i < 5; i++)
    {
        count = 0;
        for (int j = 0; str[i][j]; j++)
        {
            if (str[i][j] == 'a' || str[i][j] == 'e' || str[i][j] == 'i' || str[i][j] == 'o' || str[i][j] == 'u' || str[i][j] == 'A' || str[i][j] == 'E' || str[i][j] == 'I' || str[i][j] == 'O' || str[i][j] == 'U')
                count++;
        }
        printf("\n%d String contan %d Vowel", i + 1, count);
    }

    return 0;
}