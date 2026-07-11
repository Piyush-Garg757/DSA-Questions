/*Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:
*/

class Solution
{
public:
    bool safe(vector<vector<char>> &board, int n, int row, int col, char ch)
    {
        for (int i = 0; i < n; i++)
        {
            if (board[i][col] == ch)
                return false;
            if (board[row][i] == ch)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) // yaad rakhne aur samajhne layak cheez hai ye ki kaise box mein iterate kiya i kaloop lagake
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (safe(board, n, i, j, ch))
                        {
                            board[i][j] = ch;
                            if (solve(board, n) == true) // agar koi na koi char fill kar pa rahe ho to true return karo chalte raho aage
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false; // agar koi element fill nahi kar paye to false return karo ki pichle vale mein koi aur ayega na ki ye backtract karna padega
                }
            }
        }
        return true; // agar koi bhi khali nahi bacha to return 
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        int n = board.size();
        solve(board, n);
    }
};
// TC - O(9^e)  SC - O(e) where e is the number of empty cells