/*Wiggle Sort II

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

Example 1:
Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.

Example 2:
Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]*/


// My first and mostly accepted sol
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int left = (n - 1) / 2;
        int right = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                nums[i] = temp[left--];
            else
                nums[i] = temp[right--];
        }
    }
};
// TC - O(nlogn)  SC - O(1)

// If further optimisation is required
