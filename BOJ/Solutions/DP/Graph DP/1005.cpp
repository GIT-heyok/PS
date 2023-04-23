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

const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;

vector<int> tree[MAX];
ll delay[MAX];
ll memo[MAX];
bool visited[MAX];
/*
dp(n) = max(dp(searchable prerequisites))+delay[n]
*/
ll dfs(int n){
    if(visited[n])return 0;
    if(memo[n]!=-1)return memo[n];
    ll& temp =memo[n];
    temp = 0;
    for (int i = 0; i < tree[n].size(); i++)
    {
        temp = max(temp, dfs(tree[n][i]));
    }
    temp+=delay[n];
    return temp;
    
}
int main()
{
    FAST;
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
        {
            tree[i].clear();
        }
        fill(memo, memo+n+1, -1);
        for (int i = 1; i <= n; i++)
        {
            cin>>delay[i];
        }
        for (int j = 0; j < k; j++)
        {
            int a, b;
            cin >> a >> b;
            tree[b].push_back(a);
        }
        int W;
        cin >> W;
        cout<<dfs(W)<<endl;
        
        

    }
}