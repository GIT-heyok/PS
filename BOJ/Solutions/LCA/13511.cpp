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
const int inf = 1234567890;
const ll MOD = 1e9 + 7;
vector<pLL> graph[MAX + 1];
int depth[MAX + 1];
ll parent[MAX_DEPTH+1][MAX + 1][2];

void realGraph(int prev, int cur, int d) {
    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i].first;
        if (prev == cur) {
            parent[0][prev][0] = cur;
            parent[0][prev][1] = 0;
            depth[cur] = d;
        }
        if (next != prev) {
            parent[0][next][0] = cur;
            parent[0][next][1] = graph[cur][i].second;
            depth[next] = d + 1;
            realGraph(cur, next, d + 1);
        }
    }
}

/*
 * 1. get the values of a and b.
 * 2. first query: store this place to parent node's sum of edge weight
 * 3. second query: total length: depth(LCA(a,b))-depth(a)+depth(LCA(a,b))-depth(b)-1
*/
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
    for (int i = 0; i < MAX_DEPTH; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[i + 1][j][0] = parent[i][parent[i][j][0]][0];
            parent[i + 1][j][1] = parent[i][j][1] + parent[i][parent[i][j][0]][1];

        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        int calA = a, calB = b;
        ll sum = 0;
        //pull 'b' up
        if (depth[calA] != depth[calB]) {
            if (depth[calA] > depth[calB]) {
                swap(calA, calB);
            }
            int depthDiff = depth[calB]-depth[calA];
            for (int j = MAX_DEPTH; j >= 0; --j) {
                if(depthDiff&(1<<j)){
                    sum+=parent[j][calB][1];
                    calB = parent[j][calB][0];
                }
            }
        }
        int lca = calA;
        if(calA!=calB){
            for (int j = MAX_DEPTH; j >= 0; --j) {
                if(parent[j][calA][0]!=parent[j][calB][0]){
                    sum+=parent[j][calA][1]+parent[j][calB][1];
                    calA = parent[j][calA][0];
                    calB = parent[j][calB][0];
                }
            }
            sum += parent[0][calA][1]+parent[0][calB][1];
            lca =  parent[0][calA][0];
        }

        if (type == 1) {
            cout<<sum<<endl;
        } else {
            int kth;
            cin >> kth;
            int ans;
            int up;
            if(depth[a]-depth[lca]>=kth){
                ans = a;
                up = kth-1;
            }
            else{
                ans = b;
                kth-=depth[a]-depth[lca]+1;
                up = (depth[b]-depth[lca])-kth;

            }
//            cout<<depth[a]<<" "<<depth[lca]<<" "<<lca<<" "<<depth[b]<<ans<<up<<endl;
            for (int j = MAX_DEPTH; j >= 0; --j) {
                if(up&(1<<j))ans = parent[j][ans][0];
            }
            cout<<ans<<endl;

        }
    }

}
