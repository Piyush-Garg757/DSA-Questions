/*Maximum Manhattan Distance After All Moves

You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.
Starting from the origin (0, 0), each character represents one move on a 2D plane:
'U': Move up by 1 unit.
'D': Move down by 1 unit.
'L': Move left by 1 unit.
'R': Move right by 1 unit.
'_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.
Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.
The Manhattan distance between two points (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.
 
Example 1:
Input: moves = "L_D_"
Output: 4
Explanation:
One optimal choice is:
'L': (0, 0) -> (-1, 0)
'_' treated as 'D': (-1, 0) -> (-1, -1)
'D': (-1, -1) -> (-1, -2)
'_' treated as 'L': (-1, -2) -> (-2, -2)
The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.

Example 2:
Input: moves = "U_R"
Output: 3
Explanation:
One optimal choice is:
'U': (0, 0) -> (0, 1)
'_' treated as 'U': (0, 1) -> (0, 2)
'R': (0, 2) -> (1, 2)
The final Manhattan distance from the origin is |0 - 1| + |0 - 2| = 3.©leetcode*/

class Solution
{
public:
    int maxDistance(string a)
    {
        int x_e = 0, y_e = 0, count = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == 'U')
                x_e++;
            else if (a[i] == 'D')
                x_e--;
            else if (a[i] == 'R')
                y_e++;
            else if (a[i] == 'L')
                y_e--;
            else
                count++;
        }
        if (x_e < 0)
        {
            x_e -= count;
        }
        else
            x_e += count;
        return abs(x_e) + abs(y_e);
    }
};
// TC - O(n)  SC - O(1)