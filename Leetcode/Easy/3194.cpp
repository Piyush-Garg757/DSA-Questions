/*Minimum Average of Smallest and Largest Elements

You have an array of floating point numbers averages which is initially empty. You are given an array nums of n integers where n is even.
You repeat the following procedure n / 2 times:
Remove the smallest element, minElement, and the largest element maxElement, from nums.
Add (minElement + maxElement) / 2 to averages.
Return the minimum element in averages.

Example 1:
Input: nums = [7,8,3,4,15,13,4,1]
Output: 5.5

Example 2:
Input: nums = [1,9,8,3,10,5]
Output: 5.5

Example 3:
Input: nums = [1,2,3,7,8,9]
Output: 5.0
*/

class Solution
{
public:
    double minimumAverage(vector<int> &a)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        int mini = INT_MAX;
        for (int i = 0; i < n / 2; i++)
        {
            mini = min(mini, a[i] + a[n - i - 1]);
        }
        return mini / 2.0;
    }
};
// TC - O(nlogn)  SC - O(1)