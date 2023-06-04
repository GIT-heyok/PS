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
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

/*
Dijkstra's algorithm with a little tweak
(when it reaches the place, add bool
if same length, leave it
if there is a shorter distance toogle it back
)
*/
int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, m, t;
        cin >> n >> m >> t;
        int s ,g, h;
        cin >> s >> g >> h;
        
        vector<pI> graph[n+1];
        for (int i = 0; i < m; i++)
        {
            int a, b, d;
            cin>> a >> b>> d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }

        priority_queue<pI> pq;
        pq.push({0,s});
        int dist[n+1];
        bool routing[n+1];

        for (int i = 0; i < n+1; i++)
        {
            dist[i] = inf;
            routing[i] = false;
        }
        dist[s] = 0;
        while(!pq.empty()){
            int curDist = -pq.top().first;
            int curNode = pq.top().second;
            // cout<<curNode<<" "<<curDist<<" "<<routing[curNode]<<endl;
            pq.pop();
            if(dist[curNode]<curDist)continue;
            dist[curNode] = curDist;
            for (int i = 0; i < graph[curNode].size(); i++)
            {
                int nextNode = graph[curNode][i].first;
                bool passes = ((curNode==g&&nextNode==h)||(curNode==h&&nextNode==g));
                int nextDist = curDist+graph[curNode][i].second;
                if(nextDist<dist[nextNode]){
            // cout<<nextDist<<" "<<curNode<<" "<<nextNode<<" "<<diendl;
                 routing[nextNode]=passes||routing[curNode];
                    dist[nextNode] = nextDist;
                    pq.push({-nextDist, nextNode});
                }
                else if(nextDist==dist[nextNode]){
                    routing[nextNode]|= passes;
                    routing[nextNode]|=routing[curNode];
                }
                
            }
            
        }
        vector<int> ans;
        for (int i = 0; i < t; i++)
        {
            int temp;
            cin >> temp;
            if(routing[temp])ans.push_back(temp);

        }
        
        // for (int i = 1; i <= n; i++)
        // {
        //     cout<<dist[i]<<" ";
        // }
        // cout<<endl;
        
        // for (int i = 1; i <= n; i++)
        // {
        //     cout<<routing[i]<<" ";
        // }
        // cout<<endl;
        sort(all(ans));
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
               
    }
}