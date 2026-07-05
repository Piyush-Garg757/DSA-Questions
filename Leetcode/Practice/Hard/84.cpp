/*Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4*/

// My first approach 
class Solution
{
public:
    vector<int> nextSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &a)
    {
        vector<int> lt = prevSmallerIndex(a);
        vector<int> rt = nextSmallerIndex(a);
        int n = a.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (rt[i] - lt[i] - 1) * a[i]);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)