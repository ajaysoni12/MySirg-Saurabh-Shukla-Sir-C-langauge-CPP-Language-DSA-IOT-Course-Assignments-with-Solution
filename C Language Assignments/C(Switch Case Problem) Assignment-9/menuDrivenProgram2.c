// An Isosceles triangle is a triangle that has two equal sides.
//  A2 + B2 = C2 - right angle triangle
// an equilateral triangle is a triangle in which all three sides are equal.
#include <stdio.h>
#include <stdlib.h>
int main()
{
    while (1)
    {
        int choice;
        printf("\n1. Check Triangle is Isosceles or not ");
        printf("\n2. Check Triagnle is Right Angle Triangle or not ");
        printf("\n3. Check Trinagle is equilateral triangle or not ");
        printf("\n4. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int x, y, z;
        switch (choice)
        {
        case 1:
            printf("Enter the sides of length : ");
            scanf("%d%d%d", &x, &y, &z);
            if (x == y || x == z || y == z)
                printf("Isosceles Trinagle!");
            else
                printf("Not isosceles Trinagle!");
            break;
        case 2:
            printf("Enter the sides of length: ");
            scanf("%d%d%d", &x, &y, &z);
            if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x)
                printf("Yup!, it is right angle triangle!");
            else
                printf("it's not a right angle triangle!");
            break;
        case 3:
            printf("Enter the sides of length: ");
            scanf("%d%d%d", &x, &y, &z);
            if (x == y && x == z)
                printf("Equiletral Triangel!");
            else
                printf("Not, equiletral triangle!");
                break; 
        case 4:
            printf("Thanku!");
            exit(0);
        default:
            printf("Invalid choice!");
        }
    }
    return 0;
}