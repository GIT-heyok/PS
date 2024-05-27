#include <bits/stdc++.h>

using namespace std;
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
typedef long long ll;

class query{
public:
    int s, e, idx;

    query(int s, int e, int idx): s(s), e(e), idx(idx){};
};

int sz = 0;

bool comp(query q1, query q2){
    if(q1.s/sz == q2.s/sz){
        return q1.e < q2.e;
    }
    else{
        return q1.s/sz < q2.s/sz;
    }
}
vector<query> q;
int arr[100'001];
vector<ll> ans(100'001);
ll cnt[1'000'001];
ll result = 0;
int k;
void add(int v){
    result -= cnt[v]*cnt[v]*v;
    cnt[v]++;
    result += cnt[v]*cnt[v]*v;
}
void del(int v){
    result -= cnt[v]*cnt[v]*v;
    cnt[v]--;
    result += cnt[v]*cnt[v]*v;
}
int main(void) {
    FAST
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sz = sqrt(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        q.push_back(query(a, b,i)); // why?
    }
    sort(q.begin(), q.end(), comp);
    int prevS = 1, prevE = 0;
    for (int i = 0; i < q.size(); ++i) {
        int curS = q[i].s, curE = q[i].e;
        while(curS < prevS){ // Append
            prevS--;
            add(arr[prevS]);
        }
        while(curE > prevE){ // Append
            prevE++;
            add(arr[prevE]);
        }
        while(curS > prevS){ // remove
            del(arr[prevS]);
            prevS++;
        }
        while(curE < prevE){ // remove
            del(arr[prevE]);
            prevE--;
        }
        ans[q[i].idx] = result;
    }
    for (int i = 0; i < m; ++i) {
        cout<<ans[i]<<endl;
    }


}

