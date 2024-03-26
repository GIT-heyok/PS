#include <bits/stdc++.h>
#include <algorithm>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'

typedef long long ll;

const ll MXM = 2e9;
bool isNotPrime[500000];
int main(void) {
    FAST
    ll k;
    cin >> k;
    for (ll i = 2; i*i*i*i <= MXM; ++i) {
        if(!isNotPrime[i]){
            for (ll j = i*i; j*j <=MXM; j+=i) {
                isNotPrime[j] = true;
            }
        }
    }
    vector<ll> primeSquared;
    for (ll i = 2; i*i <= MXM; ++i) {
        if(!isNotPrime[i]){
            primeSquared.push_back(i*i);
        }
    }

    vector<ll> vec[7];
    vec[0].push_back(1);
    for (int i = 0; i < primeSquared.size(); ++i) {
        for (int j = 6; j >= 0; --j) {
            for (int m = 0; m < vec[j].size(); ++m) {
                if(vec[j][m]<=MXM/primeSquared[i])
                    vec[j+1].push_back(vec[j][m]*primeSquared[i]);
            }
        }
    }

    ll ans = 0;

    ll l = 1, r = MXM;
    while(l<=r){
        ll mid = (l+r)/2;
        ll notPrimes = 0;
        for (int i = 1; i <= 6; ++i) {
            for (int j = 0; j < vec[i].size(); ++j) {
                if(i%2==1){
                    notPrimes+=mid/vec[i][j];
                }
                else{
                    notPrimes-=mid/vec[i][j];
                }
            }
        }
//        cout<<mid<<" "<<mid-notPrimes<<endl;
        if(mid-notPrimes>=k){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    if(ans!=1&&floor(sqrt(ans))*floor(sqrt(ans))==ans){
        ans--;
    }
    else{
        cout<<ans<<endl;
    }
}
