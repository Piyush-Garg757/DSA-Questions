/*Intersection of Two Arrays II
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.*/

class Solution
{
public:
    vector<int> intersect(vector<int> &a, vector<int> &b)
    {
        vector<int> x(1001, 0);
        for (int i = 0; i < a.size(); i++)
        {
            x[a[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < b.size(); i++)
        {
            if (x[b[i]] != 0)
            {
                x[b[i]]--;
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};
// TC - O(n+m)  SC - O(1001)