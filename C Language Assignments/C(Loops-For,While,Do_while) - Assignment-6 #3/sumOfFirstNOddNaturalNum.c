#include<stdio.h> 
int main()
{
    int n; 
    printf("How many odd number sum you want to print: "); 
    scanf("%d",&n); 
    int sum = 0; 
    for(int i=1; i<2*n; i+=2)
       sum+=i; 
    printf("%d odd number sum is: %d",n,sum); 
    return 0; 
}