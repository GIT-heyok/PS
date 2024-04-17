#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

ll dp[10][2001];

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j/2]; // j/2보다 작은 수들로는 만들 수 있다.
            }
            for (int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i][j-1]; // prefix sum으로 변경
            }
        }

//        for (int i = 0; i < n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<dp[n-1][m]<<endl;

    }
}
