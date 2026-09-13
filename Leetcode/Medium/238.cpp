/*Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]*/

// My first and optimal approach
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &a)
    {
        long long prod = 1;
        int n = a.size(), zero_count = 0;
        bool zero_present = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zero_present = true;
                zero_count++;
                continue;
            }
            prod *= 1ll * a[i];
        }
        if (zero_count >= 2 || zero_count == n)
        {
            for (int i = 0; i < n; i++)
            {
                a[i] = 0;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (zero_present)
                {
                    if (a[i] != 0)
                        a[i] = 0;
                    else
                        a[i] = prod;
                }
                else
                    a[i] = prod / a[i];
            }
        }
        return a;
    }
};
// TC - O(n)  SC - O(1)

// More intuitive approach
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n, 1);

        int prefix = 1;

        for (int i = 0; i < n; i++)
        {
            ans[i] = prefix;
            prefix *= a[i];
        }

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= suffix;
            suffix *= a[i];
        }

        return ans;
    }
};
// TC - O(n)  SC - O(1)