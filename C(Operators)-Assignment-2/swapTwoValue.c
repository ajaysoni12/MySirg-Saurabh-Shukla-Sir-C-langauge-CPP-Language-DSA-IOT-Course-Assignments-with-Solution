#include <stdio.h>
int main()
{
    int num1,num2; 
    printf("Enter a two number: "); 
    scanf("%d%d",&num1,&num2); 
    printf("Before swap: a = %d,b = %d",num1,num2); 
    int temp = num1; 
    num1 = num2; 
    num2 = temp; 
    printf("\nAfter swap: a = %d,b = %d",num1,num2); 
    return 0;
}
