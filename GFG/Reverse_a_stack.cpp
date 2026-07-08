/*Reverse a Stack

You are given a stack st[]. You have to reverse the stack.
Note: The input array represents the stack from bottom to top (last element is the top). The output is displayed by printing elements from top to bottom after reversal.

Examples:

Input: st[] = [1, 2, 3, 4]
Output: [1, 2, 3, 4]
Explanation: After reversing, the elements of stack are in opposite order.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: After reversing, the elements of stack are in opposite order.*/

// This is the most optimal one but if it is needed to be done with recurssion   then at least we should know how to
class Solution
{
public:
    void reverseStack(stack<int> &st)
    {
        // code here
        queue<int> q;
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
    }
};
// TC - O(n)  SC - O(n)