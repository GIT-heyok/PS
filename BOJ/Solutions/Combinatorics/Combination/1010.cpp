#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef __int128 ll;
int main(){
    FAST
    ll fac[31];
    fac[0] = 1;
    for (int i = 1; i <= 30; ++i) {
        fac[i] = fac[i-1]*i;
    }
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        cin >> a >> b;
        ll temp = fac[b]/fac[a]/fac[b-a];
        cout<< (long long)temp<<endl;
    }
}
