/*Smallest Divisible Digit Product I

You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.*/

class Solution
{
public:
    int prod_digits(int n)
    {
        int prod = 1;
        while (n)
        {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t)
    {
        while (prod_digits(n) % t != 0)
            n++;
        return n;
    }
};
// TC - O(k)  SC - O(1)