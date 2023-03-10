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
#include <numeric>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
const int MAX = 100001;
const int INF = 1234567890;
int n, a, b;
vector<vector<pI>> tree(MAX, vector<pI>());
vector<bool> visited(MAX);
vector<int> res1, res2;

void dfs(int cur, int curVal, vector<int>& ansVec){
    for (int i = 0; i < tree[cur].size(); i++)
    {
        visited[cur] = true;
        int nxt = tree[cur][i].first;
        if(visited[nxt])continue;
        int nxtWt = curVal^tree[cur][i].second;
        if(nxt==a||nxt==b)continue;
        ansVec.push_back(nxtWt);
        dfs(nxt, nxtWt, ansVec);   
    }   
}
int main(){
    FAST
    int T;
    cin >> T;
   
    
    while(T--){
        cin >> n >> a >> b;
        res1.clear();
        res2.clear();
        
        for (int i = 1; i <= n; i++)
        {
            tree[i].clear();
        }
        
        for (int i = 0; i < n-1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            tree[u].push_back({v,w});
            tree[v].push_back({u,w});
        }
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }
        visited[a] = true; 
        visited[b] = true; 
        res1.push_back(0);
        dfs(a, 0, res1);

        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
        }
        visited[a] = true;
        visited[b] = true;
        dfs(b, 0, res2);
        
        sort(all(res1));

        bool flag = false;
        for (int i = 0; i < res2.size(); i++)
        {
            if(upper_bound(all(res1), res2[i])-lower_bound(all(res1), res2[i])){
                flag = true;
                break;
            }
        }
        if(flag)YES
        else NO
         
    }

}