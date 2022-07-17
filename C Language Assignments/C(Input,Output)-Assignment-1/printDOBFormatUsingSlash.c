#include <stdio.h>
int main()
{
    int dd, mm, yyyy;
    printf("Enter date,month,year: ");
    scanf("%d",&dd); 
    printf("%d/",dd); 
    scanf("%d",&mm); 
    printf("%d/%d/",dd,mm); 
    scanf("%d",&yyyy); 
    printf("%d/%d/%d",dd,mm,yyyy); 
    
    printf("\nmDay - %d,Month - %d, Year - %d", dd, mm, yyyy);
    return 0;
}
