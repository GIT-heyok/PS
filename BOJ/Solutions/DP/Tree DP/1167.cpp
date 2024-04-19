#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

int ans = 0;
int depth[100001];
vector<pair<int, int>> graph[100001];
int dp(int curNode, int prevNode){
//    cout<<curNode<<endl;
    int d1 = 0;
    int d2 = 0;
    for (int i = 0; i < graph[curNode].size(); ++i) {
        int nextNode = graph[curNode][i].first;
        int weight = graph[curNode][i].second;
        if(prevNode!=nextNode){
            int val = weight+dp(nextNode, curNode);
            if(d1==0){
                d1 = val;
            }
            else{
                if(val>=d1){
                    d2 = d1;
                    d1 = val;
                }
                else{
                    if(val >= d2){
                        d2 = val;
                    }
                }
            }
        }
    }
    ans = max(ans, d1+d2);
    return depth[curNode]=d1;
}
int main(){
    FAST
    int v;
    cin >> v;
    for (int i = 0; i < v; ++i) {
        int node;
        cin >> node;
        while(true){
            int no;
            cin >> no;
            if(no==-1){
                break;
            }
            int weight;
            cin >> weight;
            graph[node].push_back({no, weight});
        }
    }
    for (int i = 0; i <= v; ++i) {
        depth[i] = 0;
    }
    dp(1,0);
//    for (int i = 1; i <= v; ++i) {
//        cout<<depth[i]<<" ";
//    }
//    cout<<endl;
    cout<<ans<<endl;
}
