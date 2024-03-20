#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll MOD1 = 1e9+7;
ll MOD2 = 998244353;
ll digit = 400;
ll hashArr1[200001];
ll hashArr2[200001];
ll hashPow1[200001];
ll hashPow2[200001];

string s;
ll getHash1(int l, int r){
    return ((hashArr1[r]-hashArr1[l-1]*hashPow1[r-l+1])%MOD1+MOD1)%MOD1;
}
ll getHash2(int l, int r){
    return ((hashArr2[r]-hashArr2[l-1]*hashPow2[r-l+1])%MOD2+MOD2)%MOD2;
}

int main(void) {
    FAST
    int n;
    cin >> n;
    cin >> s;
    hashPow1[0] = 1;
    hashPow2[0] = 1;
    for (int i = 0; i < 200000; ++i) {
        hashPow1[i+1] = hashPow1[i]*digit;
        hashPow1[i+1]%=MOD1;

        hashPow2[i+1] = hashPow2[i]*digit;
        hashPow2[i+1]%=MOD2;
    }

    hashArr1[0] = 0;
    hashArr2[0] = 0;
    for (int i = 1; i <= n; ++i) {
        hashArr1[i] = hashArr1[i-1]*digit;
        hashArr1[i] += s[i-1];
        hashArr1[i] %= MOD1;

        hashArr2[i] = hashArr2[i-1]*digit;
        hashArr2[i] += s[i-1];
        hashArr2[i] %= MOD2;
    }

    int l = 1, r = n;
    int ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
//        cout<<mid<<endl;
        vector<pair<ll, ll>> vec;
        for (int i = 1; i+mid <= n+1 ; ++i) {
            ll h1 = getHash1(i, i+mid-1), h2 = getHash2(i, i+mid-1);
//            cout<<h1<<" "<<h2<<endl;
            pair<ll, ll> hh = {h1, h2};
            vec.push_back(hh);
        }
        sort(vec.begin(), vec.end());
        pair<ll, ll> abc = {-1, -1};
        bool chk = false;
        for (int i = 0; i<vec.size(); i++) {
            if(abc==vec[i]){
                chk = true;
                break;
            }
            else{
                abc = vec[i];
            }
        }

        
        if(chk){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<ans<<endl;

}

