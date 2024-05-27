#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;
/*
 * tree의 root?
 * 찾는 거는 루트로 올라가서 하위 노드들의 색을 다 입력해주면 된다.
 * 이것도 동일하게 map으로 개수 반영하면 될듯
 * 처음 tree를 설정 할 때는 아무런 차이가 없음.
 * dsu 느낌으로 관리 해야함.
 * 오프라인으로 다 분할 한 다음 하나씩 합치면 안되나?
 */

const int sz = 100'001;
vector<int> graph[sz];
int par[sz];
int color[sz];
bool chk[sz];
int ans[sz*10];
vector<pair<int, int>> query;
map<int, int> m[sz];
int parent[100001];
int find(int node){
    if(node == parent[node])
        return node;
    return parent[node] = find(parent[node]);
}

void merge(int a, int b){
    int pa = find(a), pb = find(b);
    if(pa==pb)
        return;
    if(m[pa].size() <m[pb].size())
        swap(m[pa],m[pb]);
    for(auto i=m[pb].begin(); i!=m[pb].end() ;i++){
        m[pa][i->first] += i->second;
    }
    parent[pb] = pa;
}

int main(void) {
    FAST
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> color[i];
        parent[i] = i;
        m[i][color[i]]++;
    }
    for (int i = 0; i < n+q-1; ++i) {
        int a, b;
        cin >> a >> b;
        query.push_back({a,b});
    }
    for (int i = 0; i < n+q-1; ++i) {
        if(query[i].first==1){
            chk[query[i].second] = true;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if(!chk[i])
            merge(i, par[i]);
    }

    int cnt = q;
    for (int i = n+q-2; i >= 0; --i) {
        int type = query[i].first;
        int val = query[i].second;
        if(type == 1){
            merge(val, par[val]);
        }
        else{
            ans[cnt] = m[find(val)].size();
            cnt--;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout<<ans[i]<<endl;
    }

}