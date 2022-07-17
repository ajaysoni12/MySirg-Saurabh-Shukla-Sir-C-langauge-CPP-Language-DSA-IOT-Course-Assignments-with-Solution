#include <stdio.h>
int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    int count = 0;
    for (int i = num; i != 0; i /= 10)
        count++;
    printf("%d Number, Total Digit is: %d", num, count);
    return 0;
}