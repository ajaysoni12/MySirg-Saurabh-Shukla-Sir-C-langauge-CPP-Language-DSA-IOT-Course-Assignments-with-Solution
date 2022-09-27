/* LeetCode Problem Number:- 852 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;
        while (start <= end)
        {
            if (start == end)
                return start;
            else if (arr[start] <= arr[end])
                start++;
            else
                end--;
        }
        return -1;
    }
};