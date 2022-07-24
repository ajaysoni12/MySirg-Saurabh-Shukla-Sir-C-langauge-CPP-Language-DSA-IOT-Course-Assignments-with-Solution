#include <stdio.h>
void print(int n)
{
    if (n > 0)
    {
        print(n/2); 
        printf("%d",n%2); 
    }
}
int main()
{
    int n; 
    printf("Enter the value: ");
    scanf("%d",&n);
    print(n);
    return 0;
}