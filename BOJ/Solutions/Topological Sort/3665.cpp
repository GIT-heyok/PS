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
const int MAX = 501;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
/*
when the original order is 1->2->3->4:
1->2, 1->3, 1->4,
2->3, 2->4,
3->4 holds true.

m inputs changes the order: 2 3 to 3->2

when only one order is possible, for all time: indegree=0
two or more indegree=0 -> inconsistent
zero indegree=0 -> impossible
after the node has been set, set the indegree to infinite for 
complete search.

*/
int main()
{
    FAST 
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int orig[n];
        for (int i = 0; i < n; i++)
        {
            cin >> orig[i];
        }
        bool graph[n+1][n+1];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                graph[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                graph[orig[i]][orig[j]] = true;
            }
        }
        
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if(graph[a][b]){ // a -> b is right
                graph[a][b] = false;
                graph[b][a] = true;
            }
            else{ // b -> a is right
                graph[b][a] = false;
                graph[a][b] = true;
            }
        }
        int inDegree[n+1];
        for (int i = 0; i < n+1; i++)
        {
            inDegree[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(graph[i][j])inDegree[j]++;
            }
        }
        
        vector<int> order;
        bool impossible = false;
        bool inconsistent = false;
        int cur=-1;
        
        for (int i = 0; i < n; i++)
        {
            int zeroCount = 0;
            for (int j = 1; j <= n; j++)
            {
                if(inDegree[j]==0){zeroCount++;cur=j;}
            }
            
            if(zeroCount==0){impossible=true;break;}
            else if(zeroCount>=2){inconsistent=true; break;}
            for (int j = 1; j <= n; j++)
            {
                if(graph[cur][j]){
                    graph[cur][j]=false;
                    inDegree[j]--;
                }
            }
            inDegree[cur]=MAX;
            order.push_back(cur);            
        }
        if(impossible)cout<<"IMPOSSIBLE"<<endl;
        else if(inconsistent)cout<<"?"<<endl;
        else{
            for (int i:order)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            
        }
        
        
        
        
        
        
    }

}
