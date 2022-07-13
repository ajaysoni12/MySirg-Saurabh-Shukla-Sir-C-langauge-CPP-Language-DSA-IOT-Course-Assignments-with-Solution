#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num&1==1) 
      printf("Odd number"); 
    else 
      printf("Even number"); 
    return 0;
}
