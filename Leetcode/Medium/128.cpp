/*Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto &val : s)
        {
            if (s.contains(val - 1))
                continue;
            int num = val;
            int cur = 1;
            while (s.contains(num + 1))
            {
                cur++;
                num++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)