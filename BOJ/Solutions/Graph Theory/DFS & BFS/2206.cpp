#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;
const int MAX = 100000;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
int main()
{
    FAST
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int k = 1;
    int dist[k+1][n][m];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j]-'0';
        }
    }
    fill(&dist[0][0][0], &dist[k][n-1][m], inf);
    queue<pI> q;
    dist[0][0][0] = 1;
    q.push({0,0});
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        // cout<<r<<" "<<c<<endl;
        for (int i = 0; i < 4; i++)
        {
            int nxtR = r+dr[i];
            int nxtC = c+dc[i];
            if(nxtR>=n||nxtR<0||nxtC>=m||nxtC<0)continue;
            bool chk = false;
            for (int curK = 0; curK <= k; curK++)
            {
                if(arr[nxtR][nxtC]){ //met a wall
                    if(curK+1<=k&&dist[curK+1][nxtR][nxtC]>dist[curK][r][c]+1){
                        chk = true;
                        dist[curK+1][nxtR][nxtC] = dist[curK][r][c] + 1;
                    }       
                }
                else{
                    if(dist[curK][nxtR][nxtC]>dist[curK][r][c]+1){
                        chk = true;
                        dist[curK][nxtR][nxtC] = dist[curK][r][c]+1;
                    }
                }
            }
            if(chk)q.push({nxtR,nxtC});
        }
        
    }
    int ans = min(dist[0][n-1][m-1], dist[1][n-1][m-1]);
    if(ans>=inf)cout<<-1<<endl;
    else cout<<ans<<endl;
}