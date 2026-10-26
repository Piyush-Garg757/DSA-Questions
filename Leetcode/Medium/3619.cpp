/*Count Islands With Total Value Divisible by K

You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
The total value of an island is the sum of the values of all cells in the island.
Return the number of islands with a total value divisible by k.

Example 1:
Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
Output: 2
Explanation:
The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

Example 2:
Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
Output: 6
Explanation:
The grid contains six islands, each with a total value that is divisible by 3.*/

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &a, long long &sum)
    {
        sum += a[row][col];
        int n = a.size(), m = a[0].size();
        a[row][col] = -1;
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int delrow = row + r[i];
            int delcol = col + c[i];
            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                a[delrow][delcol] > 0)
            {
                dfs(delrow, delcol, a, sum);
            }
        }
    }
    int countIslands(vector<vector<int>> &a, int k)
    {
        int n = a.size(), m = a[0].size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long sum = 0;
                if (a[i][j] > 0)
                {
                    dfs(i, j, a, sum);
                    if (sum % k == 0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
// TC - O(m*n)  SC - O(n*m)