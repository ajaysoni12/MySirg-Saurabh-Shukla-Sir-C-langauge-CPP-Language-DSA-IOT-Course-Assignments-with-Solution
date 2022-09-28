#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double find_angle(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double angle, m1, m2;

    /* The angle between two lines, of which, one of the line is ax + by + c = 0, and the other line is the x-axis, is θ = Tan-1(-a/b). */

    /* coefficients a and b are equal to zero in at least one equation, which does not make sense */
    if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0))
    {
        printf("\ncoefficients a and b are equal to zero in at least one equation, which does not make sense \n");
        return -1;
    }

    if (b1 == 0 && b2 == 0) // if both lines
    {
        angle = 0;
        return angle;
    }
    if (a1 == 0 && a2 == 0)
    {
        angle = 0;
        return angle;
    }

    // if (b1 == 0)
    // {
    //     angle = atan((-a2) / (b2));
    //     return angle;
    // }
    // if (b2 == 0)
    // {
    //     angle = atan((-a1) / (b1));
    //     return angle;
    // }

    /* find - slops of both linear eqation */
    m1 = (-a1) / (b1);
    m2 = (-a2) / (b2);

    /* The angle between two lines that are parallel to each other and having equal slopes (m1 == m2) is 0º. */
    if (m1 == m2)
    {
        angle = 0;
        return angle;
    }

    /* The angle between two lines which are perpendicular to each other and having the product of their slopes equal to -1 , (m1 * m2 = -1) is 90º. */
    if (m1 * m2 == -1)
    {
        angle = 90;
        return angle;
    }

    /* The angle between two lines having equations l1=a1x+b1y+c1=0, and l2=a2x+b2y+c2=0 is θ =Tan−1(a2b1−a1b2)/(a1a2+b1b2))*/
    angle = atan((a2 * b1 - a1 * b2) / (a1 * a2 + b1 * b2));
    return fabs(angle * 57.2957795); // return acute or obtuse (180 - acute)
}

int main()
{
    double angle_at_chowk;
    angle_at_chowk = find_angle(1, 2, 3, 4, 5, 6);
    printf("Angle at which these roads meet at 123 Chowk: %.2lf in Degree\n", angle_at_chowk);
}