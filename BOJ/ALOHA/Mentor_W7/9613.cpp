#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
// 9613 GCD 합
int main() {
    FAST
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                // GCD는 똑똑한 사람들이 이미 구현해놓았습니다.
                sum += __gcd(arr[i], arr[j]);
            }
        }
        cout<<sum<<endl;
    }
}
