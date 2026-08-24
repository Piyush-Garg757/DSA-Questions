/*Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.*/

class Solution
{
public:
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>> &a)
    {
        a[row][col] = -1;
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < 4; i++)
        {
            int delrow = row + r[i];
            int delcol = col + c[i];
            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                a[delrow][delcol] == 1)
                dfs(delrow, delcol, a);
        }
    }
    int numEnclaves(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == 1)
            {
                dfs(i, 0, a);
            }
            if (a[i][m - 1] == 1)
            {
                dfs(i, m - 1, a);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (a[0][j] == 1)
            {
                dfs(0, j, a);
            }
            if (a[n - 1][j] == 1)
            {
                dfs(n - 1, j, a);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
// TC - O(n*m)  SC - O(n*m)