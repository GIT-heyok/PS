#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const ll MOD = 1e9+7;
ll digit = 256;

int main(void) {
    FAST
    string hay, needle;
    getline(cin, hay);
    getline(cin,needle);
    ll pow[1000002];
    pow[0] = 1;
    for (int i = 0; i < 1000000; ++i) {
        pow[i+1] = pow[i]*digit;
        pow[i+1]%=MOD;
    }
    ll hayHash[1000011];
    hayHash[0] = 0;
    for (int i = 0; i < hay.length(); ++i) {
        hayHash[i+1] = hayHash[i]*digit+hay[i];
        hayHash[i+1]%=MOD;
    }

    ll needleHash = 0;
    for (int i = 0; i < needle.length(); ++i) {
        needleHash*=digit;
        needleHash+=needle[i];
        needleHash%=MOD;
    }

    vector<int> ans;
    for (int idx = 1; idx <= 1+(int)hay.length()-(int)needle.length(); ++idx) {
        ll hayHashCur = ((hayHash[idx+needle.length()-1]-hayHash[idx-1]*pow[needle.length()])%MOD+MOD)%MOD;
        if(hayHashCur==needleHash){
            ans.push_back(idx);
        }
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<endl;
    }
}
