#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
ll MOD = 1e+9;
ll digit = 400;
ll H[500001];
ll P[500001];
ll getHash(int l, int r){
    return ((H[r]-H[l-1]*P[r-l+1])%MOD+MOD)%MOD;
}
int main(void) {
    FAST
    string s;
    ll n;
    cin >> s >> n;
    P[0] = 1;
    for (int i = 0; i < 500000; ++i) {
        P[i+1] = P[i]*digit;
        P[i+1]%=MOD;
    }
    for (int i = 0; i < s.length(); ++i) {
        H[i+1] = (H[i]*digit+s[i])%MOD;
    }
    ll same = 0;
    for (int i = s.length()-1; i >= 1; --i) {
        if(getHash(1,i)== getHash(s.length()-i+1, s.length())){
            bool chk = true;
            for (int j = 0; j < i-1; ++j) {
                if(s[j]!=s[s.length()-i+j]){
                    chk = false;
                }
            }
            if(chk){
                same = i;
                break;
            }
        }
    }
    cout<< n*s.length()-same*(n-1)<<endl;

}

