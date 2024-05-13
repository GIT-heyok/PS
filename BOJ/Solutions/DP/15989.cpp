#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll arr[10001];

int main() {
    FAST
    for (int i = 0; i <= 10000; ++i) {
        arr[i] = 1;
    }
    for (int i = 3; i <= 10000; ++i) {
        arr[i] = arr[i-3]+1;
    }

    ll sum = 0;
    for (int i = 0; i <= 10000 ; i+=2) {
        sum+=arr[i];
        arr[i]+=sum-arr[i];
    }
    sum = 0;
    for (int i = 1; i <= 10000 ; i+=2) {
        sum+=arr[i];
        arr[i]+=sum-arr[i];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout<<arr[n]<<endl;
    }
}
