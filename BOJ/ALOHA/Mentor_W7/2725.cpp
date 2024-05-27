#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
bool arr[1001][1001];
int ans[1001];
// 2725 보이는 점의 개수
int main() {
    FAST
    // base case
    ans[0] = 2;
    for (int i = 1; i <= 1000; ++i) {
        ans[i] = ans[i-1];
        for (int j = 1; j <= i; ++j) {
            int gcd = __gcd(i, j);
            if(!arr[i/gcd][j/gcd]){
                ans[i]++;
            }
            arr[i/gcd][j/gcd] = true;
        }
        for (int j = 1; j <= i; ++j) {
            int gcd = __gcd(i, j);
            if(!arr[j/gcd][i/gcd]){
                ans[i]++;
            }
            arr[j/gcd][i/gcd] = true;
        }
    }
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        cout<<ans[n]<<endl;
    }

}
