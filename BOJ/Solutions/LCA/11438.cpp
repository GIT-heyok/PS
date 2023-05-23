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
vector<int> graph[MAX + 1];
int depth[MAX + 1];
int parent[17][MAX + 1];

void realGraph(int prev, int cur, int d) {
    for (int i = 0; i < graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (prev == cur) {
            parent[0][prev] = cur;
            depth[cur] = 0;
        }
        if (next != prev) {
            parent[0][next] = cur;
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
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    realGraph(1, 1, 0);
    for (int i = 0; i < 16; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[i + 1][j] = parent[i][parent[i][j]];
        }
    }
//    for (int i = 1; i < n+1; ++i) {
//        cout<<parent[0][i]<<" ";
//    }
//    cout<<endl;
//    for (int i = 1; i < n+1; ++i) {
//        cout<<depth[i]<<" ";
//    }
//    cout<<endl;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if(depth[a]!=depth[b]){
            if(depth[a]>depth[b])swap(a,b);
            for (int j = 16; j >= 0; --j) {
                if(depth[a]<=depth[parent[j][b]])b=parent[j][b];
            }
        }
        int lca = a;
//        cout<<a <<b<<endl;
        if(a!=b){
            for (int j = 16; j >=0 ; --j) {
                if(parent[j][a]!=parent[j][b]){
                    a = parent[j][a];
                    b = parent[j][b];
                }
                lca = parent[j][a];
            }
        }
        cout<<lca<<endl;

    }

} 