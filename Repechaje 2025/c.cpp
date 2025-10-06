# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using ld = long double;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int x = 0;
    for(int i=n;i>=0;--i)
    {
        int a;
        cin>>a;
        
        x |= (a << i);
    }

    int cont = 0;
    while(true)
    {
        if(x == 1) break;

        if(x & 1) x = x ^ (x << 1) ^ 1;
        else x = (x >> 1);

        cont++;
    }

    cout << cont << nl;


    return 0;
}
