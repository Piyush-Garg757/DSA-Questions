/*Count the Number of Special Characters I
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
Return the number of special letters in word.

Example 1:
Input: word = "aaAbcBC"
Output: 3
Explanation:
The special characters in word are 'a', 'b', and 'c'.

Example 2:
Input: word = "abc"
Output: 0
Explanation:
No character in word appears in uppercase.

Example 3:
Input: word = "abBCab"
Output: 1
Explanation:
The only special character in word is 'b'*/

// My first approach - ekdum bekar approach
class Solution
{
public:
    int numberOfSpecialChars(string s)
    {
        vector<char> alpha(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                alpha[s[i] - 'a'] = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z' && alpha[s[i] - 'A'] == 1)
            {
                alpha[s[i] - 'A'] = 0;
                count++;
            }
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)

// Optimal approach - tagdi approach
class Solution
{
public:
    int numberOfSpecialChars(string s)
    {
        int lower = 0, upper = 0;
        for (auto c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                lower |= (1 << (c - 'a'));
            }
            else
            {
                upper |= (1 << (c - 'A'));
            }
        }
        int n = lower & upper;
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
// TC - O(n)  SC - O(1)

/*Example
For:
"aAbBc"
Lower mask:
a b c
1 1 1
Upper mask:
a b
1 1 0
AND:
1 1 0
Count set bits = 2.
Suppose
ch = 'c'
Then:
ch - 'a'
means:
'c' - 'a' = 2
Now
1 << 2
means:
1 ko 2 positions left shift karo
Binary:
1        = 000001
1 << 2   = 000100*/