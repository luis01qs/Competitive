# include <bits/stdc++.h>
# define ll long long
# define nl '\n'

using ld = long double;
using namespace std;

const int INF = 1e9;

class SegmentTree
{
public:
    int n;
    vector<int> a, st, lazy;
    
    int left(int p){ return (p << 1); }
    int right(int p) {return (p << 1) + 1;}

    void push(int p)
    {
        st[left(p)] += lazy[p];
        st[right(p)] += lazy[p];
        lazy[left(p)] += lazy[p];
        lazy[right(p)] += lazy[p];
        lazy[p] = 0;
    }

    void build(int p, int l , int r)
    {
        if( l == r ) st[p] = a[l];
        else
        {
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            st[p] = min(st[left(p)], st[right(p)]);
        }
    }

    int query(int p, int l, int r, int i, int j)
    {
        if(i > r || j < l) return INF;
        if(i <= l && j >= r) return st[p];

        push(p);

        int p1 = query(left(p), l, (l+r)/2, i, j);
        int p2 = query(right(p), (l+r)/2+1, r, i, j);

        return min(p1, p2);
    }

    void update(int p, int valor, int l, int r, int i, int j)
    {
        if(i > r || j < l) return;
        if(i <= l && j >= r) 
        {
            st[p] += valor;
            lazy[p] += valor;
            return;
        }

        push(p);
        update(left(p), valor, l, (l+r)/2, i, j);
        update(right(p), valor, (l+r)/2+1, r, i, j);
        st[p] = min(st[left(p)], st[right(p)]);
    }

    SegmentTree(vector<int> &A)
    {
        a = A;
        n = a.size();
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1);
    }

    int query(int i, int j){ return query(1, 0, n-1, i, j); }

    void update(int i, int j, int val) { update(1, val, 0, n-1, i, j); }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &e:a) cin>>e;

    SegmentTree st(a);
    
    int res = 0;
    for(int i=0;i<n;++i)
    {
        st.update(i, i,  k);
        if(i != 0) st.update(max(0, i-k), i-1, -1);
        res = max(res, st.query(0, n-1));
    }

    cout << res << nl;


    return 0;
}
