#include <stdio.h>
void print(int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", i);
}
int main()
{
    int n; 
    printf("Enter the number: "); 
    scanf("%d",&n); 
    print(n); 
    return 0;
}