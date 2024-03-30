#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

const int MAX = 100001;
vector<int> tree[MAX];
ll value[MAX];
ll lazy[MAX];
int totalChildren[MAX];
bool visited[MAX];
int n;

int dfs(int node){
    int cnt = 1;
    for (int i = 0; i < tree[node].size(); ++i) {
        cnt += dfs(tree[node][i]);
    }
    return totalChildren[node] = cnt;
}

void modify(int node, ll val){
    lazy[node]+=val;
}
void propagate(int idx, int dest){
    int curNode = idx;
    value[curNode] += lazy[curNode];
//    for (int i = 1; i <= n; ++i) {
//        cout<<lazy[i]<<" ";
//    }
//    cout<<endl;
//    for (int i = 1; i <= n; ++i) {
//        cout<<value[i]<<" ";
//    }
//    cout<<endl;
    for (int i = 0; i < tree[curNode].size(); ++i) {
        int nextNode = tree[curNode][i];
        if(nextNode>curNode){
            lazy[nextNode] += lazy[curNode];
            if(visited[nextNode]){
                if(curNode!=dest)
                    propagate(nextNode, dest);
            }
        }
    }
    lazy[idx] = 0;
}
ll get(int idx){
    int curNode = idx;
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
    }

    while(curNode!=1){
//        cout<<curNode<<endl;
        for (int i = 0; i < tree[curNode].size(); ++i) {
            int nextNode = tree[curNode][i];
            if(nextNode<curNode){
                visited[curNode] = true;
                curNode = nextNode;
            }
        }
    }
    propagate(1, idx);
    return value[idx];


}

int main()
{
    FAST
    int m;
    cin >> n >> m;
    int temp;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        if(temp!=-1){
            tree[temp].push_back(i);
            tree[i].push_back(temp);
        }
    }
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        if(type==1){
            int a, b;
            cin >> a >> b;
            modify(a,b);
        }
        else{
            int a;
            cin >> a;
            cout<<get(a)<<endl;
        }
    }



}
