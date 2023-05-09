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
const int MAX = 10001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
ll memo[MAX][2];
ll weight[MAX];
vector<int> tree[MAX];
vector<int> g[MAX];
bool visited[MAX][2];
bool chk[MAX];
vector<int> ans;

void track(int now, int include){
    if(include){
        ans.push_back(now);
        for (int i = 0; i < tree[now].size(); i++)
        {
            int nxt = tree[now][i];
            track(nxt,0);
        }
    }
    else{
        for (int i = 0; i < tree[now].size(); i++)
        {
            int nxt = tree[now][i];
            track(nxt, chk[nxt]);
        }
        
    }
}
ll dp(int curNode, bool isCounted){
    if(memo[curNode][isCounted]!=-1){
        return memo[curNode][isCounted];
    }
    ll& val = memo[curNode][isCounted] = 0;
    if(isCounted)val+=weight[curNode];
    for (int i = 0; i < tree[curNode].size(); i++)
    {
        int next = tree[curNode][i];
        ll dpCount = 0, dpNotCount = 0;
            dpNotCount = dp(next, false);
            dpCount = dp(next, true);
        if(isCounted){
            val+=dpNotCount;
        }
        else{
            if(dpCount>dpNotCount)chk[next]=true;
            else chk[next]=false;
            val+=max(dpCount, dpNotCount);
        }
    }

    return val;
    
}

void dfs(int now, int prv){
    for (int i = 0; i < g[now].size(); i++  )
    {
        int nxt = g[now][i];
        if(nxt!=prv){
            tree[now].push_back(nxt);
            dfs(nxt, now);
        }
    }
    
}
int main(){
    FAST
    int n;
    cin >> n;
    memset(visited, false, sizeof(visited));
    fill(&memo[0][0], &memo[n][2], -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    cout<<max(dp(1,true),dp(1,false))<<endl;
    
}