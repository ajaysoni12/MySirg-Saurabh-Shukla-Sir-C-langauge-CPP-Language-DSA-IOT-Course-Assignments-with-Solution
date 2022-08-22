#include <stdio.h>
#include <stdlib.h>
char *inputTEXT()
{
    int txtLength;
    printf("input length of text: ");
    scanf("%d", &txtLength);
    fflush(stdin);
    char *ptr = (char *)malloc(sizeof(char) * txtLength);
    printf("Input Text: ");
    fgets(ptr, txtLength * sizeof(char), stdin);
    return ptr;
}
void outputText(char *ptr)
{
    printf("Output Text: %s", ptr);
}
int main()
{
    char *ptr;
    ptr = inputTEXT();
    outputText(ptr);
    return 0;
}