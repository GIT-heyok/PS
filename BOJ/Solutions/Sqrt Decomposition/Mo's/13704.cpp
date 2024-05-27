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
int pf[100'001];
vector<ll> ans(100'001);
ll cnt[2'000'001];
ll result = 0;
int k;
void add(int v){
    result += cnt[v^k];
    cnt[v]++;
}
void del(int v){
    cnt[v]--;
    result -= cnt[v^k];
}
// k == 0 이면 그냥 sum이 되는거임.
// k != 0 이면 생각이 필요하긴 한데
// 추가 될때 가져가는게 나쁘지 않을지도?
// 추가 될 때는 뭐 ㅋㅋ
int main(void) {
    FAST
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pf[i] = arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        pf[i] = pf[i-1]^arr[i];
    }
    sz = sqrt(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        q.push_back(query(a-1, b,i)); // why?
    }
    sort(q.begin(), q.end(), comp);
    int prevS = 1, prevE = 0;
    for (int i = 0; i < q.size(); ++i) {
        int curS = q[i].s, curE = q[i].e;
        while(curS < prevS){ // Append
            prevS--;
            add(pf[prevS]);
        }
        while(curE > prevE){ // Append
            prevE++;
            add(pf[prevE]);
        }
        while(curS > prevS){ // remove
            del(pf[prevS]);
            prevS++;
        }
        while(curE < prevE){ // remove
            del(pf[prevE]);
            prevE--;
        }
        ans[q[i].idx] = result;
    }
    for (int i = 0; i < m; ++i) {
        cout<<ans[i]<<endl;
    }


}

