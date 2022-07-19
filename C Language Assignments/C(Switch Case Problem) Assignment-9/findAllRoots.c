#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c;
    float root1, root2, imaginary;
    float discriminant;
    printf("Enter values of a, b, c of quadratic equation (aX^2 + bX + c): ");
    scanf("%f%f%f", &a, &b, &c);
    discriminant = (b * b) - (4 * a * c);
    switch (discriminant > 0)
    {
    case 1:
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two distinct and real roots exists: %.2f and %.2f",
               root1, root2);
        break;

    case 0:
        switch (discriminant < 0)
        {
        case 1:
            root1 = root2 = -b / (2 * a);
            imaginary = sqrt(-discriminant) / (2 * a);
            printf("Two distinct complex roots exists: %.2f + i%.2f and %.2f - i%.2f",
                   root1, imaginary, root2, imaginary);
            break;

        case 0:
            root1 = root2 = -b / (2 * a);
            printf("Two equal and real roots exists: %.2f and %.2f", root1, root2);
            break;
        }
    }

    return 0;
}