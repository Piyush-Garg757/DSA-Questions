/*Number of Closed Islands

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.

Example 1:
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation:
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2*/

class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &a)
    {
        a[row][col] = -1;
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < 4; i++)
        {
            int delrow = row + r[i];
            int delcol = col + c[i];
            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                a[delrow][delcol] == 0)
            {
                dfs(delrow, delcol, a);
            }
        }
    }
    int closedIsland(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size(), count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == 0)
                dfs(i, 0, a);
            if (a[i][m - 1] == 0)
                dfs(i, m - 1, a);
        }
        for (int j = 0; j < m; j++)
        {
            if (a[0][j] == 0)
                dfs(0, j, a);
            if (a[n - 1][j] == 0)
                dfs(n - 1, j, a);
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (a[i][j] == 0)
                {
                    dfs(i, j, a);
                    count++;
                }
            }
        }
        return count;
    }
};
// TC - O(nm)  SC - O(nm)