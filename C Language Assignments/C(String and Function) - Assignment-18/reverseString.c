#include <stdio.h>
#include <string.h>
void strRev(char str[])
{
    int strLength = strlen(str);
    for (int i = 0; i < strLength / 2; i++)
    {
        int temp = str[i];
        str[i] = str[strLength - 2 - i];
        str[strLength - 2 - i] = temp;
    }

}
int main()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, 100, stdin);
    strRev(str);
    printf("Reverse string: %s",str); 
    return 0;
}