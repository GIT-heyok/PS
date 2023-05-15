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
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;

vector<int> tree[MAX];
int compliment[MAX];
int memo[MAX];

void dfs(int cur, int prev, int val){
    int nowVal = val;
    nowVal+=compliment[cur];
    memo[cur] = nowVal;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i];
        if(next!=prev) dfs(next, cur, nowVal);
    }
    
}

int main()
{
    FAST 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;   
        cin >> a;
        if(i==1)continue;
        tree[a].push_back(i);   
    }
    fill(compliment, compliment+n+1, 0);
    fill(memo, memo+n+1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        compliment[a]+=b;
    }
    dfs(1,1,0);
    for (int i = 1; i <= n; i++)
    {
        cout<<memo[i]<<" ";
    }
    cout<<endl;
    
    
}
