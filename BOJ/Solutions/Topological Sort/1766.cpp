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

const int MAX = 32001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;

//BFS indegree topological sort
int main()
{
    FAST;
    int n, m;
    cin>> n>> m;
    vector<int> tree[n+1];
    int inDegree[n+1];
    bool visited[n+1];
    vector<int> ans;
    priority_queue<int> pq;

    fill(inDegree, inDegree+n+1, 0);
    fill(visited, visited+n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        inDegree[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if(inDegree[i]==0)
        pq.push(-i);
    }

    while(!pq.empty()){
        int cur = -pq.top();
        pq.pop();
        if(visited[cur])continue;
        visited[cur] = true;
        ans.push_back(cur);
        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i];
            inDegree[next]--;
            if(inDegree[next]==0)pq.push(-next);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    
       
}