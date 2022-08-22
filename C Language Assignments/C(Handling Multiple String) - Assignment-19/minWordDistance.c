#include <stdio.h>
#include <string.h>
int main()
{
    char words[5][20] = {"My", "Name", "Is", "Ajay", "Soni"};
    char word1[] = "My";
    char word2[] = "Ajay";
    int i, indWord1 = -1, indWord2 = -1, min = 100000;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(words[i], word1) == 0)
            indWord1 = i;
        if (strcmp(words[i], word2) == 0)
            indWord2 = i;
        if (indWord1 != -1 && indWord2 != -1)
            min = abs(indWord1 - indWord2);
    }
    printf("Minimum distance of two words is: %d", min-1);
    return 0;
}