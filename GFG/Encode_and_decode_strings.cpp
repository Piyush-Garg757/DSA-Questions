/*Encode and Decode Strings

Given an array of strings arr[], implement an algorithm in the encode() function that can convert the given strings into a single encoded string, which can be transmitted over the network and then decoded back into the original array of strings from the encoded string. The decoding will happen in the decode() function.
The encoding rule used here is:
Each string is stored as length + "/:" + actual string.
During decoding, we first read the length before the delimiter "/:", and then extract that many characters as the original string.
This approach works for all ASCII characters since the length ensures correct parsing regardless of string content.
Note: You are not allowed to use any inbuilt serialize method.

Examples:
Input: arr[] = ["Hello", "World"]
Output: ["Hello","World"]
Explanation:
The encode() function converts the array into a single string by storing each word as length + "/:" + string.
For the given input, "Hello" becomes "5/:Hello", "World" becomes "5/:World". These are concatenated to form "5/:Hello5/:World", which is transmitted.
During decoding, we read the length before "/:", then extract that many characters:
Read 5 then extract "Hello"
Read 5 then extract "World"
Thus, the original array ["Hello", "World"] is reconstructed.

Input: arr[] = ["abc", "!@"]
Output: ["abc","!@"]
Explanation: The encode() function converts each string into length + "/:" + string and concatenates them. Here: "abc" becomes "3/:abc", "!@" becomes "2/:!@" then encoded string = "3/:abc2/:!@".
During decoding, lengths are read to extract exact substrings, reconstructing ["abc","!@"].*/

class Solution
{
public:
    string encode(vector<string> &a)
    {
        // write your logic to encode the strings
        string ans = "";
        for (int i = 0; i < a.size(); i++)
        {
            string str = a[i];
            ans += to_string(str.length()) + "/:" + str;
        }
        return ans;
    }

    vector<string> decode(string &s)
    {
        vector<string> ans;
        int i = 0;
        int n = s.length();
        while (i < n)
        {
            int j = i;
            while (s[j] != '/')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            j += 2;
            string str = s.substr(j, length);
            ans.push_back(str);
            i = j + length;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)