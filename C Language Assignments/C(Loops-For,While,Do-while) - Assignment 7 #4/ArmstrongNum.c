// 153 = 1 + 125 + 27
#include <stdio.h>
int main()
{
    int num;
    printf("Enter numbre for checking armstrong numnber: ");
    scanf("%d", &num);
    int sum = 0;
    for (int i = num; i != 0; i /= 10)
    {
        int rem = i % 10;
        sum += rem * rem * rem;
    }
    if (sum == num)
        printf("Armstrong number");
    else
        printf("Not Armstrong number");
    return 0;
}