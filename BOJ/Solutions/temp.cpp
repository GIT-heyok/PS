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
const int inf = (1<<29);
const ll MOD = 1e9 + 7;
int getDist(pI a, pI b){
    int x = a.first-b.first;
    int y = a.second-b.second;
    return x*x+y*y;
}
int main() {
    FAST

    int n;
    cin >> n;
    vector<pair<pI,int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        int val = 1;
        if(x<0){x=-x;val++;}
        if(y<0){y=-y;val+=2;}
        arr[i]={{x,y},val};
        cout<<arr[i].first.first<<" "<<arr[i].first.second<<arr[i].second<<endl;
    }
    sort(all(arr));
    set<pI> s;
    int mnm = getDist(arr[0].first, arr[1].first);
    cout<<arr[0].first.first<<" "<<arr[0].first.second<< " "<<arr[1].first.first<<" "<<arr[1].first.second<<endl;
    s.insert({arr[0].first.second, arr[0].first.first});
    s.insert({arr[1].first.second, arr[1].first.first});
    int idx = 0;
    for (int i = 2; i < n; ++i) {
        cout<<mnm<<endl;
        while(idx<i){
            int d = arr[i].first.first - arr[idx].first.first;
            if(d*d<=mnm)break;
            s.erase({arr[idx].first.second,arr[idx].first.first});
            idx++;
        }
        auto start = s.lower_bound({arr[i].second-sqrt(mnm),-inf});
        auto end= s.upper_bound({arr[i].second+sqrt(mnm),inf});
        for (auto it=start; it!=end; ++it) {
            mnm = min(mnm, getDist({it->second, it->first}, arr[i].first));
            cout<<it->second<<" "<<it->first<<" "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
        }
        s.insert({arr[i].first.second, arr[i].first.first});
    }
    cout<<mnm<<endl;
}
