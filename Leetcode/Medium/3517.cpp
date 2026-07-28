/*Smallest Palindromic Rearrangement I

You are given a palindromic string s.
Return the lexicographically smallest palindromic permutation of s.

Example 1:
Input: s = "z"
Output: "z"
Explanation:
A string of only one character is already the lexicographically smallest palindrome.

Example 2:
Input: s = "babab"
Output: "abbba"
Explanation:
Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:
Input: s = "daccad"
Output: "acddca"
Explanation:
Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.*/

// My first approach
class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.length();
        sort(s.begin(), s.begin() + n / 2);
        string ans = s.substr(0, n / 2);
        if (n % 2)
            ans += s[n / 2];
        for (int i = n / 2 - 1; i >= 0; i--)
            ans += ans[i];
        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)

// Most optimal approach
class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> frequency_map(26, 0);
        for (char c : s)
            frequency_map[c - 'a']++;
        string firstHalf = "";
        char mid = 0;
        for (int i = 0; i < 26; i++)
        {
            int freq = frequency_map[i];
            for (int j = 0; j < freq / 2; j++)
                firstHalf += char('a' + i);
            if (freq % 2)
                mid = char('a' + i);
        }
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        if (mid)
            return firstHalf + mid + secondHalf;
        return firstHalf + secondHalf;
    }
};
// TC - O(n)  SC - O(n)