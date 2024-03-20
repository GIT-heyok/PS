#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
ll Z[500000];
int main(void) {
    FAST
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.length();
    Z[0] = 0;
    ll l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if(i < r){
            Z[i] = min(r-i,Z[i-l]);
        }
        while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]]){
            Z[i]++;
        }
        if(i+Z[i] > r){
            l = i;
            r = i+Z[i];
        }
    }
    ll overLap = 0;
    for (int i = 0; i < n; ++i) {
//        cout<<Z[i]<<" ";
        if(n-i==Z[i])
            overLap = max(Z[i], overLap);
    }

    cout<<n*k-overLap*(k-1)<<endl;
}

