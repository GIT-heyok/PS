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
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j]-'0';
        }
    }
    int path[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            path[i][j] = inf;
        }
    }
    
    path[0][0]=1;
    queue<pI> q;
    q.push({0,0});
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&arr[nr][nc]&&path[nr][nc]>path[r][c]+1){
                path[nr][nc] = path[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    cout<<path[n-1][m-1]<<endl;
}