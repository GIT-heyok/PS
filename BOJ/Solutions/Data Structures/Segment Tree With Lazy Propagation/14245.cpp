#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

struct SegTreeLazy{
    int n;
    vector<ll> a , t, lazy;
    SegTreeLazy(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
        lazy.resize(4*n);
    }
    void propagate(int ss ,int se, int idx)
    {
        t[idx] ^= (se-ss+1)%2==0?0:lazy[idx];
        if(ss!=se)
        {
            int mid = (ss+se)/2;
            lazy[2*idx+1] ^= lazy[idx];
            lazy[2*idx+2] ^= lazy[idx];
        }
        lazy[idx] = 0 ;
    }

    void update(int ss, int se, int qs, int qe, int idx ,ll value)
    {
        if(lazy[idx]!=0)
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return;
        if(qs<=ss && qe>=se)
        {
            lazy[idx] = value;
            propagate(ss, se, idx);
            return ;
        }
        int mid = (ss+se)/2;
        update(ss, mid , qs, qe, 2*idx+1 , value);
        update(mid+1, se, qs ,qe ,2*idx+2 , value);
        t[idx] = t[2*idx+1] ^ t[2*idx+2];
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int l, int r, ll val)
    {
        update(0 , n-1, l, r, 0 , val);
    }

    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(lazy[idx]!=0)
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return 0;
        if(qs<=ss && qe>=se)
            return t[idx];

        int mid = (ss+se)/2;
        return get(ss, mid, qs ,qe , 2*idx+1) ^ get(mid+1 , se, qs , qe, 2*idx+2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int r)
    {
        return get(0 , n-1, l , r , 0);

    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            t[idx] = a[ss];
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        t[idx] = t[2*idx+1] ^ t[2*idx+2];
    }

    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }

};

int main(void) {
    FAST
    int n;
    cin >> n;
    SegTreeLazy seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg.a[i];
    }
    seg.build();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if(type==1){
            ll a, b, c;
            cin >> a>> b >> c;
            seg.update(a, b, c);
        }
        else{
            ll val;
            cin >> val;
            cout<<seg.get(val,val)<<endl;
        }
    }
}
