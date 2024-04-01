#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
typedef long long ll;
struct segtree{
    int n;
    vector<int> a, t;
    segtree(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
    }

    void update(int ss, int se, int ii, int idx ,int value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if(ii>se || ii<ss)
            return;
        if(ii==ss&&ss==se){
            t[idx] += value;
            return;
        }
        int mid = (ss+se)/2;
        update(ss, mid , ii, 2*idx+1 , value);
        update(mid+1, se, ii ,2*idx+2 , value);
        t[idx] = t[idx*2+1]+t[idx*2+2];
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int ii, int val)
    {
        update(0 , n-1, ii, 0 , val);
    }

    int get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return 0;
        if(qs<=ss&&qe>=se){
            return t[idx];
        }
        int mid = (ss+se)/2;
        return get(ss, mid, qs, qe, 2*idx+1) + get(mid+1, se, qs, qe, 2*idx+2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    int get(int l, int  r)
    {
        return get(0 , n-1, l, r , 0);

    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            t[idx] = a[ss];
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        t[idx] = t[2*idx+1]+t[2*idx+2];
    }

    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }


};
typedef long long ll;
bool comp(const pair<int, int> p1, const pair<int,int> p2 ){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first>p2.first;
}

vector<pair<int, int>> vec;
vector<int> coordinates;
int getIdx(int i){
    return lower_bound(coordinates.begin(), coordinates.end(), i)-coordinates.begin();
}

int main(void) {
    FAST
    int TC;
    cin >> TC;
    while(TC--){
        int n;
        cin >> n;
        vec.clear();
        vec.resize(n);
        coordinates.clear();
        for (int i = 0; i < n; ++i) {
            cin >> vec[i].first >> vec[i].second;
            coordinates.push_back(vec[i].second);
        }
        sort(vec.begin(), vec.end(), comp);
        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());
        segtree seg(coordinates.size());
        for (int i = 0; i < coordinates.size(); ++i) {
           seg.a[i] = 0;
        }

        seg.build();
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
//            cout<<vec[i].first<<" "<<vec[i].second<<endl;
            ans += seg.get(0, getIdx(vec[i].second));
           seg.update(getIdx(vec[i].second),1);
        }
        cout<<ans<<endl;
//        cout<<getIdx(vec[0].second);
//        cout<<getIdx(vec[1].second);
//        cout<<getIdx(vec[2].second);
//        cout<<getIdx(vec[3].second);
    }
}
