/*Add Strings
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"*/

// My approach    complex
class Solution
{
public:
    string addStrings(string s1, string s2)
    {
        string s;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int ans = 0, carry = 0;
        while (i >= 0 && j >= 0)
        {
            ans = (s1[i] - '0') + (s2[j] - '0') + carry;
            if (ans >= 10)
            {
                ans -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s.push_back('0' + ans);
            i--;
            j--;
        }
        while (i >= 0)
        {
            ans = (s1[i] - '0') + carry;
            if (ans >= 10)
            {
                ans -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s.push_back('0' + ans);
            i--;
        }
        while (j >= 0)
        {
            ans = (s2[j] - '0') + carry;
            if (ans >= 10)
            {
                ans -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            s.push_back('0' + ans);
            j--;
        }
        if (carry)
            s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};
// TC - O(max(n,m))  SC - O(max(n,m))

// Slightly cleaner approach
class Solution
{
public:
    string addStrings(string s1, string s2)
    {
        string ans;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += s1[i--] - '0';
            if (j >= 0)
                sum += s2[j--] - '0';

            ans.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// TC - O(max(n,m))  SC - O(max(n,m))