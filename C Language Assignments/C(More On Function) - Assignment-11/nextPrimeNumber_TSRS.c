#include <stdio.h>
#include <math.h>
int nextPrime(int num)
{
    int i = num + 1, j;
    while (1)
    {
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
                break;
        }
        if (j-1 == i/2)
            break;
       i++; 
    }
    return i;
}
int main()
{
    int num;
    printf("Enter a number: "); 
    scanf("%d", &num);
    printf("Next Prime Number is: %d", nextPrime(num));
    return 0;
}