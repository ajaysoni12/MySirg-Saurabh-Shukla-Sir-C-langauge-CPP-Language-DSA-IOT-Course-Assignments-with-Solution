#include <stdio.h>
void print(int n)
{
    if (n > 0)
    {
        printf("%d",n%10); 
        print(n/10); 
    }
}
int main()
{
    int n; 
    printf("Enter the number: ");
    scanf("%d",&n);
    print(n);
    return 0;
}