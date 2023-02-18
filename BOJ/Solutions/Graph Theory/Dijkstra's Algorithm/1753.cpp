#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
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
const int MAX = 500001;
const ll INF = 12345670;

//priority queue requires a certain order!

int main()
{
    FAST
    int v, e, s;
    cin >> v >> e >> s;
    vector<pair<int, int>> vec[v+1];
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v,w});
    } 
    int dist[v+1];
    fill(dist, dist+v+1, INF);
    priority_queue<pI> q;
    dist[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        int cost = -q.top().first;
        int here = q.top().second;
        q.pop();
        for(auto a:vec[here]){
            if(a.second<INF){
            int nextCost = a.second;
            if(dist[a.first]>dist[here]+nextCost){
                dist[a.first] = dist[here]+nextCost;
                q.push({-dist[a.first], a.first});
            }}
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i]>=INF){
            cout<<"INF"<<endl;
        }
        else{
            cout<<dist[i] <<endl;
        }
    }
    cout<<endl;

}