#include<stdio.h> 
void fibo(int n)
{
    if(n==1)
       printf("0 "); 
    else if(n==2)
       printf("0 1"); 
    else 
    {
        int x=0,y=1; 
        printf("0 1 "); 
        for(int i=3; i<=n; i++)
        {
            int sum = x+y; 
            x = y; 
            y = sum; 
            printf("%d ",sum); 
        }
    }
}
int main()
{
    int term; 
    printf("How many terms you want to print: "); 
    scanf("%d",&term); 
    fibo(term); 
    return 0; 
}