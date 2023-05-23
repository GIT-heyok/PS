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
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
vector<pI> graph[MAX + 1];
int depth[MAX + 1];
int parent[17][MAX + 1][3]; //0: node, 1: min, 2: mxm

void realGraph(int prev, int cur, int d) {
    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i].first;
        if (prev == cur) {
            parent[0][prev][0] = cur;
            parent[0][prev][1] = inf;
            parent[0][prev][2] = 0;

            depth[cur] = 0;
        }
        if (next != prev) {
            parent[0][next][0] = cur;
            parent[0][next][1] = graph[cur][i].second;
            parent[0][next][2] = graph[cur][i].second;
            depth[next] = d + 1;
            realGraph(cur, next, d + 1);
        }
    }
}

int main() {
    FAST
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    realGraph(1, 1, 0);
    for (int i = 0; i < 16; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[i + 1][j][0] = parent[i][parent[i][j][0]][0];
            parent[i + 1][j][1] = min(parent[i][j][1], parent[i][parent[i][j][0]][1]);
            parent[i + 1][j][2] = max(parent[i][parent[i][j][0]][2], parent[i][j][2]);

        }
    }
//    for (int j = 0; j < 3; ++j) {
//
//        for (int i = 1; i < n + 1; ++i) {
//            cout << "(" << parent[j][i][0] << " " << parent[j][i][1] << " " << parent[j][i][2] << ") ";
//        }
//        cout << endl;
//    }
//    for (int i = 1; i < n+1; ++i) {
//        cout<<depth[i]<<" ";
//    }
//    cout<<endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        int mnm = inf, mxm = 0;
        cin >> a >> b;
        int lca = a;
        if (depth[a] != depth[b]) {
            if (depth[a] > depth[b])swap(a, b);
            for (int j = 16; j >= 0; --j) {
                if (depth[a] <= depth[parent[j][b][0]]) {
                    mnm = min(mnm, parent[j][b][1]);
                    mxm = max(mxm, parent[j][b][2]);
                    b = parent[j][b][0];
                }
            }
        }

        if (a != b) {
            for (int j = 16; j >= 0; --j) {
                if (parent[j][a][0] != parent[j][b][0]) {
                    mnm = min(mnm, parent[j][b][1]);
                    mxm = max(mxm, parent[j][b][2]);
                    mnm = min(mnm, parent[j][a][1]);
                    mxm = max(mxm, parent[j][a][2]);
                    a = parent[j][a][0];
                    b = parent[j][b][0];
                }

            }
            mnm = min(mnm, parent[0][b][1]);
            mxm = max(mxm, parent[0][b][2]);
            mnm = min(mnm, parent[0][a][1]);
            mxm = max(mxm, parent[0][a][2]);
            lca = parent[0][a][0];

        }
        cout << mnm << " " << mxm << endl;

    }

}
