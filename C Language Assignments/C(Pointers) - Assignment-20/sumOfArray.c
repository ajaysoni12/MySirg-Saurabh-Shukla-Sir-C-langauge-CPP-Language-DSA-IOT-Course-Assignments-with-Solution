#include <stdio.h>
int sumOfArray(int *ptr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(ptr + i);
    return sum;
}
int main()
{
    int n;
    printf("\nhow many number u want to enter : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d element: \n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int sum = sumOfArray(arr, n);
    printf("\nSum of Array is: %d", sum);
    return 0;
}