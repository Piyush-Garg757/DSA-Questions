/*All Paths From Source to Target

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]*/


// Easy recurssion + dfs traversal
class Solution
{
public:
    void dfs(vector<vector<int>> &ans, int idx, vector<vector<int>> &a, vector<int> v)
    {
        int n = a.size();
        if (idx == n - 1)
        {
            ans.push_back(v);
            return;
        }
        for (auto i : a[idx])
        {
            v.push_back(i);
            dfs(ans, i, a, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(0);
        dfs(ans, 0, a, v);
        return ans;
    }
};
// TC - O(p*v+e)  SC - O(v)  where p is the number of paths