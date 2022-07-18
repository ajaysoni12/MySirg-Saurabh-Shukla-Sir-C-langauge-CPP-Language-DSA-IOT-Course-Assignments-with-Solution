/*
         *
        * *        
       *   *       
      *     *      
     *       *
    *         *
   *           *
  *             *
 *               *
*                 *
*******************
*/

#include <stdio.h>
int main()
{
    int i, j, n;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &n);
    int k;
    for (i = 1; i <= n; i++)
    {
        for (int j = 1; j <=2*n-1; j++)
        {
            if (j == n+1-i || j == n-1+i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
        if(i==n)
          for(int k=1; k<=2*n-1; k++)
             printf("*"); 
    }
    return 0;
}