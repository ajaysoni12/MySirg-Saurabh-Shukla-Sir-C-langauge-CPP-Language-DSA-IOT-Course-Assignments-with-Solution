/*
9876543210
876543210 
76543210  
6543210   
543210
43210
3210
210
10
0
*/

#include <stdio.h>
int main()
{
    int i, j, lines,k;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &lines);
    for (i = 1; i <= lines; i++)
    {
        k = lines-i; 
        for (j = 1; j <=lines; j++)
        {
           if(j<=(lines+1) - i)
            printf("%d",k--);
          else 
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}