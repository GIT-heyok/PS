#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

const ll MOD = 1e9+7;
struct SegTreeLazy{
    int n;
    vector<ll> a , t;
    vector<pair<ll,ll>> lazy;
    SegTreeLazy(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
        lazy.resize(4*n);
    }
    void propagate(int ss ,int se, int idx)
    {
        if(!(lazy[idx].first==1&&lazy[idx].second==0)){
            t[idx] = t[idx]*lazy[idx].first+lazy[idx].second*(se-ss+1);
            t[idx]%=MOD;
        }

        if(ss!=se)
        {
            lazy[2*idx+1].first*=lazy[idx].first;
            lazy[2*idx+1].first%=MOD;
            lazy[2*idx+1].second*=lazy[idx].first;
            lazy[2*idx+1].second+=lazy[idx].second;
            lazy[2*idx+1].second%=MOD;

            lazy[2*idx+2].first*=lazy[idx].first;
            lazy[2*idx+2].first%=MOD;
            lazy[2*idx+2].second*=lazy[idx].first;
            lazy[2*idx+2].second+=lazy[idx].second;
            lazy[2*idx+2].second%=MOD;
        }
        lazy[idx]={1,0};
    }

    void update(int ss, int se, int qs, int qe, int idx , ll a, ll b)
    {
        if(!(lazy[idx].first==1&&lazy[idx].second==0))
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return;
        if(qs<=ss && qe>=se)
        {
            lazy[idx].first *= a;
            lazy[idx].first %= MOD;
            lazy[idx].second *= a;
            lazy[idx].second %= MOD;
            lazy[idx].second += b;
            lazy[idx].second %= MOD;
            propagate(ss, se, idx);
            return ;
        }
        int mid = (ss+se)/2;
        update(ss, mid , qs, qe, 2*idx+1 , a, b);
        update(mid+1, se, qs ,qe ,2*idx+2 , a, b);
        t[idx] = (t[2*idx+1] + t[2*idx+2])%MOD;
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int l, int r, ll a, ll b)
    {
        update(0 , n-1, l, r, 0 , a, b);
    }

    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(!(lazy[idx].first==1&&lazy[idx].second==0))
            propagate(ss, se, idx);
        if(qs>se || qe<ss)
            return 0;
        if(qs<=ss && qe>=se)
            return t[idx];

        int mid = (ss+se)/2;
        return (get(ss, mid, qs ,qe , 2*idx+1) + get(mid+1 , se, qs , qe, 2*idx+2))%MOD;
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
        t[idx] = (t[2*idx+1] + t[2*idx+2])%MOD;
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
    for (int i = 0; i < 4 * n; ++i) {
        seg.lazy[i] = {1,0};
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
            seg.update(a-1, b-1, 1,c);
        }
        else if(type==2){
            ll a, b, c;
            cin >> a>> b >> c;
            seg.update(a-1, b-1, c,0);
        }
        else if(type==3){
            ll a, b, c;
            cin >> a>> b >> c;
            seg.update(a-1, b-1, 0,c);
        }
        else{
            ll l, r;
            cin >> l>> r;
            cout<<seg.get(l-1,r-1)<<endl;
        }
    }
}
