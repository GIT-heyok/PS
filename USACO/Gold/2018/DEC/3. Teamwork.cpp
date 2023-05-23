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

void setFile(string s){
    freopen((s+".in").c_str(), "r", stdin);
    freopen((s+".out").c_str(), "w", stdout);
}
    /*dp[i]: maximum sum value from dp(1~i)
    =max(dp[i],dp[i-j-1]+mxm*(i-j+1))
    iterate through j (j<=k)
*/
int main()
{
    FAST
    setFile("teamwork");
    int n, k;
    cin >> n >> k;
    ll skills[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> skills[i];
    }
    ll dp[n+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }
    dp[1] = skills[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+skills[i];
        ll mxm = skills[i];
        
        for (int j = 1; j < k&&i-j>0; j++)
        {
            mxm = max(mxm,skills[i-j]);
            dp[i] = max(mxm*(j+1)+dp[i-j-1], dp[i]);
        }   
    }
    cout<<dp[n]<<endl;
    
    
} 