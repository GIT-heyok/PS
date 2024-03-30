#include <bits/stdc++.h>
#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
using namespace std;
//#define endl '\n'
typedef long long ll;
ll prefixSum[400001];
struct SegTree{
    int n;
    vector<ll> a , sum, cnt;
    SegTree(int sz){
        n = sz;
        a.resize(n);
        sum.resize(4*n);
        cnt.resize(4*n);
    }
    void update(int ss, int se, int qs, int qe, int idx ,ll value)
    {
        int mid = (ss+se)/2;
        if(qs<=ss && qe>=se)
        {
            cnt[idx]+=value;
        }
        else{
            if(qs<=mid)
                update(ss, mid , qs, qe, 2*idx+1 , value);
            if(qe>mid)
                update(mid+1, se, qs ,qe ,2*idx+2 , value);
        }
        if(cnt[idx]==0){
            if(ss==se)sum[idx] = 0;
            else
                sum[idx] = sum[2*idx+1] + sum[2*idx+2];
        }
        else{

            sum[idx]=prefixSum[se+1]-prefixSum[ss];
        }
    }

    /**interface to call update function
     * l and r in this function is 0-indexed
     */
    void update(int l, int r, ll val)
    {
        update(0 , n-1, l, r, 0 , val);
    }

    ll get(int ss, int se, int qs, int qe, int idx)
    {
        if(qs>se || qe<ss)
            return 0;
        if(qs<=ss && qe>=se)
            return sum[idx];

        int mid = (ss+se)/2;
        return get(ss, mid, qs ,qe , 2*idx+1) + get(mid+1 , se, qs , qe, 2*idx+2);
    }

    /**interface to call get function
     * l and r in this function is 0-indexed
     */
    ll get(int l, int r)
    {
        return get(0 , n-1, l , r , 0);

    }
    void build(int ss, int se, int idx)
    {
        if(ss==se)
        {
            sum[idx] = a[ss];
            cnt[idx] = a[ss];
            return;
        }
        int mid= (ss+se)/2;
        build(ss , mid , 2*idx+1);
        build(mid+1, se,2*idx+2);
        sum[idx] = sum[2*idx+1] + sum[2*idx+2];
        cnt[idx] =cnt[2*idx+1] +cnt[2*idx+2];
    }

    /**interface to call build function*/
    void build()
    {
        build(0 , n-1, 0);
    }

};
vector<int> yindices;
int getCompressedIndex(int a) {
    return lower_bound(yindices.begin(), yindices.end(), a) - yindices.begin();
}
int main()
{
    FAST
    int n;
    cin >> n;
    //x1 y1 y2 +1 if in 0 if out
    vector<pair<pair<ll, ll>, pair<ll,ll>>> rectangles;
    for (int i = 0; i < n; ++i) {
        pair<pair<ll,ll>,pair<ll,ll>> p1, p2;
        cin >> p1.first.first;
        cin >> p2.first.first;
        cin >> p1.first.second >> p1.second.first;
        p1.second.second = 1;
        p2.first.second = p1.first.second;
        p2.second.first = p1.second.first;
        p2.second.second = -1;
        rectangles.push_back(p1);
        rectangles.push_back(p2);
        yindices.push_back(p1.first.second);
        yindices.push_back(p2.second.first);
    }
    //YINDICES ARE 0-INDEXED AND PREFIX SUM IS 1-INDEXED
    sort(yindices.begin(), yindices.end());
    yindices.erase(unique(yindices.begin(),yindices.end()),yindices.end());

    prefixSum[1] = yindices[0];
    for (int i = 2; i <= yindices.size(); ++i) {
        prefixSum[i]=prefixSum[i-1]+(yindices[i-1]-yindices[i-2]);
    }

    sort(rectangles.begin(), rectangles.end());
    SegTree seg(2*n);
    for (int i = 0; i < 2*n; ++i) {
        seg.a[i] = 0;
    }
    seg.build();

    ll sum = 0;
    ll curX = rectangles[0].first.first;
    for (int i = 0; i < 2 * n; ++i) {
        ll x1 = rectangles[i].first.first;
        ll y1 = rectangles[i].first.second;
        ll y2 = rectangles[i].second.first;
        ll type = rectangles[i].second.second;
        sum += seg.sum[0]*(x1-curX);
        seg.update(getCompressedIndex(y1)+1, getCompressedIndex(y2), type);
        curX = x1;
    }
    cout<<sum<<endl;

}
