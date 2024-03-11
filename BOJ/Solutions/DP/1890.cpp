#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
int n;
long long memo[100][100];
int arr[100][100];
int dr[2] = {0,1};
int dc[2] = {1,0};

long long dfs(int r, int c){
    if(memo[r][c]!=-1){
        return memo[r][c];
    }
    long long & temp = memo[r][c] = 0;
    for (int i = 0; i < 2; ++i) {
        int nxtR =r+dr[i]*arr[r][c];
        int nxtC =c+dc[i]*arr[r][c];
        if(nxtR<n&&nxtC<n){
            temp += dfs(nxtR, nxtC);
        }
    }
    return temp;
}
int main(){
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            memo[i][j] = -1;
        }
    }
    memo[n-1][n-1] = 1;
    cout<<dfs(0,0)<<endl;
}
