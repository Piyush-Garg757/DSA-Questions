

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if ((x == 1 && n % 2 != 0 && k < n) || (x == 1 && k == 1))
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            if (x != 1)
            {
                cout << n << "\n";
                for (int i = 0; i < n; i++)
                    cout << "1 ";
                cout << "\n";
            }
            else if (n % 2 == 0)
            {
                cout << n / 2 << "\n";
                for (int i = 0; i < n; i = i + 2)
                    cout << "2 ";
                cout << "\n";
            }
            else
            {
                cout << "1\n";
                cout << n << "\n";
            }
        }
    }
}