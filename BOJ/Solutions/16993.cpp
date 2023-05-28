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
const int MAX = 1;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
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
            return -INF;
        if (qs <= ss && qe >= se)
        {
            return t[idx];
        }
        int mid = (ss + se) / 2;
        ll curSum = a[mid];
        ll sum1 = -INF;
        for (int i = mid-1; i>=ss&&i>=qs; i--)
        {
            curSum+=a[i];
            sum1 = max(sum1, curSum);
        }
        curSum = a[mid+1];
        ll sum2 = -INF;
        for (int i = mid+2; i<=se&&i<=qe; i++)
        {
            curSum+=a[i];
            sum2 = max(sum2, curSum);
        }
        ll ret =max(sum1+sum2,max(get(ss, mid, qs, qe, 2 * idx + 1), get(mid + 1, se, qs, qe, 2 * idx + 2)));
        return ret;
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
        ll curSum = a[mid];
        ll sum1 = -INF;
        for (int i = mid-1; i>=ss; i--)
        {
            curSum+=a[i];
            sum1 = max(sum1, curSum);
        }
        curSum = a[mid+1];
        ll sum2 = -INF;
        for (int i = mid+2; i<=se; i++)
        {
            curSum+=a[i];
            sum2 = max(sum2, curSum);
        }
        t[idx] = max(sum1+sum2, t[idx]);
        build(ss, mid, 2 * idx + 1);
        build(mid + 1, se, 2 * idx + 2);
        t[idx] = max(t[2 * idx + 1],t[2 * idx + 2]);
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
        
    }
    
    s.build();
    int q;
    cin>> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout<<s.get(a-1, b-1)<<endl;
    }
    
}
