/*Count Commas in Range II\

You are given an integer n.
Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.
In standard formatting:
A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.

Example 1:
Input: n = 1002
Output: 3
Explanation:
The numbers "1,000", "1,001", and "1,002" each contain one comma, giving a total of 3.

Example 2:
Input: n = 998
Output: 0
Explanation:
​​​​​​​All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.*/

class Solution
{
public:
    long long countCommas(long long n)
    {
        long long ans = 0;
        if (n >= 1000)
        {
            ans += n - 999;
        }
        if (n >= 1000000)
        {
            ans += n - 999999;
        }
        if (n >= 1000000000LL)
        {
            ans += n - 999999999LL;
        }
        if (n >= 1000000000000LL)
        {
            ans += n - 999999999999LL;
        }
        if (n >= 1000000000000000LL)
        {
            ans += n - 999999999999999LL;
        }
        return ans;
    }
};
// TC - O(1)  SC - O(1)