#include <stdio.h>
int main()
{
    // 31 - jan, march, may, july,Aug,oct,dec
    int month;
    printf("Enter month number: ");
    scanf("%d", &month);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 9 || month == 11)
        printf("31 Days!");
    else if (month == 2)
        printf("28 or 29 days depond on leap year!");
    else
        printf("30 days");
    return 0;
}