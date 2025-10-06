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
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;++i)
    {
        int x, y;
        cin>>x>>y;
        a[i] = {x, y};
    }

    vector<int> d(n-1);
    for(int i=0;i<n-1;++i)
    {
        if(a[i].first == a[i+1].first) d[i] = abs(a[i].second - a[i+1].second);
        else d[i] = abs(a[i].first - a[i+1].first);
    }

    pair<int, int> res = {1, 1e9};
    for(int i=n-2;i>=-1;--i)
    {
        if(res.first > res.second || (i != -1 && d[i] == 0))
        {
            cout << -1 << nl;
            return 0;
        }
        

        pair<int, int> next;
        if(i == n-2) next = {1, d[i]-1};
        else
        {
            next = {max(1, -res.second +  d[i+1]),  d[i+1] - res.first};
        }

        res = next;

    }

    if(res.first > res.second) cout << -1 << nl;
    else cout << res.second << nl;

    return 0;
}
