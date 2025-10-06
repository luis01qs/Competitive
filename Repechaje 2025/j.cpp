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

    int n = 10;
    set<int> a;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.insert(x);
    }

    cout << 4 - a.size() << nl;

    return 0;
}
