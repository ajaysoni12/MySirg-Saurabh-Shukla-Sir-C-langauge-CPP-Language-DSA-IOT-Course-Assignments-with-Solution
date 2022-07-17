#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int rem = num % 10;
    if (rem == 0)
    {
        printf("one position towards the right ans: "); 
        rem = rem * 100 + num / 10;
        printf("one position towards the right ans: 0%d", rem);
    }
    else
    {
        rem = rem * 100 + num / 10;
        printf("one position towards the right ans: %d", rem);
    }
    return 0;
}
