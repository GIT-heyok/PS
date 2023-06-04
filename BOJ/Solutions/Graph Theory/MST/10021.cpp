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

//mst with selection
ll getDist(pI a, pI b){
    ll x = a.first-b.first;
    ll y = a.second-b.second;
    return x*x+y*y;
}
int main()
{
    FAST
    int n, c;
    cin >> n >> c;
    pair<int, int> coord[n];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        coord[i] = {a,b};
    }
    bool visited[n];
    fill(visited, visited+n, false);
    ll minim = 0;
    priority_queue<pLL> pq;
    pq.push({0,0});
    while(!pq.empty()){
        ll dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node])continue;
        visited[node]=true;
        minim+=dist;
        for (int i = 0; i < n; i++)
        {
            if(visited[i])continue;
            ll distDiff = getDist(coord[node], coord[i]);
            if(distDiff>=c)pq.push({-distDiff, i});
        }
    }
    bool chk = true;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i])chk=false;
    }
    if(chk)cout<<minim<<endl;
    else cout<<-1<<endl;
    
}