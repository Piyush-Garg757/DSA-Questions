/*Generate Binary Strings Without Adjacent Zeros

You are given a positive integer n.
A binary string x is valid if all substrings of x of length 2 contain at least one "1".
Return all valid strings with length n, in any order.

Example 1:
Input: n = 3
Output: ["010","011","101","110","111"]
Explanation:
The valid strings of length 3 are: "010", "011", "101", "110", and "111".

Example 2:
Input: n = 1
Output: ["0","1"]
Explanation:
The valid strings of length 1 are: "0" and "1".*/

class Solution
{
public:
    void solve(int n, vector<string> &ans, string &s, int idx)
    {
        if (idx == n)
        {
            ans.push_back(s);
            return;
        }
        if (!s.empty() && s[idx - 1] == '0')
        {
            s.push_back('1');
            solve(n, ans, s, idx + 1);
            s.pop_back();
        }
        else
        {
            s.push_back('1');
            solve(n, ans, s, idx + 1);
            s.pop_back();
            s.push_back('0');
            solve(n, ans, s, idx + 1);
            s.pop_back();
        }
    }
    vector<string> validStrings(int n)
    {
        vector<string> ans;
        int idx = 0;
        string s = "";
        solve(n, ans, s, idx);
        return ans;
    }
};