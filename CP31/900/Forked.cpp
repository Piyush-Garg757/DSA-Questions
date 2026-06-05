

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        int position = 0;
        int y_diff = abs(yk - yq);
        int x_diff = abs(xk - xq);
        if (xk == xq && (y_diff == 2 * a || y_diff == 2 * b))
            position = 2;
        else if (yk == yq && (x_diff == 2 * a || x_diff == 2 * b))
            position = 2;
        else
        {
            if ((y_diff == 2 * a && x_diff == 2 * b) || (x_diff == 2 * a || y_diff == 2 * b))
                position = 1;
            else if (x_diff == a + b && y_diff == a + b)
                position = 2;
        }
        cout << position << "\n";
    }
}