#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int main() {    
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        ll mxm = 0;
        for (int i = n-1; i >= 0; i--)
        {
            mxm = max(mxm, arr[i]);
            ans+=mxm-arr[i];
        }
        cout<<ans<<endl;
        
    }
}