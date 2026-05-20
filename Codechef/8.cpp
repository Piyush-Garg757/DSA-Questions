/*Magic Mirror

A long, long time ago, Chef found a pair of magic mirrors.
Naturally, he decided to play around with them to test their capabilities.
There are an infinite number of boxes arranged in a line.
The boxes are numbered:
1, 2, 3, …
from left to right.
Initially, all of these boxes are colored white.

First, Chef chose two integer positions X1 and X2 such that:
1 ≤ X1 < X2
and placed the mirrors at these two positions
Then, he performed the following operation several times:
Choose an integer d such that:
0 ≤ d < X1
and box:
X1 − d
is colored white.
Then, color box:
X1 − d
black.
The magic mirrors are linked, so this will cause box:
X2 + d
to also become colored black.

You have stumbled across this infinite line of boxes.
However, the only thing you can see is that there are N boxes colored black — namely, boxes:
A1, A2, …, AN
It is guaranteed that:
- N is even
- A1 < A2 < … < AN

Is it possible that this coloring is a result of Chef's experiment?
That is, does there exist a choice of (X1, X2) and then a sequence of coloring boxes that would result in exactly these N boxes being colored black?

Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer N — the number of boxes colored black.
The second line contains N space-separated integers:
A1, A2, …, AN

Output Format
For each test case, output on a new line the answer:
Yes — if it's possible for exactly these boxes to have been colored by the experiment
No — otherwise.
Each letter of the output may be printed in either uppercase or lowercase, i.e. the strings:
NO, No, nO, and no
will all be considered equivalent.

Constraints
1 ≤ T ≤ 2000
2 ≤ N ≤ 100
N is even.
1 ≤ A1 < A2 < … < AN ≤ 10^5

Sample 1
Input
4
2
3 5
4
1 2 3 4
4
1 3 4 5
6
3 4 6 7 9 10

Output
Yes
Yes
No
Yes

Explanation
Test case 1:
One possible solution is to choose:
X1 = 3
X2 = 5
and then choose:
d = 0
This will color the boxes:
X1 − d = 3 − 0 = 3
and
X2 + d = 5 + 0 = 5
exactly the two boxes required.

Test case 2:
One possible solution is to choose:
X1 = 2
X2 = 3
and then:
Choose d = 0, coloring boxes:
2 − 0 = 2
3 + 0 = 3
Choose d = 1, coloring boxes:
2 − 1 = 1
3 + 1 = 4
This results in exactly the four boxes:
1, 2, 3, 4
as required.

Test case 3:
It can be proved that no matter what we do, it's impossible to color exactly the set of boxes:
{1, 3, 4, 5}*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int b = 0;
        for (int i = 0; i < n / 2 - 1; i++)
        {
            if (abs(a[i] - a[i + 1]) != abs(a[n - i - 1] - a[n - 2 - i]))
            {
                b = 1;
                break;
            }
        }
        if (b == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
// TC - O(n/2)  SC - O(1)