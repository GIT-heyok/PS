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
    int n, m, x;
    cin >> n >> m >> x;
    int distGo[n+1];
    int distCome[n+1];
    for (int i = 1; i <= n; ++i) {
        distGo[i] = INF;
        distCome[i] = INF;
    }
    vector<pair<int, int>> graphGo[n+1];
    vector<pair<int, int>> graphCome[n+1];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < m; ++i) {
        int s, e, w;
        cin >> s >> e >> w;
        graphGo[s].push_back({e, w});
        graphCome[e].push_back({s, w});
    }

    pq.push({0,x});
    distGo[x]=0;
    while(!pq.empty()){
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curWeight<=distGo[curNode]){
            for (int i = 0; i < graphGo[curNode].size(); ++i) {
                int nextNode = graphGo[curNode][i].first;
                int nextWeight = graphGo[curNode][i].second;
                if(curWeight+nextWeight<distGo[nextNode]){
                    distGo[nextNode] = curWeight+nextWeight;
                    pq.push({-(curWeight+nextWeight), nextNode});
                }
            }
        }
    }

    distCome[x]=0;
    pq.push({0,x});
    while(!pq.empty()){
        int curWeight = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if(curWeight<=distCome[curNode]){
            for (int i = 0; i < graphCome[curNode].size(); ++i) {
                int nextNode = graphCome[curNode][i].first;
                int nextWeight = graphCome[curNode][i].second;
                if(curWeight+nextWeight<distCome[nextNode]){
                    distCome[nextNode] = curWeight+nextWeight;
                    pq.push({-(curWeight+nextWeight), nextNode});
                }
            }
        }
    }
    int mxm = 0;
    for (int i = 1; i <= n; ++i) {
        mxm = max(distGo[i]+distCome[i],mxm);
    }
    cout<<mxm<<endl;

}
