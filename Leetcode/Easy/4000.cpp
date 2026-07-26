/*Largest Integer With Given Digit Sum

You are given two non-negative integers n and s.
Return the largest integer that has at most n digits and whose sum of digits is s. If no such integer exists, return -1.

Example 1:
Input: n = 2, s = 9
Output: 90
Explanation:
The largest integer with at most 2 digits that has a sum of digits of 9 is 90.

Example 2:
Input: n = 2, s = 19
Output: -1
Explanation:
There is no integer with at most 2 digits that has a sum of digits of 19, so the answer is -1.

Example 3:
Input: n = 5, s = 0
Output: 0
Explanation:
The only non-negative integer whose digits sum to 0 is 0.*/

class Solution
{
public:
    int largestInteger(int n, int s)
    {
        if (s > 9 * n)
            return -1;
        int ans = 0;
        while (s >= 9)
        {
            ans = ans * 10;
            ans += 9;
            s -= 9;
        }
        if (s)
        {
            ans = ans * 10;
            ans += s;
        }
        int digits = 0;
        int temp = ans;
        if (temp == 0)
            digits = 1;
        else
        {
            while (temp)
            {
                digits++;
                temp /= 10;
            }
        }
        while (digits < n)
        {
            ans *= 10;
            digits++;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)