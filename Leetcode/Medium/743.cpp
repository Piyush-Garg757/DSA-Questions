/*Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &a, int n, int k)
    {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][0] - 1].push_back({a[i][1] - 1, a[i][2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k - 1});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto i : adj[node])
            {
                int edge = i.first;
                int wt = i.second;
                if (d + wt < dist[edge])
                {
                    dist[edge] = d + wt;
                    pq.push({dist[edge], edge});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dist[i]);
            if (dist[i] == INT_MAX)
                return -1;
        }
        return ans;
    }
};
// TC - O((e+v)logv)  SC - O(e+v)