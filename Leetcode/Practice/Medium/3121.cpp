/*Count the Number of Special Characters II
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
Return the number of special letters in word.

Example 1:
Input: word = "aaAbcBC"
Output: 3
Explanation:
The special characters are 'a', 'b', and 'c'.

Example 2:
Input: word = "abc"
Output: 0
Explanation:
There are no special characters in word.

Example 3:
Input: word = "AbBCab"
Output: 0
Explanation:
There are no special characters in word*/

// My first approach
class Solution
{
public:
    int numberOfSpecialChars(string a)
    {
        int n = a.length();
        unordered_map<char, int> mpp;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 'a' && a[i] <= 'z')
            {
                mpp[a[i]] = i;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 'A' && a[i] <= 'Z')
            {
                if (mpp.find(tolower(a[i])) != mpp.end()) // aisa isiliye kiya kyuki agar element nhi hota map mein aur hum fir bhi access karte hain to vo bana deta hai with value 0  to us se nachne ke liye
                {
                    int x = mpp[tolower(a[i])];
                    mpp[tolower(a[i])] = -1;
                    if ((i > x) && x != -1)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)

// Optimal sol - vahi ki alphabets hai to we can use fixed size array rather than map
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {

        vector<int> lower(26, -1);
        vector<int> upper(26, -1);

        for (int i = 0; i < word.size(); i++)
        {

            if (islower(word[i]))
            {
                lower[word[i] - 'a'] = i;
            }
            else
            {

                int idx = word[i] - 'A';

                if (upper[idx] == -1)
                {
                    upper[idx] = i;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++)
        {

            if (lower[i] != -1 &&
                upper[i] != -1 &&
                lower[i] < upper[i])
            {

                count++;
            }
        }

        return count;
    }
};
// TC - O(n)  SC - O(26)