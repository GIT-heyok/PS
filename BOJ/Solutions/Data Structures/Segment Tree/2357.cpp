#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;
const int MAX = 200005;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e9 + 7;

struct segtree{
    int n;
    vector<ll> a;
    vector<pLL> t;
    segtree(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
    }
    
    void update(int ss, int se, int ii, int idx ,ll value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if(ii>se || ii<ss)
            return;
        if(ii==ss&&ss==se){
            t[idx].first = value;
            t[idx].second= value;
            return;
        }
        int mid = (ss+se)/2;
        update(ss, mid , ii, 2*idx+1 , value);
        update(mid+1, se, ii ,2*idx+2 , value);
        t[idx].first = min(t[2*idx+1].first, t[2*idx+2].first);
        t[idx].second = min(t[2*idx+1].second, t[2*idx+2].second);
    }
    
    /**interface to call update function
     * l and r in this function is 0-indexed 
     */
    void update(int ii, ll val)
    {
        update(0 , n-1, ii, 0 , val);
    }
    
    pLL get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return {INF,0};
        if(qs<=ss&&qe>=se){
            return t[idx];
        }
        int mid = (ss+se)/2;
        pLL a = get(ss,mid,qs,qe, 2*idx+1);
        pLL b = get(mid+1,se,qs,qe, 2*idx+2);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    
    /**interface to call get function
     * l and r in this function is 0-indexed 
     */
    pLL get(int l, int  r)
    {
		return get(0 , n-1, l, r , 0); 
        
    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            t[idx] = {a[ss],a[ss]};
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        t[idx]= {min(t[2*idx+1].first, t[2*idx+2].first), max(t[2*idx+1].second, t[2*idx+2].second)};
    }
    
    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }
		
};



int main() {
    FAST
    int n, q;
    cin >> n >> q;
    segtree s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s.a[i];
    }
    
    s.build();
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a>> b;
        cout<<s.get(a-1,b-1).first<<" "<<s.get(a-1,b-1).second<<endl;
    }
    
}

