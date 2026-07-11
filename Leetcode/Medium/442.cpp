/*Find All Duplicates in an Array
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []*/

// My first approach
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &a)
    {
        int n = a.size();
        vector<int> hash(n + 1, -1);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (hash[a[i]] == 1)
            {
                ans.push_back(a[i]);
            }
            else
                hash[a[i]] = 1;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Most optimal approach - we can use the same array for hashing    for every a[i]  we visit index mod(a[i]) -1 and make it as negative and if the the number on that idx is already negative   we push to and since it is a duplicate   else we carry on
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[idx] *= -1;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)