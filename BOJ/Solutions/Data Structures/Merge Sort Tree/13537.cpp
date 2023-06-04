#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

#define FAST                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pI;
typedef pair<ll, ll> pLL;
typedef pair<double, double> pD;
const int MAX = 100001;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e9 + 7;

/*
Merge sort tree? yes...
*/
int n;

vector<int> segTree[4*MAX];
int a[MAX];
void build(int node, int start, int end){
    if(start==end){
        segTree[node].push_back(a[start]);
        return;
    }
    int ptr1 = 0;
    int ptr2 = 0;
    int mid = (start+end)/2;
    build(node*2+1, start, mid);
    build(node*2+2, mid+1, end);
    vector<int>& seg1 = segTree[node*2+1];
    vector<int>& seg2 = segTree[node*2+2];
    vector<int>& segorig = segTree[node];
    while(ptr1<seg1.size()&&ptr2<seg2.size()){
        if(seg1[ptr1]<seg2[ptr2]){
            segorig.push_back(seg1[ptr1]);
            ptr1++;
        }  
        else{
            segorig.push_back(seg2[ptr2]);
            ptr2++;
        }
    }
    while(ptr1<seg1.size()){
        segorig.push_back(seg1[ptr1]);
        ptr1++;
    }
    while(ptr2<seg2.size()){
        segorig.push_back(seg2[ptr2]);
        ptr2++;
    }

}

int query(int l, int r, int start, int end, int node, int k){
    if(end<l||start>r){
        return 0;
    }
    if(start>=l&&end<=r){
        return segTree[node].size()-(upper_bound(all(segTree[node]), k)-segTree[node].begin());
    }
    int mid = (start+end)/2;
    return query(l,r,start, mid, node*2+1, k)+query(l,r,mid+1, end, node*2+2, k);
}
int main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0,0,n-1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout<<query(l-1,r-1,0, n-1,0,k)<<endl;
    }
    
}
