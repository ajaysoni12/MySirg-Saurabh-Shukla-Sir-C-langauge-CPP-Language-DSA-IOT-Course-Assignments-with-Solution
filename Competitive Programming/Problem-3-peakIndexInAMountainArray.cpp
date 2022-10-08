/* LeetCode Problem Number:- 852 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /* Approach 1 */
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
    /* Approach 2  Binary Search*/
     int peakIndexInMountainArray(vector<int> &arr)
    {
        int start = 0, end = arr.size() - 1;
        while (start < end)
        { 
            int mid = (left + right) / 2; 
            if(arr[mid] > arr[mid-1]) return mid; 
            else if(arr[mid]  > arr[mid+1]) return mid; 
            else if(arr[mid] < arr[start]) start = mid+1; 
            else end = mid - 1; 
        }
        return -1;
    }
};
