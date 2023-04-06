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
const ll INF = 1e15;
const int inf = 1234567890;
const ll MOD = 1e9;

int main(){
	FAST
    int n,m;
    cin >> n >> m;
    vector<pD> coord(n+1);
    double arr[n+1][n+1];
    double visited[n+1];
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        coord[i] = {x,y};
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double x1 = coord[i].first;
            double y1 = coord[i].second;
            double x2 = coord[j].first;
            double y2 = coord[j].second;
            double dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            arr[i][j] = dist;
        }
        
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 0;
        arr[b][a] = 0;
    }
    
    for (int i = 0; i < n+1; i++)
    {
        visited[i] = -INF;
    }
    priority_queue<pair<double, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int curNode = pq.top().second;
        double cost = -pq.top().first;
        pq.pop();
        if(visited[curNode]==-INF){
            visited[curNode] = sqrt(cost);
            for (int i = 1; i<= n; i++)
            {
                if(i==curNode)continue;
                pq.push({-arr[curNode][i], i});
            }            
        }
    }
    double ans = 0;
    for (int i = 1; i < n+1; i++)
    {
         ans += visited[i];
    }
    cout<<setprecision(2);
    cout<<fixed;
    cout<<ans<<endl;
    
     
}


