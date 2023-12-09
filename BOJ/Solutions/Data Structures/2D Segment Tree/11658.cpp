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
    vector<int> a , t;
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
            t[idx] = value;
            return;
        }
        int mid = (ss+se)/2;
        update(ss, mid , ii, 2*idx+1 , value);
        update(mid+1, se, ii ,2*idx+2 , value);
        t[idx] = t[2*idx+1]+t[2*idx+2];
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



struct segtree2D{
    int n;
    vector<vector<int>> a;
    vector<segtree> seg;

    segtree2D(int sz){
        n = sz;
        for (int i = 0; i < n; ++i) {
            a.push_back(vector<int>(n));
        }
        for (int i = 0; i < 4 * n; ++i) {
            segtree temp(n);
            seg.push_back(temp);
        }

    }
    void update(int rs, int re, int rr, int cc, int idx ,int value)
    {
        // cout<<idx<<" "<<t[idx]<<endl;
        if(rr>re || rr<rs)
            return;
        if(rr==rs&&rs==re){
            seg[idx].update(cc, value);
            return;
        }
        int mid = (rs+re)/2;
        update(rs, mid , rr, cc, 2*idx+1 , value);
        update(mid+1, re, rr, cc, 2*idx+2 , value);
        seg[idx].update(cc, seg[2*idx+1].get(cc, cc)+seg[2*idx+2].get(cc,cc));
    }
    void update(int rr, int cc, int val)
    {
        update(0 , n-1, rr, cc, 0 , val);
    }

    int get(int ss, int se, int qs, int qe, int c1, int c2, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return 0;
        if(qs<=ss&&qe>=se){
            return seg[idx].get(c1, c2);
        }
        int mid = (ss+se)/2;
        return get(ss, mid, qs, qe, c1, c2,2*idx+1) + get(mid+1, se, qs, qe, c1, c2, 2*idx+2);
    }

    int get(int r1, int r2, int c1, int c2)
    {
        return get(0 , n-1, r1, r2, c1, c2 , 0);

    }
    void build(int rs, int re, int idx){

        if(rs==re){
            seg[idx].a = a[rs];
            seg[idx].build();
            return;
        }
        int mid= (rs+re)/2;
        build(rs , mid , 2*idx+1);
        build(mid+1, re,2*idx+2);
        for (int i = 0; i < 4 * n; ++i) {
            seg[idx].t[i] = seg[2*idx+1].t[i]+seg[2*idx+2].t[i];
        }
    }

    void build(){
        build(0, n-1, 0);
    }
};

int main() {
    FAST
    int n, m;
    cin >> n >> m;
    segtree2D seg2D(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> seg2D.a[i][j];
        }
    }
    seg2D.build();
//    for (int i = 0; i < 4 * n; ++i) {
//        for (int j = 0; j < 4 * n; ++j) {
//            cout<<seg2D.seg[i].t[j]<<" ";
//        }
//        cout<<endl;
//    }
    for (int i = 0; i < m; ++i) {
        int query;
        cin >> query;
        if(query==0){
            int x, y, c;
            cin >> x >> y >> c;
            seg2D.update(x-1,y-1,c);
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout<<seg2D.get(x1-1, x2-1, y1-1, y2-1)<<endl;
        }
    }

}
