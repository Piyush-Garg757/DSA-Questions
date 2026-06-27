/*Primes in a Range

Given two integers l and r, find and return all prime numbers in the range [l, r] (inclusive).

Examples:

Input: l = 1, r = 10
Output: [2, 3, 5, 7]
Explanation:
The prime numbers between 1 and 10 are 2, 3, 5 and 7.

Input: l = 2, r = 5
Output: [2, 3, 5]
Explanation:
The prime numbers between 2 and 5 are 2, 3 and 5.*/

class Solution
{
public:
    vector<int> primeRange(int l, int r)
    {
        // code here
        vector<int> prime(r + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= r; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= r; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        vector<int> ans;
        for (int i = l; i < r + 1; i++)
        {
            if (prime[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(rlog(logr))  SC - O(r)