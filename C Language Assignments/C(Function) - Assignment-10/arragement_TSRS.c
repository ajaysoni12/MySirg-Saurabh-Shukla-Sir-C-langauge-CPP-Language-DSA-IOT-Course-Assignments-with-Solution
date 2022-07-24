#include <stdio.h>
int fact(int n)
{
    int fact=1; 
    for(int i=1; i<=n; i++)
      fact*=i; 
    return fact; 
}
int arrange(int n,int r)
{
    return fact(n)/fact(n-r); 
}
int main()
{
    int x,y;
    printf("Enter the two number: ");
    scanf("%d%d", &x,&y);
    printf("%d arrangement!",arrange(x,y));
    return 0;
}