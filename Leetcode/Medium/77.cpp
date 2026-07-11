/*Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.*/

class Solution
{
public:
    void solve(int n, int k, vector<vector<int>> &ans, vector<int> &v,
               int curr)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i <= n; i++)
        {
            v.push_back(i);
            solve(n, k, ans, v, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> v;
        int curr = 1;
        solve(n, k, ans, v, curr);
        return ans;
    }
};
// TC - O(nCk * k)  SC - O(k)