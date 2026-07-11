/*Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.*/

// My first approach
class Solution
{
public:
    bool check_row(vector<vector<char>> &a, int row, char target)
    {
        int count = 0;
        for (int j = 0; j < 9; j++)
        {
            if (a[row][j] == target)
                count++;
        }
        return count == 1;
    }
    bool check_col(vector<vector<char>> &a, int col, char target)
    {
        int count = 0;
        for (int i = 0; i < 9; i++)
        {
            if (a[i][col] == target)
                count++;
        }
        return count == 1;
    }
    bool check_box(vector<vector<char>> &a, int row, int col, char target)
    {
        int s_col = 0, e_col = 0, e_row = 0, s_row = 0;
        if (row < 3)
        {
            e_row = 3;
            s_row = 0;
        }
        else if (row < 6)
        {
            s_row = 3;
            e_row = 6;
        }
        else if (row < 9)
        {
            s_row = 6;
            e_row = 9;
        }
        if (col < 3)
        {
            e_col = 3;
            s_col = 0;
        }
        else if (col < 6)
        {
            s_col = 3;
            e_col = 6;
        }
        else if (col < 9)
        {
            s_col = 6;
            e_col = 9;
        }
        int count = 0;
        for (int i = s_row; i < e_row; i++)
        {
            for (int j = s_col; j < e_col; j++)
            {
                if (a[i][j] == target)
                    count++;
            }
        }
        return count == 1;
    }
    bool isValidSudoku(vector<vector<char>> &a)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char target = a[i][j];
                if (target == '.')
                    continue;
                if (check_row(a, i, target) == false ||
                    check_col(a, j, target) == false ||
                    check_box(a, i, j, target) == false)
                    return false;
            }
        }
        return true;
    }
};
// TC - O(9^4)  SC - O(1)

// Most optimal approach - using hash sets
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num])
                        return false;
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};
// TC - O(9^2)  SC - O(9^2)