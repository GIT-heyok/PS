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
const int MAX = 51;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int n, m;
int arr[MAX][MAX];
int memo[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};

int dp(int r, int c){
    if(memo[r][c]!=-1)memo[r][c];

    if(visited[r][c])return inf;
    visited[r][c] = true;
    int cur = 1;
    int prev = 0;
    int val  = arr[r][c];
    for (int i = 0; i < 4; i++)
    {
        int nextr = r+dr[i]*val;
        int nextc = c+dc[i]*val;
        if(nextr>=0&&nextr<n&&nextc>=0&&nextc<m&&arr[nextr][nextc]!=-1){
            prev = max(dp(nextr, nextc),prev);
            visited[nextr][nextc] =false;
        }

    }
    if(prev>=inf)return inf;
    // cout<<r<<" "<<c<<" "<<cur+prev<<endl;
    return memo[r][c] = cur+prev;
    
}
int main()
{
    FAST
    cin >> n >> m;
    for (int i1 = 0; i1 < n; i1++)
    {
        string s;
        cin >> s;
        for (int i2 = 0; i2 < m; i2++)
        {
            if(s[i2]=='H')arr[i1][i2] = -1;
            else arr[i1][i2]=s[i2]-'0';
        }
    }
    for (int i3 = 0; i3 < n; i3++)
    {
        for (int i4 = 0; i4 < m; i4++)
        {
            memo[i3][i4] = -1;
            visited[i3][i4] = false;
        }
        
    }
    int ans = dp(0,0);
    if(ans>=inf)cout<<-1<<endl;
    else cout<<ans<<endl;

    
    
}