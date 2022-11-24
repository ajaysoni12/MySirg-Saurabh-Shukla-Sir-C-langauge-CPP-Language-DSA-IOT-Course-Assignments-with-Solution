#include <iostream>
using namespace std;
template <typename X>
X sumOfArray(X arr[], int length)
{
    X sum = 0;
    for (int i = 0; i < length; i++)
        sum += arr[i];
    return sum;
}
int main()
{
    float arr[] = {3, 5.4, 6, 7, 8};
    int brr[] = {2, 3, 4, 5};
    int size = 5;
    cout << sumOfArray<float>(arr, size) << endl;
    cout << sumOfArray<int>(brr, 4);
    return 0;
}