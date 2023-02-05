#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int MAX = 200001;
const int INF = 1e9;

int n, ans = INF;
int dist[MAX], res[MAX];
bool visited[MAX];
vector<vi> tree(MAX);

void dfs(int v, int p){
    if(dist[v]>= ans) return;
    if(visited[v]) ans = min(ans, dist[v]);
    for(int u: tree[v]){
        if(u==p) continue;
        if(dist[v]+1<dist[u]){
            dist[u] = dist[v]+1;
            dfs(u, v);
        }
        else{
            ans = min(ans, dist[v]+1+dist[u]);
        }
    } 
}
int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int c;
        cin >> n >> c;
        ans = INF;
        vi query(n-1);
        for(int i=0; i<n-1; i++){
            cin >> query[i]; 
        }
        for(int i=1; i<=n; i++){
            tree[i].clear();
        }
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        fill(visited,visited+n+1, false);
        fill(dist, dist+n+1, INF);
        dist[c] = 0;
        dfs(c, 0);
        visited[c] = true;
        for(int i=0; i<n-1; i++){
            dist[query[i]] = 0;
            dfs(query[i],0);
            visited[query[i]] = true;
            res[i] = ans;
        }
        for(int i=0; i<n-1; i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;


    }
}