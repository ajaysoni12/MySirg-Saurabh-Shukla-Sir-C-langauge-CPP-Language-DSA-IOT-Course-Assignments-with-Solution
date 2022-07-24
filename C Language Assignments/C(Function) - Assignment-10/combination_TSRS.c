#include <stdio.h>
int fact(int n)
{
    int fact=1; 
    for(int i=1; i<=n; i++)
      fact*=i; 
    return fact; 
}
int combi(int n,int r)
{
    return fact(n)/(fact(n-r)*fact(r)); 
}
int main()
{
    int x,y;
    printf("Enter the two number: ");
    scanf("%d%d", &x,&y);
    printf("%d combination!",combi(x,y));
    return 0;
}