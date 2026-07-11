/*Sort Array by Increasing Frequency

Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
Return the sorted array.

Example 1:
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Example 2:
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.

Example 3:
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]*/

class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<pair<int, int>> v;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                count++;
            else
            {
                if (a[i] == a[i - 1])
                    count++;
                else
                {
                    v.push_back({count, a[i - 1]});
                    count = 1;
                }
            }
        }
        v.push_back({count, a[n - 1]});
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
        {
            int count = v[i].first;
            while (count)
            {
                ans.push_back(v[i].second);
                count--;
            }
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)