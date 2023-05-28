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
const ll MOD = 1e9 + 7;

int main() {
    FAST
    int n, m, k;
    vector<pI> graphMax[n + 1];
    vector<pI> graphMin[n + 1];
    for (int i = 0; i < m; ++i) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'B') {
            graphMax[a].push_back({b, 0});
            graphMax[b].push_back({a, 0});
            graphMin[a].push_back({b, 1});
            graphMin[b].push_back({a, 1});
        } else {

            graphMax[a].push_back({b, 1});
            graphMax[b].push_back({a, 1});
            graphMin[a].push_back({b, 0});
            graphMin[b].push_back({a, 0});
        }
    }
    bool visited[n + 1];
    fill(visited, visited + n + 1, false);
    priority_queue<pI> pq;
    pq.push({0, 1});
    int ans1 = 0;
    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curVal = -pq.top().first;
        pq.pop();
        if (visited[curNode])continue;
        ans1 += curVal;
        visited[curNode] = true;
        for (int i = 0; i < graphMax[curNode].size(); ++i) {
            int nextNode = graphMax[curNode][i].first;
            int nextVal = graphMax[curNode][i].second;
            if (!visited[nextNode])pq.push({-nextVal, nextNode});
        }
    }
    pq.push({0, 1});
    int ans2 = 0;

    fill(visited, visited + n + 1, false);
    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curVal = -pq.top().first;
        pq.pop();
        if (visited[curNode])continue;
        ans2 += curVal;
        visited[curNode] = true;
        for (int i = 0; i < graphMin[curNode].size(); ++i) {
            int nextNode = graphMin[curNode][i].first;
            int nextVal = graphMin[curNode][i].second;
            if (!visited[nextNode])pq.push({-nextVal, nextNode});
        }
    }
    ans1 = n - 1 - ans1;
    cout << (k >= ans2 && k <= ans1) << endl;
}
