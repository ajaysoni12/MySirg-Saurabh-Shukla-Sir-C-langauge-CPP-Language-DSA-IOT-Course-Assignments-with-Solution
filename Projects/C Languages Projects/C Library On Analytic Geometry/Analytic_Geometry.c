#include "Analytic_Geometry.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define pi 3.14159265358979323846

/*
Commands for link library.c to main
Steps:-
    Run on terminal
    1) gcc -c -g library.c
    2) gcc -c -g main.c
    3) gcc -o main main.o library.o
    4) Run the main library (here we do not provide main function )

*/

/*
Analytic Geometry
    1. 2D Co-ordinate System
    2. Straight Line
    3. Circle
    4. Conic Sections
    5. Parabola
    6. Ellipse
    7. Hyperbola
    8. Planes in 3 Dimensions
*/
/* This function converts decimal degrees to radians */
double deg2rad(double deg)
{
    return (deg * pi / 180);
}

/* This function converts radians to decimal degrees */
double rad2deg(double rad)
{
    return (rad * 180 / pi);
}
/* This function calculate Angle between two linear equation */
double find_angle(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double angle, m1, m2;

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

/* This function find distance between two locations */
double find_distance(double lat1, double lon1, double lat2, double lon2, char unit)
{
    /* This Function calculates the distance between two points (given the latitude/longitude of those points) */

    /*  Definitions:
        South latitudes are negative, east longitudes are positive
        West latitudes are negative, north longitude are postive

        Passed to function:
        lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees)
        lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)
        unit = the unit you desire for results
            where: 'M' is statute miles (By default)
                   'K' is kilometers
                   'N' is nautical miles
    */

    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2))
    {
        return 0; // Because distance is 0
    }
    else
    {
        /* Apply Harvesine Formula */
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        switch (unit)
        {
        case 'M':
            break; // byDefault it is statute iles
        case 'K':
            dist = dist * 1.609344;
            break;
        case 'N':
            dist = dist * 0.8684;
            break;
        }
        return dist;
    }
}

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

/*
   <-- Distance b/w two points (x1, y1) & (x2, y2) -->
   Formula - distance = sqrt((x2-x1)^2 + (y2-y1)^2))
*/
double distanceBWTwoPoints(double x1, double y1, double x2, double y2)
{
    double temp = pow((x2 - x1), 2) + pow((y2 - y1), 2);
    return sqrt(temp);
}

/*
    <--  Point of Division of a line joining (x1,y1) & (x2,y2) in the ratio m:n -->
    Formula - (x3,y3) = (((m * x2 + n * x1) / (m + n)),((m * y2 + n * y1) / (m + n)))
*/
void pointOfDivisionOFALineJoining(double x1, double y1, double x2, double y2, double m, double n)
{
    double x3, y3;
    x3 = ((m * x2 + n * x1) / (m + n));
    y3 = ((m * y2 + n * y1) / (m + n));
    printf("Point of Division of a line Joining is: %.2lf & %.2lf", x3, y3);
}

/*
    <-- MidPoint of the Line Joining (x1, y1) & (x2, y2) -->
    Formula - (x3,y3) = (((x1 + x2) / 2), ((y1+y2)/2))
*/
void midPointOFTheLineJoining(double x1, double y1, double x2, double y2)
{
    double x3, y3;
    x3 = (x1 + x2) / 2;
    y3 = (y1 + y2) / 2;
    printf("Mid Points of the line joining is: %.2lf & %.2lf", x3, y3);
}

/*
    <-- Area of triangle formed by the three vertices (x1, y1), (x2, y2) & (x3, y3) -->
    Formula - Area = 0.5 * fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1-y2)))
*/
double areaOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    /* Note:-
    1. Area can never be negative Hence Always use MOD value
    2. If Area=0, this means all the three points are collinear
    */
    double Area;
    Area = 0.5 * fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
    return Area;
}

/*
    <-- Distance between two points in Polar-Coordinate (r1,01) & (r2, 02) -->
    Formula - Distance = sqrt(r1^2 + r2^2 - 2*r1*r2*cos(02-01))
*/
double distanceBWTwoPointsInPolarCoordinate(double r1, double theeta1, double r2, double theeta2)
{
    double distance;
    distance = (r1 * r1) + (r2 * r2) - (2 * r1 * r2 * cos(theeta1 - theeta2));
    return sqrt(distance);
}

/*
    <-- Equations of Transformation
        1. Cartesian to Polar         2. Polar to Cartesian
        r = sqrt(x*x + y*y)           x = r * cos(0)
        0 = atan(y/x)                 y = r * sin(0)
*/
void cartesianToPolar(double x, double y)
{
    double r = sqrt(x * x + y * y);
    double theeta = atan(y / x);
    theeta = (theeta * 180) / 3.141592653589793238462643;
    printf("r = %.2lf & theeta = %.2lf", r, theeta);
}
void polarToCartesian(double r, double theeta)
{
    double x, y;
    x = r * cos((theeta * 3.141592653589793238462643) / 180);
    y = r * sin((theeta * 3.141592653589793238462643) / 180);
    printf("x = %.2lf & y = %.2lf", x, y);
}

/*
    <-- find circle diameter if having radius -->
    Formula - diameter = 2 * r
    <-- find cirlce radius if having diameter -->
    Formula - radius = d / 2
    <-- find circle area if having radius-->
    Formula - area = 3.14 * r * r

*/
double findCirlceDiameter(double r)
{
    return 2 * r;
}
double findCircleRadius(double d)
{
    return d / 2;
}
double findCirlceArea(double r)
{
    return 3.141592653589793238462643 * r * r;
}
/*
    General Equation of conic: ax^2 + bxy; cy^2 + dx + ey + f = 0
    if b^2-4ac < 0 --- Ellipse
    if b^2-4ac = 0 --- Parabola
    if b^2-4ac > 0 --- Hyperbola
*/
int whichShapedOfConicSection(double a, double b, double c, double d, double e, double y)
{
    double temp = b * b - 4 * a * c;
    if (temp == (double)0)
        return 2; // Parabola
    else if (temp < (double)0)
        return 1; // Ellipse
    else if (temp > 0)
        return 3; // Hyperbola
}
/*
    <-- Find the coordinates of the focus and the vertex, the equations of the directrix and the axis, and the length of the latus rectum of the parabola y2 = 8x. -->
    Formulas:-
    Single Function printf all answre together:
    1. Coordinate of Focus:  F(a,0)
    2. Equation of Directix: x = -a
    3. Length of latus rectum: 4a unites
*/
void findCoordinateFocusEquationDirectixLengthLatusRectumOfParaBola(double x)
{
    // here x is a cofficent of y2 = 4ax
    double a = x / 4;
    printf("\nCoordinate of Focus: F(%.2lf,0)\nEquation of directix: x = -%.2lf\nLength of latus rectum: %.2lf", a, a, 4 * a);
}

/*
    <--
    1. Slope of a line passing through two points (x1, y1) & (x2, y2)
    Formula - Slope(m) = (y2-y1)/(x2-x1)
    where (x2-x1 != 0) if it is 0 then it is undefined means there is no slop

    2. Slope of Straight line ax + by + c  = 0
    Formula - m = -a / b

    3. Slope of a line with inclination of theeta degree
    Formula - m = tan0
    -->
*/

double slopeOfALineThroughTwoPoints(double x1, double y1, double x2, double y2)
{
    if (x2 - x1 == 0)
    {
        printf("\nSlope is undefined..!");
        return -1; // means slope is undefined
    }
    return ((y2 - y1) / (x2 - x1));
}
double slopOfStraightLine(double a, double b, double c)
{
    if (b == 0)
    {
        printf("\nResult is undefined..!");
        return -1; // indicate result is undefined
    }
    double m = -a / b;
    return m;
}
double slopeOfLineInclinationOfTheta(double angle)
{
    /* Note
    if theeta = 90 degree then m = infinity & it is a vertical line
    */
    if (angle == 90)
    {
        printf("\nslope m = undefined, it is a vetical line..!");
        return -1;
    }
    angle = (angle * 3.141592653589793238462643) / 180; // angle to radian
    return atan(angle);
}

/*
    <-- Angle b/w two lines having slopes m1 and m2 -->
    Formula - 0 = atan((m1 - m2) / (1 + m1 * m2))
*/

double angleBWTwoLinesHavingSlopes(double m1, double m2)
{
    // two lines are parallel if m1 == m2
    if (m1 == m2)
    {
        printf("\nLines are Parallel..!");
        return 0; // no angle
    }
    // two lines are perpendicular if m1 * m2 = -1
    if (m1 * m2 == (double)-1)
    {
        printf("\nLines are Perpendicular..!");
        return 90; // 90 degree angle create
    }
    return atan((m1 - m2) / (1 + m1 * m2));
}