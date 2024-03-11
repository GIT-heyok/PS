#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
ll tree[5050][5050];

void update(ll x, ll y, ll v){
    for(int xx = x+1; xx<5050; xx+=xx&-xx) for(ll yy=y+1; yy<5050; yy+=yy&-yy) tree[xx][yy] += v;
}
ll query(ll x, ll y){
    ll ret = 0;
    for(int xx = x+1; xx; xx-=xx&-xx) for(ll yy=y+1; yy; yy-=yy&-yy) ret += tree[xx][yy];
    return ret;
}

int main(){
    FAST
    ll n, m, q; cin >> n >> m >> q;
    while(q--){
        ll op; cin >> op;
        if(op == 1){
            ll a, b, c, d, e; cin >> a >> c >> b >> d >> e;
            update(a, c, e); update(b+1, d+1, e);
            update(b+1, c, -e); update(a, d+1, -e);
        }else{
            ll a, b; cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }
}