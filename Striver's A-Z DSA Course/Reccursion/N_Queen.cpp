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

// Intution curr_col lwkw chalo aur har col mein optimally place karte chalo check karte hue ki yaha place kar sakte hai ya nahi aur aise hi aagr n tak pahhuch gaya curr_sol to matlab ki ek sol mila hai
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

// Slight optimisation in is_safe - rather than checking all previous queens and eliminating positions in thr curr_col whih cant be filled we check which previous queen collide with the current one and if we cant find one we return true
class Solution
{
public:
    bool is_safe(int row, int col, vector<string> &v, int n)
    {
        int r = row, c = col;
        while (c >= 0)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
        }
        c = col;
        while (c >= 0 && r >= 0)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
            r--;
        }
        r = row, c = col;
        while (c >= 0 && r < n)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
            r++;
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
// TC - O(n*n!)  SC - O(n^2)

// Most optimal sol
class Solution
{
public:
    void solve(int n, vector<vector<string>> &ans, vector<string> &v, int curr_col, vector<int> &upperdiagonal,
               vector<int> &lowerdiagonal, vector<int> &leftrow)
    {
        if (curr_col == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (lowerdiagonal[i + curr_col] == 0 &&
                upperdiagonal[n - 1 + curr_col - i] == 0 && leftrow[i] == 0)
            {
                v[i][curr_col] = 'Q';
                lowerdiagonal[i + curr_col] = 1;
                upperdiagonal[n - 1 + curr_col - i] = 1;
                leftrow[i] = 1;
                solve(n, ans, v, curr_col + 1, upperdiagonal, lowerdiagonal, leftrow);
                lowerdiagonal[i + curr_col] = 0;
                upperdiagonal[n - 1 + curr_col - i] = 0;
                leftrow[i] = 0;
                v[i][curr_col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        vector<int> upperdiagonal(2 * n - 1, 0);
        vector<int> lowerdiagonal(2 * n - 1, 0);
        vector<int> leftrow(n, 0);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;
        int curr_col = 0;
        solve(n, ans, v, curr_col, upperdiagonal, lowerdiagonal, leftrow);
        return ans;
    }
};
// TC - O(n!)  SC - O(n^2)