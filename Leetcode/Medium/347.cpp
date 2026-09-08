/*Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]*/

// My first approach
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &a, int k)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < a.size(); i++)
        {
            mpp[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto i : mpp)
        {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (!k)
                break;
            k--;
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(m)

// Most optimal sol - Using Bucket sort
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &a, int k)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < a.size(); i++)
        {
            mpp[a[i]]++;
        }
        vector<vector<int>> v(a.size() + 1);
        for (auto i : mpp)
        {
            v[i.second].push_back(i.first);
        }
        vector<int> ans;
        for (int i = a.size(); i >= 0; i--)
        {
            if (!k)
                break;
            for (auto j : v[i])
            {
                if (!k)
                    break;
                k--;
                ans.push_back(j);
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)
// ismein hum kya kar rahe hain agar normal bucket sort se karein to nahi kar sakte kyuki bohot range ke elements hain but koi element kitni baar aa raha hai uspe hum bucket sort laga sakte hain jismein maximum hoga array ka size kyuki us se zyada baar to koi element aa nahi sakta to hum yahi karenge ek bucket banayenge aur jo element jitni baar ayega utne number pe jake use ppush kar denge    aur fir end me last se iterate karte hue k elements le lenge