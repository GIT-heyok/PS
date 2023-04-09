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
//#define endl '\n'
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
int main()
{
    FAST
    int n;
    cin >> n;
    ll coord[3][n];
    pLL coordSort[3][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> coord[j][i];
            coordSort[j][i].first = coord[j][i];
            coordSort[j][i].second = i;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        sort(&coordSort[i][0], &coordSort[i][n]);
    }
    
    ll dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = -1;
    }
    
    vector<pLL> tree[n];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            ll lowCoord = coordSort[i][j].first;
            ll highCoord = coordSort[i][j+1].first;
            ll lowNode = coordSort[i][j].second;
            ll highNode = coordSort[i][j+1].second;
            tree[lowNode].push_back({-(highCoord-lowCoord), highNode});
            tree[highNode].push_back({-(highCoord-lowCoord), lowNode});
        }
    }

    priority_queue<pLL> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll d = -pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(dist[node]==-1){
            dist[node] = d;
            for (int i = 0; i < tree[node].size(); i++)
            {
                pq.push(tree[node][i]);
            }
        }
    }
    ll ans =0;
    for (int i = 0; i < n; i++)
    {
        ans+=dist[i];
    }
    cout<<ans<<endl;
     
    
    
   
    



}

