/*Minimum Sum of Four Digit Number After Splitting Digits

You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.

Example 1:
Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

Example 2:
Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc.
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.*/

class Solution
{
public:
    int minimumSum(int n)
    {
        int a = -1, b = -1, c = -1, d = -1;
        while (n)
        {
            int digit = n % 10;
            if (a == -1)
                a = digit;
            else if (b == -1)
                b = digit;
            else if (c == -1)
                c = digit;
            else
                d = digit;
            n /= 10;
        }
        int mn1 = min({a, b, c, d});
        if (mn1 == b)
            swap(a, b);
        else if (mn1 == c)
            swap(a, c);
        else if (mn1 == d)
            swap(a, d);
        int mn2 = min({b, c, d});
        if (mn2 == c)
            swap(b, c);
        else if (mn2 == d)
            swap(b, d);
        return a * 10 + c + b * 10 + d;
    }
};
// TC - O(logn)  SC - O(1)