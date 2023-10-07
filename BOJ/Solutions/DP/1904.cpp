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
    int n;
    cin >> n;
    int memo[n+2];
    for (int i = 0; i < n + 1; ++i) {
        memo[i]=0;
    }
    memo[0]=1;
    for (int i = 0; i < n; ++i) {
        memo[i+1]+=memo[i];
        memo[i+2]+=memo[i];
        memo[i+1]%=15746;
        memo[i+2]%=15746;
    }
    cout<<memo[n]<<endl;
}

