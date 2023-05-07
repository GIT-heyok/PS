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
const int MAX = 200001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
int main()
{
    FAST
    int N, T;
    cin >> N >> T;
    vector<pI> city(N+1);
    bool isSpecial[N+1];
    for (int i = 1; i <= N; i++)
    {
        int s, x, y;
        cin >> s >> x >> y;
        isSpecial[i] = !!s;
        city[i] = {x,y};
    }
    int arr[N+1][N+1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(i==j){arr[i][j] = 0;continue;}
            arr[i][j] = inf;
            if(isSpecial[i]&&isSpecial[j])arr[i][j]= T;
            int dx = abs(city[i].first-city[j].first);
            int dy = abs(city[i].second-city[j].second);
            arr[i][j] = min(dx+dy, arr[i][j]);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int dist[N+1];
        for (int i = 0; i < N+1; i++)
        {
            dist[i] = inf;
        }
        int a, b;
        cin >> a>> b;
        dist[a] = 0;
        priority_queue<pI> pq;
        pq.push({0, a});
        while(!pq.empty()){
            int curIdx = pq.top().second;
            int curDist = -pq.top().first;
            pq.pop();
            if(dist[curIdx]<curDist)continue;
            for (int i = 1; i <= N; i++)
            {
                if(i==curIdx)continue;
                if(dist[i]>dist[curIdx]+arr[curIdx][i]){
                    dist[i] = dist[curIdx]+arr[curIdx][i];
                    pq.push({-dist[curIdx]-arr[curIdx][i], i});
                }
            }
            
        }
        cout<<dist[b]<<endl;  
    }

    
    
}

