/*Count Digit Appearances

You are given an integer array nums and an integer digit.
Return the total number of times digit appears in the decimal representation of all elements in nums.

Example 1:
Input: nums = [12,54,32,22], digit = 2
Output: 4
Explanation:
The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.

Example 2:
Input: nums = [1,34,7], digit = 9
Output: 0
Explanation:
The digit 9 does not appear in the decimal representation of any element in nums, so the total number of times digit 9 appears is 0.*/

class Solution
{
public:
    int countDigitOccurrences(vector<int> &a, int digit)
    {
        int count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            while (a[i])
            {
                if (a[i] % 10 == digit)
                    count++;
                a[i] /= 10;
            }
        }
        return count;
    }
};
// TC - O(nlogn)  SC - O(1)