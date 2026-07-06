/*Remove Covered Intervals

Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
Return the number of remaining intervals.

Example 1:
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.

Example 2:
Input: intervals = [[1,4],[2,3]]
Output: 1*/

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &a)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        int start = a[0][0], end = a[0][1], count = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i][0] == start)
            {
                count++;
                end = a[i][1];
            }
            else
            {
                if (a[i][1] <= end)
                {
                    count++;
                }
                else
                {
                    start = a[i][0];
                    end = a[i][1];
                }
            }
        }
        return n - count;
    }
};
// TC - O(nlogn)  SC - O(1)