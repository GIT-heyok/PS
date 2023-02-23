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
vi arr(100001);
vector<vi> bucket(320, vi());

int sq;
int n, m;
void init(){
    sq = sqrt(n);
    for (int i = 1; i <= n; i++)
    {  
        bucket[i/sq].push_back(arr[i]);
        if(i%sq==0){
            sort(all(bucket[i/sq-1]));
        }
    }
    sort(all(bucket[n/sq]));
}

void update(int idx, int val){
    
    int id = idx/sq;
    int s = id*sq;
    int e = s+sq;
    int curVal = arr[idx];
    int curPos = lower_bound(all(bucket[id]), curVal)-bucket[id].begin();
    bucket[id][curPos] = val;
    sort(all(bucket[id]));
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
        ret += bucket[l/sq].size()-(upper_bound(all(bucket[l/sq]), k)-bucket[l/sq].begin());
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
        if(type==1){
            int a, b, c;
            cin >> a >> b >> c;
            cout<<query(a,b,c)<<endl;
        }
        else if(type==2){
            int a, b;
            cin >> a >> b;
            update(a, b);
        }

    }
    
    
    }