/*Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]
Example 3:
Input: strs = ["a"]
Output: [["a"]]*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &a)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> mpp;
        int k = 0;
        for (int i = 0; i < a.size(); i++)
        {
            string pseudo = a[i];
            sort(pseudo.begin(), pseudo.end());
            if (mpp.count(pseudo))
            {
                ans[mpp[pseudo]].push_back(a[i]);
            }
            else
            {
                mpp[pseudo] = k++;
                ans.push_back({a[i]});
            }
        }
        return ans;
    }
};
// TC - O(mnlogn)  SC - O(mn)

// optimal sol
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &a)
    {
        unordered_map<string, vector<string>> mpp;
        for (string &s : a)
        {
            int count[26] = {};
            for (char c : s)
                count[c - 'a']++;
            string key;
            for (int i = 0; i < 26; i++)
            {
                key += to_string(count[i]) + '#';
            }
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &it : mpp)
            ans.push_back(it.second);
        return ans;
    }
};
// TC - O(mn)  SC - O(mn)