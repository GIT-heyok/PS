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
//SUM SEG

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

struct segtree
{
    int n;
    vll a, t;
    segtree(int sz)
    {
        n = sz;
        a.resize(n);
        t.resize(4 * n);
    }

    void update(int ss, int se, int ii, int idx, ll value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if (ii > se || ii < ss)
            return;
        if (ii == ss && ss == se)
        {
            t[idx] = value;
            return;
        }
        int mid = (ss + se) / 2;
        update(ss, mid, ii, 2 * idx + 1, value);
        update(mid + 1, se, ii, 2 * idx + 2, value);
        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int ii, ll val)
    {
        update(0, n - 1, ii, 0, val);
    }

    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if (qs > se || qe < ss) // out of bound
            return 0;
        if (qs <= ss && qe >= se)
        {
            return t[idx];
        }
        int mid = (ss + se) / 2;
        return get(ss, mid, qs, qe, 2 * idx + 1) + get(mid + 1, se, qs, qe, 2 * idx + 2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int r)
    {
        return get(0, n - 1, l, r, 0);
    }
    void build(int ss, int se, int idx)
    {
        if (ss == se)
        {
            t[idx] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * idx + 1);
        build(mid + 1, se, 2 * idx + 2);
        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
    }

    /**interface to call build function*/
    void build()
    {
        build(0, n - 1, 0);
    }
};

int main()
{
    FAST

        int n;
    cin >> n;
    segtree s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s.a[i];
        s.a[i] = s.a[i] % 2;
    }
    s.build();
    int q;
    cin>> q;
    for (int i = 0; i < q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if(type==1){
            s.update(a-1, b%2);
        }
        else if(type==2){
            cout<< b-a+1-s.get(a-1,b-1) << endl;
        }
        else{
            cout<< s.get(a-1,b-1) << endl;
        }

    }
    
}
