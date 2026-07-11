/*Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3*/

// My first approach - but here i am modifying array
class Solution
{
public:
    int findDuplicate(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int ans = -1;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == a[i - 1])
            {
                ans = a[i];
                break;
            }
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(1)

// Most optimal approach - slow fast pointers
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// TC - O(n)  SC - O(1)

/*Most optimal approach is Floyd's Cycle Detection (Tortoise and Hare).
Why?
n+1 numbers
values in [1,n]
exactly one duplicate
cannot modify array
O(1) extra space
These constraints are specifically designed for Floyd's algorithm.
Observation
Treat array as a linked list:
next = nums[current]
Example:
[1,3,4,2,2]
0 -> 1
1 -> 3
3 -> 2
2 -> 4
4 -> 2
Graph:
0 -> 1 -> 3 -> 2 -> 4
               ^    |
               |____|
Duplicate number creates a cycle.*/