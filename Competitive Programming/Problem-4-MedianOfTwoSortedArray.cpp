#include <bits/stdc++.h>
using namespace std;
float medianOfTwoSortedArray(int num1[], int num2[], int m, int n)
{
    if (m > n)
        return medianOfTwoSortedArray(num2, num1, n, m);
    int low = 0, high = m, medianPos = ((m + n) + 1) / 2;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = medianPos - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : num1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : num2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : num1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : num2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 != 0)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0f;
        }
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0.0f;
}
int main()
{
    int a[] = {1, 2, 3, 5};
    int b[] = {4, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]), m = sizeof(b) / sizeof(b[0]);
    cout << medianOfTwoSortedArray(a, b, n, m);
    return 0;
}