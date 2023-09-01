#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int main()
{
    FAST
    ll W, H, f, c, x1, y1, x2, y2;
    cin >> W >> H >>f>> c>> x1>> y1>> x2>> y2;
    ll M = f>W/2?W-f:f;
    ll ans = W*H-(c+1)*(y2-y1)*(x2-x1+min(max(M-x1,0ll),x2-x1));
    cout<<ans<<endl;
}