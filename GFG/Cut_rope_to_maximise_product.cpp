/*Cut rope to maximise product

Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.

Examples:
Input: n = 2
Output: 1
Explanation: Since 1 cut is mandatory. Maximum obtainable product is 1 * 1 = 1.

Input: n = 5
Output: 6
Explanation: Maximum obtainable product is 2 * 3 = 6.*/

class Solution
{
public:
    int maxProduct(int n)
    {
        // code here
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n % 3 == 0)
        {
            return pow(3, n / 3);
        }
        else if (n % 3 == 1)
        {
            return pow(3, (n / 3) - 1) * (n - 3 * ((n / 3) - 1));
        }
        return pow(3, n / 3) * (n % 3);
    }
};
// TC - O(logn)  SC - O(1)