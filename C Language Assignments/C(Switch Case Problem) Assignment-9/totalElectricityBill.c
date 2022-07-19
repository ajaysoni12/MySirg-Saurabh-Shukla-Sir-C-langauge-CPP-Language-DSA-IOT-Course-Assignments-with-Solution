#include <stdio.h>
int main()
{
    int unit;
    printf("Enter the total eletricity consume -");
    scanf("%d", &unit);
    float totalBill, sucharge;
    switch (unit)
    {
    case 1 ... 50:
        totalBill = unit * 0.50;
        break;
    case 51 ... 150:
        totalBill = 25 + ((unit - 50) * 0.75);
        break;
    case 151 ... 250:
        totalBill = 100 + ((unit - 150) * 1.20);
        break;
    default:
        totalBill = 220 + ((unit - 250) * 1.50);
    }
    sucharge = totalBill * 0.20;
    printf("Total bill is: %.2f", totalBill + sucharge);
    return 0;
}