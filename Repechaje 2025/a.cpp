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

    int n, m;
    cin>>n>>m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for(auto &e:a) for(auto &u:e) cin>>u;

    ll res = 0;
    for(int j=0;j<m;++j) 
    {
        ll cont = 0;
        for(int i=0;i<n;++i) cont = max(cont, a[i][j]);
        res += cont;
    }

    cout << res << nl;

    return 0;
}
