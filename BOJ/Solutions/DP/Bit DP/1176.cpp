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
const double INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
int n,k;
ll memo[MAX][1<<MAX];
int height[MAX];
ll dfs(int cur, int bit){
    if(cur==-1){
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dfs(i, (1<<i));
        }
        return ans;
    }
    if(bit==(1<<n)-1)return 1;

    ll& temp = memo[cur][bit];
    if(temp!=-1)return temp;
    temp = 0;
    for (int i = 0; i < n; i++)
    {
        if(abs(height[cur]-height[i])<=k)continue;
        if(bit&(1<<i))continue;
        temp += dfs(i,bit+(1<<i));
    }
    return temp;
    
}
int main()
{
    FAST 
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    
    fill(&memo[0][0], &memo[MAX-1][(1<<MAX)-1], -1);
    cout<<dfs(-1,0)<<endl;
    
    
}
