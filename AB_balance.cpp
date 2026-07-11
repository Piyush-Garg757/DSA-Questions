

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ab = 0, ba = 0, n = s.length();
        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] == 'a' && s[i + 1] == 'b')
                ab++;

            if (s[i] == 'b' && s[i + 1] == 'a')
                ba++;
        }
        if (ab == ba)
            cout << s << "\n";
        else
        {
            if (ab > ba)
            {
                if (s[0] == 'a' && s[1] == 'b')
                {
                    s[0] = 'b';
                    ab--;
                }
                if (ab == ba)
                    break;
                if (s[n - 2] == 'a' && s[n - 1] == 'b')
                {
                    s[n - 1] = 'a';
                    ab--;
                }
                if (ab == ba)
                    break;
                for (int i = 1; i < n - 2; i++)
                {
                    if (s[i] == 'a' && s[i + 1] == 'b')
                    {
                        if (i < n - i - 1)
                        {
                            for (int j = i; j >= 0; j--)
                                s[j] = 'b';
                        }
                        else
                        {
                            for (int j = i + 1; j < n; j++)
                                s[j] = 'b';
                        }
                    }
                }
            }
            else
            {

                if (s[0] == 'b' && s[1] == 'a')
                {
                    s[0] = 'a';
                    ba--;
                }
                if (ab == ba)
                    break;
                if (s[n - 2] == 'b' && s[n - 1] == 'a')
                {
                    s[n - 1] = 'b';
                    ba--;
                }
                if (ab == ba)
                    break;
                for (int i = 1; i < n - 2; i++)
                {
                    if (s[i] == 'b' && s[i + 1] == 'a')
                    {
                    }
                }
            }
            cout << s << "\n";
        }
    }
}