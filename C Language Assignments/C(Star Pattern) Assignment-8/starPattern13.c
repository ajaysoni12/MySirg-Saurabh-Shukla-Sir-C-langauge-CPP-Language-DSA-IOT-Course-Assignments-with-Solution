/*
         1
        232        
       34543       
      4567654      
     567898765
*/

#include <stdio.h>
int main()
{
    int i, j, lines,k=0;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &lines);
    for (i = 1; i <= lines; i++)
    {
        for (j = 1; j <=lines*2-1; j++)
        {
           if(j>=lines+1-i && j<=lines-1+i){
               j<=lines?k++:k--;
               printf("%d",k);
           }
          else 
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}