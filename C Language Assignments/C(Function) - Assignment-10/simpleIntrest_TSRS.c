#include <stdio.h>
float simpleIntrest(float p, float r, float t)
{
    return (p * r * t) / 100.0;
}
int main()
{
    float p, r, t;
    printf("Enter the value of P,R,T: ");
    scanf("%f%f%f", &p, &r, &t);
    printf("Simple Intrest is: %.2f", simpleIntrest(p, r, t));
    return 0;
}