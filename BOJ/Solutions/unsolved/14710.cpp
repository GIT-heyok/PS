#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>

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
const int MAX = 500001;
const int INF = 123456780;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
vi arr(100001);
vector<FenwickTree> bucket(320, FenwickTree(10001));


int sq;
int n, m;
void init(){
    sq = sqrt(n);
    for (int i = 1; i <= n; i++)
    {  
        bucket[i/sq].add(arr[i], 1);
    }
}

void update(int idx, int val){
    
    int id = idx/sq;
    int s = id*sq;
    int e = s+sq;
    int curVal = arr[idx];
    bucket[id].add(curVal,-1);
    bucket[id].add(val,1);
    arr[idx] = val;
}

int query(int l, int r, int k){
    int ret  = 0;
    while(l%sq!=0&&l<=r){
        if(arr[l++]>k)ret++;
    }
    while((r+1)%sq!=0&&l<=r)
        if(arr[r--]>k)ret++;
    while(l<=r){
        ret += bucket[l/sq].sum(1,10000)-bucket[l/sq].sum(1,k);
        l+=sq;
    }
    return ret;
}
int main()
{
    FAST
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    init();
    cin >> m;
    for (int qq = 0; qq < m; qq++)
    {
        int type;
        cin >> type;
        if(type==2){
            int a, b, c;
            cin >> a >> b >> c;
            cout<<query(a,b,c)<<endl;
        }
        else if(type==1){
            int a, b;
            cin >> a >> b;
            update(a, b);
        }

    }
    
    
    }