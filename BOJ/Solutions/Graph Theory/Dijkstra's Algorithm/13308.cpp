#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll INF = 1e14;
ll memo[2501][2501];
int oil[2501];
int n, m;
vector<pair<int, int>> graph[2501];
priority_queue<pair<ll, pair<int, int>>> pq;


int main() {
    FAST
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> oil[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 2500; ++j) {
            memo[i][j] = -1;
        }
    }
    pq.push({0, {1, oil[1]}});
    ll minCost;
    while (!pq.empty()){
        int cur = pq.top().second.first;
        ll curCost = -pq.top().first;
        int curOil = pq.top().second.second;
        pq.pop();
        ll& ret = memo[cur][curOil];
        if(ret!=-1)continue;
        ret = curCost;
        if(cur==n){
            minCost = curCost;
            break;
        }
        for (int i = 0; i < graph[cur].size(); ++i) {
            int next = graph[cur][i].first;
            ll nextCost = graph[cur][i].second*min(curOil, oil[cur])+curCost;
            int nextOil = min(curOil, oil[cur]);

            if(memo[next][nextOil]==-1){
                pq.push({-nextCost, {next, nextOil}});
            }
        }
    }
    cout<<minCost<<endl;
}

