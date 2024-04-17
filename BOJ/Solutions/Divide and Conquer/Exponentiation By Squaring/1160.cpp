#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
ll m, a, c, x0, n, g;

ll mul(ll x, ll y) {
    if (!y) return 0;
    return (mul(x, y / 2) * 2 + (y & 1 ? x : 0)) % m;
}

struct st {
    ll a, b, c, d;

    st(ll _a, ll _b, ll _c, ll _d) : a(_a), b(_b), c(_c), d(_d) {}

    st operator*(st i) {
        return {(mul(a, i.a) + mul(b, i.c)) % m, (mul(a, i.b) + mul(b, i.d)) % m,
                (mul(c, i.a) + mul(d, i.c)) % m, (mul(c, i.b) + mul(d, i.d)) % m};
    }
};

st pow(ll x) {
    if (!x) return st(1, 0, 0, 1);
    st t = pow(x / 2);
    return t * t * (x & 1 ? st(a + 1, m - a % m, 1, 0) : st(1, 0, 0, 1));
}

int main() {
    cin >> m >> a >> c >> x0 >> n >> g;
    st t = pow(n);
    cout<<  (mul(t.c, mul(a, x0) + c) + mul(t.d, x0)) % m % g;
}
