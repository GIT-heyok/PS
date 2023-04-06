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

int main(){
	FAST
    int n;
    cin >> n;
    vector<pD> coord(n+1);
    double visited[n+1];
    for (int i = 1; i <= n; i++)
    {
        double a, b;
        cin >> a >>b;
        coord[i] = {a, b};   
    }
    
    for (int i = 0; i < n+1; i++)
    {
        visited[i] = -INF;
    }
    priority_queue<pair<double, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int curNode = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(visited[curNode]==-INF){
            visited[curNode] = sqrt(cost);
            for (int i = 1; i<= n; i++)
            {
                if(i==curNode)continue;
                double x1 = coord[curNode].first;
                double y1 = coord[curNode].second;
                double x2 = coord[i].first;
                double y2 = coord[i].second;
                double dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                pq.push({-dist, i});
            }            
        }
    }
    double ans = 0;
    for (int i = 1; i < n+1; i++)
    {
         ans += visited[i];
    }
    cout<<setprecision(5);
    cout<<fixed;
    cout<<ans<<endl;
    
     
}



