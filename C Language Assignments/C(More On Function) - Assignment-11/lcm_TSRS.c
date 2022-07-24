#include<stdio.h>
int lcm(int n1,int n2)
{
    int i; 
    for(i=n1>n2?n1:n2; i<=n1*n2; i++)
      if(i%n1==0 && i%n2==0)
        break; 
return i; 
}
int main(){
    int n1,n2; 
    printf("Enter two number: "); 
    scanf("%d%d",&n1,&n2); 
    printf("LCM is: %d",lcm(n1,n2)); 
return 0;
}