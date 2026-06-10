/*Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"*/

// My first approach
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string s = "";
        while (i >= 0 && j >= 0)
        {
            int digit = a[i] - '0' + b[j] - '0' + carry;
            if (digit == 0)
            {
                s.push_back('0');
                carry = 0;
            }
            else if (digit == 1)
            {
                s.push_back('1');
                carry = 0;
            }
            else if (digit == 2)
            {
                s.push_back('0');
                carry = 1;
            }
            else
            {
                s.push_back('1');
                carry = 1;
            }
            i--;
            j--;
        }
        while (i >= 0)
        {
            int digit = a[i] - '0' + carry;
            if (digit == 0)
            {
                s.push_back('0');
                carry = 0;
            }
            else if (digit == 1)
            {
                s.push_back('1');
                carry = 0;
            }
            else
            {
                s.push_back('0');
                carry = 1;
            }
            i--;
        }
        while (j >= 0)
        {
            int digit = b[j] - '0' + carry;
            if (digit == 0)
            {
                s.push_back('0');
                carry = 0;
            }
            else if (digit == 1)
            {
                s.push_back('1');
                carry = 0;
            }
            else
            {
                s.push_back('0');
                carry = 1;
            }
            j--;
        }
        if (carry == 1)
            s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};
// TC - O(max(m,n))  SC - O(max(m,n))

// Cleaner approach
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string s = "";
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            s.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
// TC - O(max(m,n))  SC - O(max(m,n))