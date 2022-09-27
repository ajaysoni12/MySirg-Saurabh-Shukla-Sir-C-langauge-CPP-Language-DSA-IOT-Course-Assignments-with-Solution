/* LeetCode Problem Number:- 09 */
class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0)
        return false;
    long int reverseNum = 0;
    for (long int i = x; i != 0; i /= 10)
        reverseNum = reverseNum * 10 + i % 10;
    if (x == reverseNum)
        return true;
    return false;   
    }
};