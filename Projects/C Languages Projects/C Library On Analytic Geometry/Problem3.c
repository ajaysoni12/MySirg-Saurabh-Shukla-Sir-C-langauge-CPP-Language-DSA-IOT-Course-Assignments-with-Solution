#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* This function calculate area shaped having three vertices */
double find_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    /* Area of Triangle(three vertice shaped) */

    /* Formula
    0.5 * (x1(y2-y3) + x2(y3-y1)+ x3(y1-y2)) */

    /* This function handle all the situatio like all coordinate are pesent in same lines etc   */

    double area = 0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return fabs(area); // area unit always postive 
}

int main()
{
    printf("Area: %.2lf", find_area(0, 0, 3, 4, 3, 3));
    return 0;
}