/* LeetCode Problem Number:- 238 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix, suffix, ans;

        int temp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            temp *= nums[i];
            prefix.push_back(temp);
        }
        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            temp *= nums[i];
            suffix.push_back(temp);
        }
        reverse(suffix.begin(), suffix.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                ans.push_back(suffix[i + 1]);
            else if (i == nums.size() - 1)
                ans.push_back(prefix[i - 1]);
            else
                ans.push_back(prefix[i - 1] * suffix[i + 1]);
        }
        return ans;
    }
};