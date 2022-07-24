#include<stdio.h>
float findArea(int r)
{
    return 3.14*r*r; 
}
int main()
{
    int radius; 
    printf("Enter the radius of circle: "); 
    scanf("%d",&radius);
    printf("Area of circle is: %.2f",findArea(radius)); 
    return 0; 
}