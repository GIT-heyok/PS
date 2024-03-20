#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
bool dp[2][200001];
bool arrIsLeft[2][200001];
int n;
int dr[4] = {0,0,-1,1};
int dc[4] = {1,-1,0,0};
void dfs(int r, int c){
    if(!dp[r][c]){
        dp[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0&&nr<2&&nc>=0&&nc<n){
                if(arrIsLeft[nr][nc]){
                    nc--;
                }
                else{
                    nc++;
                }
                if(nc>=0&&nc<n){
                    dfs(nr, nc);
                }
            }
        }
    }
}
int main(void) {
    FAST
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j) {
                arrIsLeft[i][j] = s[j]=='<';
                dp[i][j] = 0;
            }
        }

        dfs(0,0);
        if(dp[1][n-1]){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
}
