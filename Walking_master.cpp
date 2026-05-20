

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a,b,c,d,count=0;
        cin>>a>>b>>c>>d;
        if(d<b) cout<<"-1\n";
        else
        {
            if(d>b)
            {
                long long diff = d-b;
                a+=diff;
                b+=diff;
                count+=diff;
            }
            if(c>a) cout<<"-1\n";
            else
            {
                count+=a-c;
                cout<<count<<"\n";
            }
        }
    }
}