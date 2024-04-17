#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

pair<ll, ll> firstTwoNumbers(pair<ll, ll> p1, pair<ll, ll> p2){
    vector<ll> vec;
    vec.push_back(p1.first), vec.push_back(p1.second), vec.push_back(p2.first), vec.push_back(p2.second);
    sort(vec.begin(), vec.end());
    return {vec[vec.size()-1], vec[vec.size()-2]};
}

struct SegTree {
    int n;
    vector<ll> a;
    vector<pair<ll, ll>> t;

    SegTree(int sz) {
        n = sz;
        a.resize(n);
        t.resize(4 * n);
    }

    void update(int ss, int se, int ii, int idx, ll value) {
        if (ii > se || ii < ss)
            return;
        if (ii == ss && ss == se) {
            t[idx].first = value;
            return;
        }
        int mid = (ss + se) / 2;
        update(ss, mid, ii, 2 * idx + 1, value);
        update(mid + 1, se, ii, 2 * idx + 2, value);
        // Tree manipulation
        t[idx] = firstTwoNumbers(t[2*idx+1], t[2*idx+2]);
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int ii, ll val) {
        update(0, n - 1, ii, 0, val);
    }

    pair<ll, ll> get(int ss, int se, int qs, int qe, int idx) {
        // out of bound
        if (qs > se || qe < ss)
            return {0,0};
        if (qs <= ss && qe >= se) {
            return t[idx];
        }
        int mid = (ss + se) / 2;
        // Tree Manipulation
        auto p1 = get(ss, mid, qs, qe, 2 * idx + 1);
        auto p2 = get(mid+1, se, qs, qe, 2 * idx + 2);
        return firstTwoNumbers(p1, p2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    pair<ll, ll> get(int l, int r) {
        return get(0, n - 1, l, r, 0);

    }

    void build(int ss, int se, int idx) {
        if (ss == se) {
            t[idx].first = a[ss];
            t[idx].second = 0;
            return;
        }
        int mid = (ss + se) / 2;
        build(ss, mid, 2 * idx + 1);
        build(mid + 1, se, 2 * idx + 2);
        // Tree Manipulation
        t[idx] = firstTwoNumbers(t[2*idx+1], t[2*idx+2]);
    }

    /**interface to call build function*/
    void build() {
        build(0, n - 1, 0);
    }

};

int main()
{
    FAST
    int n;
    cin >> n;
    SegTree seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg.a[i];
    }
    seg.build();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type==1){
            seg.update(a-1, b);
        }
        else{
            auto temp = seg.get(a-1, b-1);
            cout<<temp.first+temp.second<<endl;
        }
    }
}
