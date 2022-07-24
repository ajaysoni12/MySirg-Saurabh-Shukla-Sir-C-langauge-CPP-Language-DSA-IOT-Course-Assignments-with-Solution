#include <stdio.h>
int checkEvenOdd(int n)
{
    if (n % 2 == 0)
        return 1;
    return 0;
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    if (checkEvenOdd(num))
        printf("Number is even");
    else
        printf("Number is odd");
    return 0;
}