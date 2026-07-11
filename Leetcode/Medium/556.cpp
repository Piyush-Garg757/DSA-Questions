/*Next Greater Element III

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

Example 1:
Input: n = 12
Output: 21

Example 2:
Input: n = 21
Output: -1*/

class Solution
{
public:
    int nextGreaterElement(int m)
    {
        string a = to_string(m);
        int n = a.size(), idx = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
            return -1;
        for (int i = n - 1; i > idx; i--)
        {
            if (a[i] > a[idx])
            {
                swap(a[i], a[idx]);
                break;
            }
        }
        reverse(a.begin() + idx + 1, a.end());
        long long ans = stoll(a);
        if (ans > INT_MAX)
            return -1;
        return (int)ans;
    }
};
// TC - O(n)  SC - O(n)