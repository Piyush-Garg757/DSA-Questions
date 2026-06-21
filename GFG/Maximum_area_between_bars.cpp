/*Maximum Area Between Bars

Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.
Examples :
Input: height[] = [2, 5, 4, 3, 7]
Output: 10
Explanation:
The maximum rectangular area is formed by selecting the bars of heights 5 and 7.
There are 2 bars between them, so the area is: min(5, 7) × 2 = 10

Input: height[] = [1, 3, 4]
Output: 1
Explanation: Selecting bars 1 and 4 gives one bar between them, so the area is: min(1, 4) × 1 = 1*/

class Solution
{
public:
    int maxArea(vector<int> &a)
    {
        // code here
        int n = a.size();
        int i = 0, j = n - 1;
        int ans = INT_MIN;
        while (i < j)
        {
            int area = min(a[i], a[j]) * (j - i - 1);
            ans = max(area, ans);
            if (a[i] < a[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)