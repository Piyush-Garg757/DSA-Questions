

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
        int ab = 0, ba = 0;
        for (int i = 0; i + 1 < s.length(); i++)
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
                for (int i = 0; i < s.length() - 1; i++)
                {
                    if (s[i] == 'a' && s[i + 1] == 'b' && (i == 0 || s[i - 1] != 'b'))
                    {
                        s[i] = 'b';
                        ab--;
                        if (ab == ba)
                            break;
                    }
                }
            }
            else
            {
                for (int i = 0; i + 1 < s.length(); i++)
                {
                    if (s[i] == 'b' && s[i + 1] == 'a' && (i == 0 || s[i - 1] != 'a'))
                    {
                        s[i] = 'a';
                        ba--;
                        if (ab == ba)
                            break;
                    }
                }
            }
            cout << s << "\n";
        }
    }
}