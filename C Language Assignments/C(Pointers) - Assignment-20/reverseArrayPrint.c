#include <stdio.h>
void reverseArrayPrint(int *ptr, int n)
{
    for(int i = n-1; i>=0; i--)
        printf("%d ",*(ptr+i)); 
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
    reverseArrayPrint(arr, n);
    return 0;
}