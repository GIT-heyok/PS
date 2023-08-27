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
const int inf = (1 << 20);
const ll MOD = 1e4 + 7;
int main() {
    FAST
    int n, m;
    cin >> n >> m;
    int arr[n+1][m+1];
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = s[j-1]-'0';
        }
    }
    int memo[n+1][m+1];
    fill(&memo[0][0], &memo[n][m+1], 0);
    memo[1][1] = arr[1][1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(!arr[i][j])memo[i][j]=0;
            else{
                memo[i][j] = min(memo[i-1][j], min(memo[i-1][j-1], memo[i][j-1]))+1;
                ans = max(ans, memo[i][j]);
            }
        }
        
    }
    cout<<ans*ans<<endl;
    
}