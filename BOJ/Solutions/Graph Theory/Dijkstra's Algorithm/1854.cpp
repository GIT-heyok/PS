#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int N,M,K;
vector< pair<int,int> > mp[1002];
priority_queue<int> kth_queue[1002];

int main() {
    FAST
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a,b,d;

        cin >> a >> b >> d;

        mp[a].push_back(make_pair(b,d));
    }
    priority_queue< pair<int,int> > pq;
    pq.push(make_pair(0,1));
    kth_queue[1].push(0);

    while(!pq.empty()) {
        int cur_u = pq.top().second;
        int cur_d = -pq.top().first;

        pq.pop();

        for (int i = 0; i < mp[cur_u].size(); i++) {
            int next_u = mp[cur_u][i].first;
            int next_d = mp[cur_u][i].second + cur_d;

            if (kth_queue[next_u].size() < K) {
                kth_queue[next_u].push(next_d);
                pq.push(make_pair(-next_d,next_u));
            } else if (kth_queue[next_u].top() > next_d) {
                kth_queue[next_u].pop();
                kth_queue[next_u].push(next_d);
                pq.push(make_pair(-next_d,next_u));
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (kth_queue[i].size() != K) cout << -1 << endl;
        else cout << kth_queue[i].top() << endl;
    }
}