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
const int inf = 1e6;
const ll MOD = 1e7 + 3;
int parent[30001];
int children[30001];
ll candies[30001];
int find(int a){
    if(a==parent[a])return a;
    return parent[a]=find(parent[a]);
}
void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x!=y){
        if(x>y)swap(x,y);
        candies[x]+=candies[y];
        children[x]+=children[y];
        parent[y]=x;
    }
}
int main()
{
    FAST;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n; i++)
    {
        parent[i]=i;
        children[i]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> candies[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a,b);
    }
    bool visited[n+1];
    fill(visited, visited+n+1, 0);
    ll memo[k];
    fill(memo, memo+k, -1);
    memo[0]=0;
    for (int i = 1; i <=n; i++)
    {
        int p = find(i);
        if(visited[p])continue;
        visited[p]=true;
        for (int j = k-1; j >=0; j--)
        {
            if(j-children[p]>=0){
                if(memo[j-children[p]]!=-1)memo[j]=max(memo[j], memo[j-children[p]]+candies[p]);
            }
        }
        
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<candies[i]<<" ";
    // }
    // cout<<endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<children[i]<<" ";
    // }
    
    // cout<<endl;
    ll ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = max(ans, memo[i]);
    }
    cout<<ans<<endl;
    
    
}