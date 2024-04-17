#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;

vector<ll> coordinates;

ll getCoordinate(ll x) {
    return lower_bound(coordinates.begin(), coordinates.end(), x)-coordinates.begin();
}

//lazy Seg
struct SegTreeLazy {
    int n;
    vector<ll> a, tEndHere, tNotEndHere, lazy;

    SegTreeLazy(int sz) {
        n = sz;
        a.resize(n);
        tEndHere.resize(4 * n);
        tNotEndHere.resize(4 * n);
        lazy.resize(4 * n);
    }

    void propagate(int ss, int se, int idx, int last) {
        // Tree manipulation
        if(se==last){
            tEndHere[idx] += lazy[idx] * (coordinates[se+1] - coordinates[ss]);
        }
        else{
            tNotEndHere[idx] += lazy[idx] * (coordinates[se+1] - coordinates[ss]);
        }

        if (ss != se) {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        // default lazy value
        lazy[idx] = 0;
    }

    void update(int ss, int se, int qs, int qe, int idx, ll value) {
        // defaule lazy value
        if (lazy[idx] != 0)
            propagate(ss, se, idx, qe);
        if (qs > se || qe < ss)
            return;
        if (qs <= ss && qe >= se) {
            // setting the lazy value if
            lazy[idx] = value;
            propagate(ss, se, idx, qe);
            return;
        }
        int mid = (ss + se) / 2;
        update(ss, mid, qs, qe, 2 * idx + 1, value);
        update(mid + 1, se, qs, qe, 2 * idx + 2, value);
        // Tree manipulation
        tEndHere[idx] = tEndHere[2 * idx + 1] + tEndHere[2 * idx + 2];
        tNotEndHere[idx] = tNotEndHere[2 * idx + 1] + tNotEndHere[2 * idx + 2];
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int l, int r, ll val) {
        update(0, n - 1, l, r, 0, val);
    }

    ll get(int ss, int se, int qs, int qe, int idx) {
        // lazy default value
        if (lazy[idx] != 0)
            propagate(ss, se, idx, qe);
        if (qs > se || qe < ss)
            return 0;
        if (qs <= ss && qe >= se){
            if(se==qe){
                return tEndHere[idx];
            }
            else{
                return tNotEndHere[idx];
            }

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
//            t[idx] = a[ss];
            return;
        }
//        int mid = (ss + se) / 2;
//        build(ss, mid, 2 * idx + 1);
//        build(mid + 1, se, 2 * idx + 2);
        // Tree Manipulation
//        t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
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
    vector<tuple<ll, ll, ll, ll, ll>> queries(n);

    int iCnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> get<1>(queries[i]);
        cin >> get<2>(queries[i]);
        cin >> get<3>(queries[i]);
        cin >> get<4>(queries[i]);
        if (get<1>(queries[i]) == 1) {
            iCnt++;
            get<0>(queries[i]) = iCnt;
        }
        else{
            get<0>(queries[i]) = get<4>(queries[i]);
            get<4>(queries[i]) = i;
        }
        coordinates.push_back(get<2>(queries[i]));
        coordinates.push_back(get<3>(queries[i]));
    }
    coordinates.push_back(1e9+1);
    sort(coordinates.begin(), coordinates.end());
    coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
    sort(queries.begin(), queries.end());
//    for (int i = 0; i < n; ++i) {
//        cout<<get<0>(queries[i])<<" ";
//        cout<<get<1>(queries[i])<<" ";
//        cout<<get<2>(queries[i])<<" ";
//        cout<<get<3>(queries[i])<<" ";
//        cout<<get<4>(queries[i])<<" ";
//        cout<<endl;
//    }

//    for (int i = 0; i < coordinates.size(); ++i) {
//        cout<<coordinates[i]<<" ";
//    }
//    cout<<endl;
    SegTreeLazy seg(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        seg.a[i] = 0;
    }
    seg.build();

    vector<pair<int, ll>> ans;
    for (int i = 0; i < n; ++i) {
        ll type = get<1>(queries[i]), l = get<2>(queries[i]), r = get<3>(queries[i]), k = get<4>(queries[i]);
        if (type == 1) {
            seg.update(getCoordinate(l), getCoordinate(r), k);
        } else {
            ans.push_back({k,seg.get(getCoordinate(l), getCoordinate(r))});
        }
    }
    sort(ans.begin(), ans.end());
    for (auto p: ans) {
        cout<<p.second<<endl;
    }
}
