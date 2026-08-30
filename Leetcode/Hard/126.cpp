/*Word Ladder II

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.*/


// This is brute force in which we are storing entire path so this won't submit on lc but gfg pe ho jayega
class Solution
{
public:
    vector<vector<string>> findLadders(string s1, string s2, vector<string> &a)
    {
        unordered_set<string> st(a.begin(), a.end());
        vector<vector<string>> ans;
        if (st.find(s2) == st.end())
            return ans;
        queue<vector<string>> q;
        vector<string> used;
        q.push({s1});
        int curr_level = 0;
        while (!q.empty())
        {
            vector<string> v = q.front();
            q.pop();
            if (v.size() > curr_level)
            {
                curr_level++;
                for (auto i : used)
                    st.erase(i);
                used.clear();
            }
            string s = v.back();
            if (s == s2)
            {
                if (ans.size() == 0 || v.size() == ans[0].size())
                {
                    ans.push_back(v);
                }
                continue;
            }
            for (int i = 0; i < s.length(); i++)
            {
                string pseudo = s;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    pseudo[i] = ch;
                    if (st.count(pseudo))
                    {
                        v.push_back(pseudo);
                        q.push(v);
                        v.pop_back();
                        used.push_back(pseudo);
                    }
                }
            }
        }
        return ans;
    }
};


