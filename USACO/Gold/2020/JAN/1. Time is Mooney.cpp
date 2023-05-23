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
const int MAX = 4000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

 
int main()
{
    FAST
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    ll cost[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    ll ans = 0;
    ll dp[1001][n+1];
    fill(&dp[0][0], &dp[1000][n+1], -1);
    dp[0][1] = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dp[i][j]==-1)continue;
            for(int a: graph[j]){
                dp[i+1][a]=max(dp[i+1][a], dp[i][j]+cost[a]);
            }
        }
        ans = max(ans, dp[i][1]-c*i*i);
    }
    cout<<ans<<endl;
    
} 