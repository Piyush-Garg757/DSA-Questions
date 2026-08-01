/*Count Partitions with Even Sum Difference

You are given an integer array nums of length n.
A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:
Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.

Example 1:
Input: nums = [10,10,3,7,6]
Output: 4
Explanation:
The 4 partitions are:
[10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
[10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
[10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
[10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation:
No partition results in an even sum difference.

Example 3:
Input: nums = [2,4,6,8]
Output: 3
Explanation:
All partitions result in an even sum difference.*/

class Solution
{
public:
    int countPartitions(vector<int> &a)
    {
        int n = a.size(), sum = 0, pref_sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        for (int i = 0; i < n - 1; i++)
        {
            pref_sum += a[i];
            int rem = sum - pref_sum;
            if (abs(pref_sum - rem) % 2 == 0)
                ans++;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)

/*Observation
Let
L = left sum
R = right sum
Total = L + R
We want:
(L−R) is even
Now,
L−R=L−(Total−L)=2L−Total
Since 2L is always even, the parity of 2L - Total depends only on Total.
That means:
If Total is even, then every partition has an even difference.
If Total is odd, then no partition has an even difference.
Therefore
No need to compute prefix sums at all.

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int x : nums)
            sum += x;

        return (sum % 2 == 0) ? nums.size() - 1 : 0;
    }
};*/