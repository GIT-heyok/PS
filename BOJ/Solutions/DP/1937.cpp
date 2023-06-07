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
const int MAX = 501;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int arr[MAX][MAX];
int memo[MAX][MAX];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int n;
int dp(int r, int c){
        if(memo[r][c]!=-1)return memo[r][c];
        int cur = 1;
        int prev = 0;
        for (int i = 0; i < 4; i++)
        {
            int nextr = r+dr[i];
            int nextc = c+dc[i];
            if(nextr>=0&&nextr<n&&nextc>=0&&nextc<n&&arr[r][c]<arr[nextr][nextc])
                prev = max(dp(r+dr[i], c+dc[i]), prev);
        }
        cur+=prev;
        return memo[r][c] = cur;   
}
int main()
{
    FAST
    cin >> n;
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int i2 = 0; i2 < n; i2++)
        {
            cin >> arr[i1][i2];
            memo[i1][i2] = -1;
        }
    }
    int ans = 0;
    for (int i1 = 0; i1 < n; i1++)
    {
        for (int i2 = 0; i2 < n; i2++)
        {
            ans = max(ans, dp(i1,i2));
        }
        
    }
    cout<<ans<<endl;
    
    
}