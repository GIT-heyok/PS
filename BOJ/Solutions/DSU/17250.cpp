#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
const int MAX = 100001;
int parent[MAX];
int cnt[MAX];

int find(int a){
    if(parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

int get(int a){
    return cnt[find(a)];
}
int merge(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return get(a);
    if(pa>pb){
        swap(pa, pb);
    }
    parent[pb] = pa;
    cnt[pa] += cnt[pb];
    return cnt[pa];
}
int main() {
   FAST
   int n, m;
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
        cin >> cnt[i];
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout<<merge(a,b)<<endl;
    }
}