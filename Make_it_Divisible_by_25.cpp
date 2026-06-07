

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int steps = 0;
        int a = 1;
        bool first_0 = false, second_0 = false, first_5 = false, second_5 = false, second_2 = false, second_7 = false;
        while (n && a != -1)
        {
            int ld = n % 10;
            if (ld == 0)
            {
                if (first_0 == false)
                    first_0 = true;
                else
                    second_0 = true;
            }
            else if (ld == 5)
            {
                if (first_5 == false)
                    first_5 = true;
                else
                    second_5 = true;
            }
            else if (ld == 7)
                second_7 = true;
            else if (ld == 2)
                second_2 = true;
            if (second_0 == true || (first_5 == true && (second_2 == true || second_7 == true)))
                a = -1;
            else
                steps++;
            n /= 10;
        }
        cout << steps << "\n";
    }
}