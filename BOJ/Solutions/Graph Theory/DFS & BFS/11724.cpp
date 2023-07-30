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
const int MAX = 16;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

bool arr[1001][1001];
bool chk[1001];

void dfs(int node){
    chk[node] = true;
    for (int i = 1; i < 1001; i++)
    {
        if(arr[node][i]&&!chk[i]){
            dfs(i);
        }
    }
}


int main()
{
    FAST
    int n, m;
    cin >>  n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!chk[i]){
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
    
}