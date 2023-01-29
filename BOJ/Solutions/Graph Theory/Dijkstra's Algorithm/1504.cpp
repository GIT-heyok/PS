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

ll dijkstra(int arr[801][801],int s, int e){
    ll dist[801];
    fill(dist, dist+801, INF);
    priority_queue<pLL> q;
    q.push({0,s});
    dist[s] = 0;
    while(!q.empty()){
        ll cost = -q.top().first;
        ll here = q.top().second;
        // cout<<cost<<" "<<here<<endl;
        q.pop();
        for(int i=1; i<=800; i++){
            if(arr[here][i]<INF){
                ll nextCost = arr[here][i];
                if(dist[i]>dist[here]+nextCost){
                    dist[i] = dist[here]+nextCost;
                    q.push({-dist[i],i});
                }
            }
        }
    }
    return dist[e];
}

int main()
{
    FAST
    int n, e;
    cin >> n >> e;
    int arr[800+1][800+1];
    for(int i=1; i<=800; i++){
        for(int j=1; j<=800; j++){
            arr[i][j] = INF;
        }
    }

    for(int i=0; i<e; i++){
        int a,b,c;
        cin >> a>> b>>c;
        arr[a][b] = c;
        arr[b][a] = c;
    }
    int v1, v2;
    //1->v1->v2->N or 1->v2->v1->N
    cin >> v1 >>v2;
           
    ll r1 = dijkstra(arr, 1, v1);
    ll r2 = dijkstra(arr, 1, v2);
    ll p1 = dijkstra(arr, v1, n);
    ll p2 = dijkstra(arr, v2, n);
    ll pil = dijkstra(arr, v1, v2);
    // cout<<r1<<" "<<r2 << " "<<p1<< " "<<p2 << " "<<pil<<endl;
    ll ans = min(r1+p2+pil, r2+p1+pil);
    if(ans>=INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
