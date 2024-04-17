#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

struct segtree{
    int n;
    vector<ll> a , t;
    segtree(int sz){
        n = sz;
        a.resize(n);
        t.resize(4*n);
    }

    void update(int ss, int se, int ii, int idx ,ll value)
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
    void update(int ii, ll val)
    {
        update(0 , n-1, ii, 0 , val);
    }

    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss) //out of bound
            return 0;
        if(qs<=ss&&qe>=se){
            return t[idx];
        }
        int mid = (ss+se)/2;
        return get(ss, mid, qs, qe , 2*idx+1)+get(mid+1 , se, qs, qe, 2*idx+2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int  r)
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
        t[idx] = t[2*idx+1]+ t[2*idx+2];
    }

    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }

};
//updating only if lazy is an odd number
int main()
{
    FAST
    int  type , l ,r ,q , n;
    ll val , ans;
    cin >> n;
    segtree seg(n);
    for(int i=0; i<n; i++){
        cin >> seg.a[i];
    }

    cin >> q;
    seg.build();
    vector<pair<pair<int,int>,pair<int,int>>> commands;
    int queryCnt = 1;
    int ansCnt = 0;
    for(int i=1; i<=q; i++)
    {
        cin >> type >> l >> r;
        if(type==1){
            commands.push_back({{queryCnt, 1},{l-1, r}});
            queryCnt++;
        }
        else{
            int temp;
            cin >> temp;
            commands.push_back({{l, r-1+100},{temp-1, ansCnt}});
            ansCnt++;
        }
    }
    ll result[ansCnt];
    sort(commands.begin(), commands.end());
    for (int i = 0; i < q; ++i) {
        int query = commands[i].first.first;
        type = commands[i].first.second;
//        cout<<query <<" "<<type<<" "<<commands[i].second.first<<" "<<commands[i].second.second<<endl;
        if(type==1){
           seg.update(commands[i].second.first, commands[i].second.second);
        }
        else{
            result[commands[i].second.second] = seg.get(commands[i].first.second-100, commands[i].second.first);
        }
    }
    for (int i = 0; i < ansCnt; ++i) {
        cout<<result[i]<<endl;
    }

    return 0;
}


