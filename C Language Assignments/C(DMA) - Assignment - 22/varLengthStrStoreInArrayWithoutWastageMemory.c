#include <stdio.h>
#include <stdlib.h>
char* inputVarLengthString()
{
    int varLength;
    printf("Enter variable length: ");
    scanf("%d", &varLength);
    char *ptr = (char *)calloc(varLength, sizeof(char));
    printf("Input %d length string: ", varLength);
    fflush(stdin);
    fgets(ptr, varLength * sizeof(char) + 1, stdin); // +1 because 1 character hold null character
    return ptr; 
}
int main()
{
    char *ptr; 
    ptr = inputVarLengthString();
    printf("You enter string - %s", ptr);
    return 0;
}