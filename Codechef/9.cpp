/*Triple Threat

For a binary string A of length 3N, we define a new binary string f(A) of length N via the following rule:
For each index i (1≤i≤N), the i-th character of f(A) is the most frequent element among the three values (Ai, Ai+N, Ai+2N).
For example, if N=3 and A=010100110 then f(A)=110 because:
• The first character is the most frequent element among (A1,A4,A7)=(0,1,1), which is 1.
• The second character is the most frequent element among (A2,A5,A8)=(1,0,1), which is 1.
• The third character is the most frequent element among (A3,A6,A9)=(0,0,0), which is 0.
You're given two integers N and X. Find any binary string A of length 3N satisfying the following conditions:
• A contains exactly X ones and 3N−X zeros, and
• f(A) is lexicographically minimum across all strings satisfying the first condition.
If there are multiple valid strings, you may find any of them.
Note that you do not need to lexicographically minimize A, but rather find A that minimizes f(A).
We say a binary string P is lexicographically smaller than a binary string Q of the same length if and only if there exists an index i such that:
• Pj = Qj for each 1≤j<i, and
• Pi = 0 but Qi = 1.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of a single line of input, containing 2 space-separated integers N and X.

Output Format
For each test case, output on a new line the binary string A of length 3N that contains exactly X ones and lexicographically minimizes f(A).
If there are multiple valid solutions, any of them will be accepted.

Constraints
1≤T≤15250
1≤N≤100
0≤X≤3N

Sample Input
3
1 0
2 2
3 5

Sample Output
000
100001
011101001

Explanation
Test case 1:
We need a string of length 3 with 0 ones. The only choice is 000, so that's the answer.

Test case 2:
We need a string of length 6 with 2 ones. For A=100001 we have f(A)=00, which is clearly lexicographically minimum. So this A is a valid answer.

Test case 3:
We need a string of length 9 with 5 ones. For A=011101001 we have f(A)=001. It can be proved that we cannot obtain a lexicographically smaller value of f(A) under the given constraints.*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int one = x;
        int zero = 3 * n - x;
        string ans(3 * n, ' ');
        for (int i = 0; i < n; i++)
        {
            if (one == 0)
            {
                ans[i] = '0';
                ans[i + n] = '0';
                ans[i + 2 * n] = '0';
                zero -= 3;
            }
            else if (zero >= 2)
            {
                ans[i] = '0';
                ans[i + n] = '0';
                ans[i + 2 * n] = '1';
                zero -= 2;
                one--;
            }
            else if (zero == 1)
            {
                ans[i] = '0';
                ans[i + n] = '1';
                ans[i + 2 * n] = '1';
                zero--;
                one -= 2;
            }
            else
            {
                ans[i] = '1';
                ans[i + n] = '1';
                ans[i + 2 * n] = '1';
                one -= 3;
            }
        }
        cout << ans << "\n";
    }
}
// TC - O(n)  SC - O(n)