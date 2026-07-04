/*Good times Good times

An integer n is said to be good if it contains at most two distinct digits in its decimal representation. For example, the integers 3, 8588, 67 are good, whereas the integers 123, 9447 are not.
You are given an integer x (1≤x<10^8), which is good. Your task is to find an integer y (2≤y≤10^9) such that both of the following conditions are satisfied:
• y is good.
• x×y is good.

Input
The first line contains an integer t (1≤10^4) — the number of test cases. The description of each test case follows.
Each test case contains a single integer x (1≤x<10^8). It is guaranteed that x is good.

Output
For each test case, print a single integer y (2≤y≤10^9) such that both the integers y and x×y are good.
If there are multiple valid answers, output any one of them.

Example

Input
4
8
73
299
6767

Output
11
4
26
3366
Note
For the first test case, we have x=8; choosing y=11 is valid because both y=11 and x×y=88 are good.
For the second test case, we have x=73; choosing y=4 is valid because both y=4 and x×y=292 are good.*/

/*🔥 Mind-blowing observation 🔥

Since x is already guaranteed to be GOOD (contains at most 2 distinct digits),
we need to find another GOOD number y such that x * y is also GOOD.

------------------------------------------------------------
Why isn't y = 1 allowed?
------------------------------------------------------------

If y = 1 were allowed, the answer would always be 1 because

x * 1 = x

and x is already GOOD.

So the problem deliberately sets

2 <= y <= 10^9

forcing us to think of another construction.

------------------------------------------------------------
Key Observation
------------------------------------------------------------

Suppose x has d digits.

Take

        y = 10^d + 1

Examples

x = 8        (d = 1)

y = 11

8 × 11 = 88


-----------------------

x = 73       (d = 2)

y = 101

73 × 101 = 7373


-----------------------

x = 299      (d = 3)

y = 1001

299 × 1001 = 299299


------------------------------------------------------------
Why does this always work?
------------------------------------------------------------

10^d + 1

means

1000...001

So

x × (10^d + 1)

= x × 10^d + x

The first term shifts x by d digits.

Then adding x simply appends another copy of x.

Example

121 × 1001

= 121000 + 121

= 121121

Because exactly d zeroes are inserted,
there is no carry between the two copies.

Thus

x × (10^d + 1)

is just x written twice.

Since x contains at most two distinct digits,

x repeated twice also contains at most two distinct digits.

Hence

• y is GOOD
• x × y is GOOD

------------------------------------------------------------
Construction
------------------------------------------------------------

Let d = number of digits in x.

Answer:

        y = 10^d + 1

Works for every test case.

Complexity:
O(number of digits) = O(1)

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        long long p = 1;
        long long temp = x;

        while (temp)
        {
            p *= 10;
            temp /= 10;
        }

        cout << p + 1 << "\n";
    }

    return 0;
}