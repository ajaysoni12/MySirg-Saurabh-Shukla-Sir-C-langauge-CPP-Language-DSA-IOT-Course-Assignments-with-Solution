#include <stdio.h>
int main()
{
    char ch; 
    printf("Ente a character: "); 
    scanf("%c",&ch); 
    if(ch>='A' && ch<='Z')
      printf("%c - Alfhabets(UpperCase)",ch); 
    else if(ch>='a' && ch<='z')
      printf("%c - Alfhabet(LowerCase)",ch); 
    else if(ch>='0' && ch<='9')
      printf("%c - Digit",ch); 
    else 
      printf("%c - Special Character",ch); 
    return 0;
}
