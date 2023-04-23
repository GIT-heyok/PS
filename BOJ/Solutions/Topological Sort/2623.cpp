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

bool arr[MAX][MAX];

/*Topological sort, beware of counting indegree in a
same input!
*/
int main()
{
    FAST;
    int n, m;
    cin>> n>> m;
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            arr[i][j] = false;
        }
        
    }

    int inDegree[n+1];
    fill(inDegree, inDegree+n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int sz;
        cin >> sz; 
        int cur = 0;
        for (int j = 0; j < sz; j++)
        {
            int nxt;
            cin >> nxt;
            if(j>0){
                if(!arr[cur][nxt])inDegree[nxt]++;
                arr[cur][nxt]= true;
            }   
            cur = nxt;
        }   
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if(inDegree[i]==0)q.push(i);
    }
    bool visited[n+1];
    fill(visited, visited+n+1, 0);
    while(!q.empty()){
        
        int cur = q.front();
        q.pop();
        if(visited[cur])continue;
        visited[cur] = true;
        ans.push_back(cur);
        for (int i = 1; i <= n; i++)
        {
            if(i==cur)continue;
            if(arr[cur][i])
                inDegree[i]--;
            if(inDegree[i]==0)
                q.push(i);
        }   
    }
    if(ans.size()==n){
        for (int a: ans)
        {
            cout<<a<<endl;
        }
        
    }
    else{
        cout<<0<<endl;
    }
    

    
    
}