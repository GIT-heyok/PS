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

const int MAX = 101;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9;
//PRIM's Algorithm https://c4u-rdav.tistory.com/49
int main(){
	FAST
    int v, e;
    cin >> v >> e;
    priority_queue<pI> pq;
    vector<pI> edges[v+1];
    int visited[v+1];
    for (int i = 0; i < e; i++)
    {
        int s, ee, w;
        cin >> s >> ee >> w;
        edges[s].push_back({-w, ee});
        edges[ee].push_back({-w, s});
    }
    for (int i = 0; i < v+1; i++)
    {
        visited[i] = -inf;
    }
    pq.push({0, 1});
    while(!pq.empty()){
        int curNode = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(visited[curNode]==-inf){
            visited[curNode] = cost;
            for (int i = 0; i < edges[curNode].size(); i++)
            {
                pq.push(edges[curNode][i]);
            }       
        }
    }
    int ans = 0;
    for (int i = 1; i < v+1; i++)
    {
         ans += visited[i];
    }
    cout<<ans<<endl;
    
     
}


