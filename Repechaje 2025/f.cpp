# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using ld = long double;
using namespace std;

ll M = 1e9 + 7;

ll modexp(ll a, ll e)
{
    ll r = 1;
    a %= M;

    while(e)
    {
        if(e & 1) r = (r * a) % M;
        a = (a * a) % M;
        e >>= 1;
    }

    return r;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    vector<ll> a(q);
    for(auto &e:a) cin>>e;

    vector<pair<ll, ll>> prob(q+1, pair<ll, ll>({0, 1}));
    vector<pair<ll, ll>> res(n, pair<ll, ll>{0,0});
    
    for(int i=q-1;i>=0;--i)
    {
        prob[i].second = (prob[i+1].second) * 2; 
        prob[i].second %= M;

        prob[i].first = (prob[i+1].first + (a[i] * prob[i+1].second) % M) % M;
    }

    ll extra = 1;
    prob[0].second *= 2;
    for(int i=0;i<q;i++)
    {
        prob[i].first = (prob[i].first * extra) % M;
        extra *= 2;
        extra %= M;

        prob[i].second = prob[0].second % M;
    }

    int actual = 0;
    extra = 1;
    for(int i=0;i<q;++i)
    {
        if(i != 0) res[actual].first += (prob[i].first);
        else res[actual].first += prob[i].first * 2;
        res[actual].first %= M;

        actual = a[i] - 1;
    }

    for(int i=0;i<n;++i) res[i].second = prob[0].second;


    for(int i=0;i<n;++i)
    {
        ll gcd = __gcd(res[i].first, res[i].second);
        res[i].first /= gcd;
        res[i].second /= gcd;
        ll qinv = modexp(res[i].second, M-2);
        ll ans = (res[i].first * qinv) % M;
        cout << ans << nl;
    }
    cout << nl;
 

    return 0;
}
