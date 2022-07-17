#include<stdio.h> 
int main()
{
    int n; 
    printf("How many even number sum you want to print: "); 
    scanf("%d",&n); 
    int sum = 0; 
    for(int i=2; i<=2*n; i+=2)
       sum+=i; 
    printf("%d even number sum is: %d",n,sum); 
    return 0; 
}