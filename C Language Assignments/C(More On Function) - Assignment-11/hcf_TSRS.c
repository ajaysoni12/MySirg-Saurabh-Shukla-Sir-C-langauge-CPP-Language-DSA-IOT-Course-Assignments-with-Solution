#include<stdio.h>
int hcf(int n1,int n2)
{
    int i; 
    for(i=n1<n2?n1:n2; i>=1; i--)
      if(n1%i==0 && n2%i==0)
        break; 
return i; 
}
int main(){
    int n1,n2; 
    printf("Enter two number: "); 
    scanf("%d%d",&n1,&n2); 
    printf("LCM is: %d",hcf(n1,n2)); 
return 0;
}