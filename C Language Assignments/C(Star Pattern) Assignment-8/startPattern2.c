/* 
        *
      * *
    * * *
  * * * *
* * * * *
*/

#include<stdio.h>
int main()
{
    int lines; 
    printf("Enter how many lines you want to print: "); 
    scanf("%d",&lines); 
    int i,j; 
    for(i=1; i<=lines; i++)
    {
        for(int j=1; j<=lines; j++)
        {
            if(j>=(lines+1)-i)
              printf("*"); 
            else 
              printf(" "); 
        }
        printf("\n"); 
    }
    return 0; 
}