/*N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]*/

class Solution
{
public:
    bool is_safe(int row, int col, vector<string> &v, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (v[i][j] == 'Q')
                {
                    if (row == i)
                        return false;
                    if (abs(row - i) == abs(col - j))
                        return false;
                }
            }
        }
        return true;
    }
    void solve(int n, vector<vector<string>> &ans, vector<string> &v,
               int curr_col)
    {
        if (curr_col == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (is_safe(i, curr_col, v, n))
            {
                v[i][curr_col] = 'Q';
                solve(n, ans, v, curr_col + 1);
                v[i][curr_col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;
        int curr_col = 0;
        solve(n, ans, v, curr_col);
        return ans;
    }
};
// TC - O(n^2*n!)  SC - O(n^2)