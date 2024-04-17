#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll INF = 1e14;
int main() {
    FAST
    int n, m;
    cin >> n >> m;
    ll dist[n][2];
    for (int i = 0; i < n; ++i) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    int stationNumber[n];
    for (int i = 0; i < n; ++i) {
        cin >> stationNumber[i];
    }
    ll graph[n][n];
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    priority_queue<pair<pair<ll, ll>, int>> pq;
    dist[0][0] = 0;
    dist[0][1] = 0;
    pq.push({{0,0},0});
    while(!pq.empty()){
        ll curChangePath = -pq.top().first.first;
        ll curWeight = -pq.top().first.second;
        int curNode = pq.top().second;
        pq.pop();
        if(curChangePath>dist[curNode][0])
            continue;
        if(curChangePath==dist[curNode][0]&&curWeight>dist[curNode][1])
            continue;
        for (int i = 0; i < n; ++i) {
            if(graph[i][curNode]>0&&curNode!=i){
                int nextNode = i;
                ll nextChangePath = curChangePath;
                if(stationNumber[nextNode] != stationNumber[curNode])
                    nextChangePath++;

                ll nextWeight = curWeight + graph[nextNode][curNode];
                if(nextChangePath > dist[nextNode][0]) continue;
                if(nextChangePath == dist[nextNode][0] && nextWeight > dist[nextNode][1]) continue;
                dist[nextNode][0] = nextChangePath;
                dist[nextNode][1] = nextWeight;
                pq.push({{-nextChangePath, -nextWeight}, nextNode});
            }
        }
    }
    cout<<dist[m][0]<<" "<<dist[m][1]<<endl;

}
