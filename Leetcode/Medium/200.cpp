/*Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3*/

class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &a)
    {
        a[row][col] = '0';
        int n = a.size(), m = a[0].size();
        for (int i = -1; i <= 1; i++)
        {
            int delrow = row + i, delcol = col;
            if (delrow >= 0 && delrow < n && a[delrow][delcol] == '1')
            {
                dfs(delrow, delcol, a);
            }
        }
        for (int j = -1; j <= 1; j++)
        {
            int delrow = row, delcol = col + j;
            if (delcol >= 0 && delcol < m && a[delrow][delcol] == '1')
            {
                dfs(delrow, delcol, a);
            }
        }
    }
    int numIslands(vector<vector<char>> &a)
    {
        int n = a.size(), m = a[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '1')
                {
                    dfs(i, j, a);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// TC - O(n*m)  SC - O(n*m)