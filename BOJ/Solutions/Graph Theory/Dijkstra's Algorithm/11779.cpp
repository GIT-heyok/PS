#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
int INF = 1e9;
int main() {
    FAST
    int n, m;
    cin >> n >> m;
    int dist[n+1];
    for (int i = 0; i <= n; ++i) {
        dist[i] = INF;
    }
    vector<pair<int, int>> graph[n+1];
    int prevPath[n+1];
    for (int i = 0; i < n + 1; ++i) {
        prevPath[i] = i;
    }
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    int start, end;
    cin >> start >> end;
    pq.push({0, start});
    while(!pq.empty()){
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curWeight<=dist[curNode]){
            for (int i = 0; i < graph[curNode].size(); ++i) {
                int nextNode = graph[curNode][i].first;
                int nextWeight = graph[curNode][i].second;
                if(curWeight+nextWeight<dist[nextNode]){
                    prevPath[nextNode] = curNode;
                    dist[nextNode] = curWeight+nextWeight;
                    pq.push({-(curWeight+nextWeight), nextNode});
                }
            }
        }
    }
    cout<<dist[end]<<endl;
    int cur = end;
    vector<int> path;
    while(cur!=start){
        path.push_back(cur);
        cur = prevPath[cur];
    }
    path.push_back(start);
    cout<<path.size()<<endl;
    for (int i = path.size()-1; i >= 0; --i) {
        cout<< path[i] <<" ";
    }
    cout<<endl;

}
