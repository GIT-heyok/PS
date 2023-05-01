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

const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e6 + 7;
const int MAX = 100001;

//opposite direction union find
int parent[MAX];
int sizze[MAX];

int find(int a){
    if(parent[a]==a)return a;
    return parent[a] = find(parent[a]);
}
ll merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x==y)return 0;
    else{
        if(x>y)swap(x,y);
        ll szx = sizze[x];
        ll szy = sizze[y];
        sizze[x]+=sizze[y];
        parent[y]=x;
        return szx*szy;
    }
}
int main()
{
    FAST 
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        parent[i]=i;
        sizze[i]=1;
    }

    
    pI E[m+1];
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        E[i] = {a,b};
    }
    vector<int> process(q);
    for (int i = q-1; i >=0; i--)
    {
        cin>>process[i];
    }
    bool visited[m+1];
    fill(visited, visited+m+1, false);
    for (int i = 0; i < q; i++)
    {
        visited[process[i]] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        if(!visited[i])merge(E[i].first, E[i].second);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    
    ll ans= 0;
    for (int i = 0; i < q; i++)
    {
        ans+=merge(E[process[i]].first, E[process[i]].second);
    }
    cout<<ans<<endl;
    
}