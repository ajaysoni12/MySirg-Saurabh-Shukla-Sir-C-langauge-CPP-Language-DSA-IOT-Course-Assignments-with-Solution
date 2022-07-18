/*
 *******************
 ***************** 
  ***************  
   *************   
    ***********
     *********
      *******
       *****
        ***
         *
*/

#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &lines);
    for (i = 1; i <= lines; i++)
    {
        for (j = 1; j <=lines*2-1; j++)
        {
           if(j>=i && j<=(lines*2) - i)
               printf("*");
          else 
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}