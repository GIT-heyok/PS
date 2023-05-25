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
const int inf = (1<<30);
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
    vector<pI> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(all(arr));
    set<pI> s;
    int mnm = getDist(arr[0], arr[1]);
    s.insert({arr[0].second, arr[0].first});
    s.insert({arr[1].second, arr[1].first});
    int idx = 0;
    for (int i = 2; i < n; ++i) {
        while(idx<i){
            int d = arr[i].first - arr[idx].first;
            if(d*d<=mnm)break;
            s.erase({arr[idx].second,arr[idx].first});
            idx++;
        }
        auto start = s.lower_bound({arr[i].second-sqrt(mnm),-inf});
        auto end= s.upper_bound({arr[i].second+sqrt(mnm),inf});
        for (auto it=start; it!=end; ++it) {
            mnm = min(mnm, getDist({it->second, it->first}, arr[i]));
        }
        s.insert({arr[i].second, arr[i].first});
    }
    cout<<mnm<<endl;
}
