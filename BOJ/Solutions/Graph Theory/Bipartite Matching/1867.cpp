#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int n, k;
vector<int> graph[501];
int d[501];
bool chk[501];

bool dfs(int here){
    if(chk[here])return false;
    chk[here] = true;

    for (int i = 0; i < graph[here].size(); ++i) {
        int nxt = graph[here][i];
        if(d[nxt]==0||dfs(d[nxt])){
            d[nxt] = here;
            return true;
        }
    }
    return false;
}

int main() {
    FAST
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int ans = 0;
    for (int i = 0; i < 501; ++i) {
        d[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 501; ++j) {
            chk[j] = false;
        }
        if(dfs(i))ans++;
    }
//    for (int i = 0; i < n; ++i) {
//        cout<<d[i+1]<<endl;
//    }
    cout<<ans<<endl;
}
