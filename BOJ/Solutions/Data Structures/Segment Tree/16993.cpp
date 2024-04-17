
#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
ll INF = 1e9;
// Segment Tree without Lazy Propagation
ll prefixSum[100001];
struct SegTree {
    int n;
    vector<ll> a, tL, tR, tM;

    SegTree(int sz) {
        n = sz;
        a.resize(n);
        tL.resize(4 * n);
        tR.resize(4 * n);
        tM.resize(4 * n);
    }

    vector<ll> get(int ss, int se, int qs, int qe, int idx) {
        // out of bound
        if (qs > se || qe < ss){
            vector<ll> vec = {-INF, -INF, -INF};
            return vec;
        }
        if (qs <= ss && qe >= se) {
            vector<ll> vec = {tL[idx], tR[idx], tM[idx]};
            return vec;
        }
        int mid = (ss + se) / 2;
        // Tree Manipulation
        vector<ll> left = get(ss, mid, qs, qe, 2*idx+1);
        vector<ll> right = get(mid+1, se, qs, qe, 2*idx+2);
//        cout<<"ss, se: "<<ss<<" "<<se<<" ";
//        for (int i = 0; i < left.size(); ++i) {
//            cout<<left[i]<<" ";
//        }
//        for (int i = 0; i < right.size(); ++i) {
//            cout<<right[i]<<" ";
//        }
//        cout<<endl;
        vector<ll> ret = {-INF,-INF,-INF};
        ret[2] = max(left[2], right[2]);
//        ll curTM = max(max(curTL, curTR), tR[2*idx+1]+tL[2*idx+2]);
        ret[0] = max(left[0], prefixSum[mid]-prefixSum[ss-1]+right[0]);
        ret[1] = max(right[1], prefixSum[se]-prefixSum[mid]+left[1]);
        ret[2] = max(ret[2], right[0]+left[1]);
//    cout<<"returning "<<ss<<" "<<se<<", "<<qs<<" "<<qe<<" : "<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
        return ret;
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int r) {
        vector<ll> temp = get(0, n-1, l, r, 0);
//        cout<<l<<" "<<r<<" "<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<endl;
        return temp[2];
    }

    void build(int ss, int se, int idx) {
        if (ss == se) {
            tL[idx] = a[ss];
            tR[idx] = a[ss];
            tM[idx] = a[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * idx + 1);
        build(mid + 1, se, 2 * idx + 2);
        // Tree Manipulation
        tM[idx] = max(tM[2*idx+1], tM[2*idx+2]);
//        ll curTM = max(max(curTL, curTR), tR[2*idx+1]+tL[2*idx+2]);
        tL[idx] = max(tL[2*idx+1], prefixSum[mid]-prefixSum[ss-1]+tL[2*idx+2]);
        tR[idx] = max(tR[2*idx+2], prefixSum[se]-prefixSum[mid]+tR[2*idx+1]);

        tM[idx] = max(tM[idx], tL[2*idx+2]+tR[2*idx+1]);
    }

    /**interface to call build function*/
    void build() {
        build(0, n - 1, 0);
    }

};
int main() {
    FAST
    int n;
    cin >> n;
    SegTree seg(n+1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> seg.a[i];
        prefixSum[i] = prefixSum[i-1]+seg.a[i];
    }
    for (int i = 0; i < 4 * n+4; ++i) {
        seg.tL[i] = -INF;
        seg.tR[i] = -INF;
        seg.tM[i] = -INF;
    }
    seg.build();
    int m;
    cin >> m;
//    for (int i = 0; i < 4 * n; ++i) {
//        cout<<i<<" : "<<seg.tL[i]<<" "<<seg.tR[i]<<" "<<seg.tM[i]<<endl;
//    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        cout<<seg.get(l, r)<<endl;
    }
}
