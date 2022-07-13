#include <stdio.h>
int main()
{
    int cp, sp;
    printf("Enter a cost price and selling price of product: ");
    scanf("%d%d", &cp, &sp);
    int amountAfterSelling = sp - cp;
    if (amountAfterSelling == 0)
        printf("No Profit or No Loss, Profit or loss % wil be 0%");
    else if (amountAfterSelling > 0)
        printf("Profit, Profit percentage is: %f", (amountAfterSelling * 100.0) / cp);
    else
        printf("Loss, loss percentage is: %f", (abs(amountAfterSelling) * 100.0) / cp);
    return 0;
}
