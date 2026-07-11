/*3Sum Closest
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).*/

class Solution
{
public:
    int threeSumClosest(vector<int> &a, int target)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int diff = INT_MAX, ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = a[i] + a[j] + a[k];
                if (abs(sum - target) < diff)
                {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return target;
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(1)