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
//#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;
const int MAX = 100001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;

vector<pLL> graph[MAX];
ll memo[MAX];
ll dp(int prev, int cur){
    ll& ret = memo[cur];
    if(ret!=-1)return ret;
    ret = 0;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i].first;
        if(prev!=next){
            dp(cur, next);
        }
    }
    for (int i = 0; i < graph[cur].size(); i++)
    {
        
        int n1 = graph[cur][i].first;
        ll n1Val =graph[cur][i].second;
        if(prev==n1)continue;
        ret+=(n1Val+1)*(dp(cur, n1)+1)-1;
        ret%=MOD;
        for (int j = i+1; j < graph[cur].size(); j++)
        {
            int n2 = graph[cur][j].first;
            ll n2Val = graph[cur][j].second;
            if(prev==n2)continue;
            ret += ((n1Val+1)*(dp(cur, n1)+1)-1)*((n2Val+1)*(dp(cur,n2)+1)-1);
            ret%=MOD;
        }
        
    }
    return ret;
    
}
int main()
{
    FAST 
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }
    fill(memo, memo+n+1,-1);
    cout<<dp(1,1)<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<memo[i]<<" ";
    }
    cout<<endl;
    

}
