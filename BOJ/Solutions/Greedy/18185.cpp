#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'

typedef long long ll;



int main(void) {
    FAST

    ll n, b, c;
//    cin >> n >> b >> c;
    cin >> n;
    b = 3;
    c = 2;
    if(b>c){
        ll ans = 0;
        ll arr[n+2];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        arr[n]= 0;
        arr[n+1]= 0;

        for (int i = 0; i <n; ++i) {
            if(arr[i+1]>arr[i+2]){
                ll mnm2 = min(arr[i], arr[i+1]-arr[i+2]);
                ans += (b+c)*mnm2;
                arr[i]-=mnm2;
                arr[i+1]-=mnm2;

                ll mnm = min(arr[i], min(arr[i+1], arr[i+2]));
                arr[i]-=mnm;
                arr[i+1]-=mnm;
                arr[i+2]-=mnm;
                ans += mnm*(b+c+c);
            }
            else{
                ll mnm = min(arr[i], min(arr[i+1], arr[i+2]));
                arr[i]-=mnm;
                arr[i+1]-=mnm;
                arr[i+2]-=mnm;
                ans += mnm*(b+c+c);

                ll mnm2 = min(arr[i], arr[i+1]);
                ans += (b+c)*mnm2;

                arr[i]-=mnm2;
                arr[i+1]-=mnm2;
            }
            ans+=arr[i]*b;
        }
        cout<<ans<<endl;
    }
    else{
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll temp;
            cin >> temp;
            ans+=temp*b;
        }
        cout<<ans<<endl;
    }
}
