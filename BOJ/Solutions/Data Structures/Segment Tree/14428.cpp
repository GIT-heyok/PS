#include <bits/stdc++.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
#define endl '\n'
const int MAX = 1e9;
struct segtree{
    int n;
    vector<int> a , t, t2;
    segtree(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
        t2.resize(4*n);
    }

    void update(int ss, int se, int ii, int idx ,int value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if(ii>se || ii<ss)
            return;
        if(ii==ss&&ss==se){
            t[idx] = value;
            return;
        }
        int mid = (ss+se)/2;
        update(ss, mid , ii, 2*idx+1 , value);
        update(mid+1, se, ii ,2*idx+2 , value);
        if(t[2*idx+1]<=t[2*idx+2]){
            t[idx] = t[2*idx+1];
            t2[idx] = t2[2*idx+1];
        }
        else{
            t[idx] = t[2*idx+2];
            t2[idx] = t2[2*idx+2];
        }
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int ii, int val)
    {
        update(0 , n-1, ii, 0 , val);
    }

    pair<int, int> get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return {MAX, 0};
        if(qs<=ss&&qe>=se){
            return {t[idx], t2[idx]};
        }
        int mid = (ss+se)/2;
        pair<int,int> p1 = get(ss, mid, qs, qe, 2*idx+1);
        pair<int,int> p2 = get(mid+1, se, qs, qe, 2*idx+2);
        if(p1.first<=p2.first){
            return p1;
        }
        else return p2;
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    int get(int l, int  r)
    {
        return get(0 , n-1, l, r , 0).second;

    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            t[idx] = a[ss];
            t2[idx] = ss+1;
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        if(t[2*idx+1]<=t[2*idx+2]){
            t[idx] = t[2*idx+1];
            t2[idx] = t2[2*idx+1];
        }
        else{
            t[idx] = t[2*idx+2];
            t2[idx] = t2[2*idx+2];
        }
    }

    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }


};
int main() {
    FAST
    int n;
    cin >> n;
    segtree seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg.a[i];
    }
    seg.build();
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            seg.update(b-1, c);
        }
        else{
            cout<<seg.get(b-1,c-1)<<endl;
//            for (int j = 0; j < seg.t.size(); ++j) {
//                cout<<seg.t[j]<<" ";
//            }
//            cout<<endl;
//            for (int j = 0; j < seg.t.size(); ++j) {
//                cout<<seg.t2[j]<<" ";
//            }
//            cout<<endl;
        }
    }
}
