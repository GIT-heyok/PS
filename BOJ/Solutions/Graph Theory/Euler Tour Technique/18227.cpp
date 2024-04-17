#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
//lazy Seg
int startNode[200001];
int endNode[200001];
int depth[200001];
struct SegTree {
    int n;
    vector<ll> a, t;

    SegTree(int sz) {
        n = sz;
        a.resize(n);
        t.resize(4 * n);
    }

    void update(int ss, int se, int ii, int idx, ll value) {
        if (ii > se || ii < ss)
            return;
        if (ii == ss && ss == se) {
            t[idx] += value;
            return;
        }
        int mid = (ss + se) / 2;
        update(ss, mid, ii, 2 * idx + 1, value);
        update(mid + 1, se, ii, 2 * idx + 2, value);
        // Tree manipulation
        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int ii, ll val) {
        update(0, n - 1, ii, 0, val);
    }

    ll get(int ss, int se, int qs, int qe, int idx) {
        // out of bound
        if (qs > se || qe < ss)
            return 0;
        if (qs <= ss && qe >= se) {
            return t[idx];
        }
        int mid = (ss + se) / 2;
        // Tree Manipulation
        return get(ss, mid, qs, qe, 2 * idx + 1) + get(mid + 1, se, qs, qe, 2 * idx + 2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int r) {
        return get(0, n - 1, l, r, 0);

    }

    void build(int ss, int se, int idx) {
        if (ss == se) {
            t[idx] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * idx + 1);
        build(mid + 1, se, 2 * idx + 2);
        // Tree Manipulation
        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
    }

    /**interface to call build function*/
    void build() {
        build(0, n - 1, 0);
    }

};
vector<int> graph[200001];
int cnt = 0;
void dfs(int cur, int prev = 0){
    startNode[cur] = ++cnt;
    for (int nextNode : graph[cur]) {
        if(depth[nextNode]==0){
            depth[nextNode] = depth[cur]+1;
            dfs(nextNode, cur);
        }
    }
    endNode[cur] = cnt;
}

int main(){
    FAST
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    depth[c] = 1;
    dfs(c);
    SegTree seg(n+1);
    seg.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        if(a==1){
            seg.update(startNode[b] , 1);
        }
        else{
            cout<<seg.get(startNode[b], endNode[b])*depth[b]<<endl;
        }
    }
}
