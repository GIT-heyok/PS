#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int memo[1001];
int main() {
    FAST
    int n;
    cin >> n;
    for (int i = 2; i < 1001; ++i) {
        memo[i] = -1;
    }
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;

    int cur[1001];
    for (int i = 3; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            cur[j]  = 0;
        }

        for (int j = 0; j <= (i - 2); ++j) {
            cur[memo[j]^memo[i-2-j]] = 1;
        }
        for (int j = 0; j < i; ++j) {
            if(cur[j]==0){
                memo[i] = j;
                break;
            }
        }
    }
    if(memo[n]){
        cout<<1<<endl;
    }
    else cout<<2<<endl;
}