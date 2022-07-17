// 153 = 1 + 125 + 27
#include <stdio.h>
int main()
{
    for (int j = 1; j <= 1000; j++)
    {
        int sum;
        for (int j = 1; j <= 1000; j++)
        {
            sum = 0;
            for (int i = j; i != 0; i /= 10)
            {
                int rem = i % 10;
                sum += rem * rem * rem;
            }
            if (sum == j)
                printf("%d ", j);
        }
    }
    return 0;
}