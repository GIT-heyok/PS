#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<ll, ll>
int32_t mod = 1e9 + 7;


void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;
    if (n == 2)
        cout << max({2 * abs(a[0] - a[1]), a[0] + a[1]});
    else if (n == 3)
        cout << max({3 * (abs(a[0] - a[1])), 3 * (abs(a[2] - a[1])), 3 * a[0], 3 * a[2], a[0] + a[1] + a[2]});
    else
    {
        ll mx = 0;
        for (auto i : a)
            mx = max(i, mx);
        cout << n * mx;
    }
    cout<<'\n';
}

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    ll t = 0;
    cin >> t;
    while (t--)
        solve();
}