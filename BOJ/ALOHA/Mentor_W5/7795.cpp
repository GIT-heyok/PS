#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n' // \n도 써줘야함.
// 7795 먹을 것인가 먹힐 것인가
int main(void) {
    FAST // 빠른 입출력 구현 해 주어야 함.
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        int INF = 2147483647;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            //범위 내의 개수 구하기 : (b, INF]
            ans+= (upper_bound(a.begin(), a.end(), INF)- lower_bound(a.begin(), a.end(), b[i]+1));
        }
        cout<<ans<<endl;
    }
}
