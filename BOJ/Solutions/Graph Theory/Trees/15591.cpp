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
const int MAX = 100001;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;
vector<pI> graph[MAX];
int dfs(int k, int curUsa, int prev, int cur){
    // cout<<k<<" "<<prev<<" "<<cur<<endl;
    //how many nodes satisfiy in the subtree
    int ret = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i].first;
        int val = graph[cur][i].second;
        if(prev!=next){
            if(min(curUsa,val)>=k)
            ret+=dfs(k,min(curUsa,val), cur, next); 
        }
    }
    return ret;
}  

int main()
{
    FAST
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++)
    {
        int a, b, c;
        cin >> a  >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for (int i = 0; i < q; i++)
    {
        int k, v;
        cin >> k >> v;
        cout<<dfs(k,k,v,v)-1<<endl;
    }
    
    
    
}