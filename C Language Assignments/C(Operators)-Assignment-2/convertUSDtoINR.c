#include <stdio.h>
int main()
{
    float priceUSD = 76.23; 
    int inr; 
    printf("Enter a amount of INR: "); 
    scanf("%d",&inr); 
    float totalUsdAmount = inr*priceUSD; 
    printf("total amount in usd is: %f",totalUsdAmount); 
    return 0;
}