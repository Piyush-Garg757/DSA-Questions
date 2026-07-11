/*Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]*/

// My first approach - ekdum bekar approach
class Solution
{
public:
    vector<int> majorityElement(vector<int> &a)
    {
        int n = a.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[a[i]]++;
        }
        vector<int> ans;
        for (auto i : mpp)
        {
            if (i.second > n / 3)
                ans.push_back(i.first);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Optimal approach
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0, count2 = 0;         // Counters for the potential majority elements
        int candidate1 = 0, candidate2 = 0; // Potential majority element candidates
        // First pass to find potential majority elements.
        for (int i = 0; i < nums.size(); i++)
        {
            // If count1 is 0 and the current number is not equal to candidate2, update candidate1.
            if (count1 == 0 && nums[i] != candidate2)
            {
                count1 = 1;
                candidate1 = nums[i];
            }
            // If count2 is 0 and the current number is not equal to candidate1, update candidate2.
            else if (count2 == 0 && nums[i] != candidate1)
            {
                count2 = 1;
                candidate2 = nums[i];
            }
            // Update counts for candidate1 and candidate2.
            else if (candidate1 == nums[i])
            {
                count1++;
            }
            else if (candidate2 == nums[i])
            {
                count2++;
            }
            // If the current number is different from both candidates, decrement their counts.
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> result;
        int threshold = nums.size() / 3; // Threshold for majority element
        // Second pass to count occurrences of the potential majority elements.
        count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (candidate1 == nums[i])
            {
                count1++;
            }
            else if (candidate2 == nums[i])
            {
                count2++;
            }
        }
        // Check if the counts of potential majority elements are greater than n/3 and add them to the result.
        if (count1 > threshold)
        {
            result.push_back(candidate1);
        }
        if (count2 > threshold)
        {
            result.push_back(candidate2);
        }
        return result;
    }
};
// TC - O(n)  SC - O(1)

// Intution - Since we have to find elements appearing more than n/3   there can  be atmost 2 elements   so we use boyre moore voting algorithm for 2 elements
/*This algorithm can be used to return the highest K elements that appeared in the array more than array_size/(K+1) times. In our case, K = 2.
The major Intuition behind this algorithm is that maintaining voting variable for the candidates:
Increase the variable if you faced the candidate in your iteration.
Decrease the variable if you faced another element.
If the variable reaches 0, look for another promising candidate.*/