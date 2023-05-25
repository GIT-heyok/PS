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
ll getDist(pI a, pI b){
    int x = a.first-b.first;
    int y = a.second-b.second;
    return (ll)x*x+y*y;
}
int main() {
    FAST

    int n;
    cin >> n;
    vector<pair<pLL,int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        int val = 1;
        if(x<0){x=-x;val++;}
        if(y<0){y=-y;val+=2;}
        arr[i]={{x,y},val*100000+i};
//        cout<<arr[i].first.first<<" "<<arr[i].first.second<<arr[i].second<<endl;
    }
    int conv[5] = {0,4,3,2,1};
    sort(all(arr));
    set<pair<pLL,int>> s;
    ll mnm = getDist(arr[0].first, arr[1].first);
//    cout<<arr[0].first.first<<" "<<arr[0].first.second<< " "<<arr[1].first.first<<" "<<arr[1].first.second<<endl;
    s.insert({{arr[0].first.second, arr[0].first.first},arr[0].second});
    s.insert({{arr[1].first.second, arr[1].first.first},arr[1].second});
    int idx = 0;
    int a1=arr[0].second%100000+1;
    int a2=arr[1].second%100000+1;
    int v1=arr[0].second/100000;
    int v2=arr[1].second/100000;
    v2 = conv[v2];
    for (int i = 2; i < n; ++i) {
//        cout<<mnm<<endl;
        while(idx<i){
            int d = arr[i].first.first - arr[idx].first.first;
            if(d*d<=mnm)break;
            s.erase({{arr[idx].first.second,arr[idx].first.first},arr[idx].second});
            idx++;
        }
        auto start = s.lower_bound({{arr[i].first.second-sqrt(mnm)-1,-inf},0});
        auto end= s.upper_bound({{arr[i].first.second+sqrt(mnm)+1,inf},500000});
        for (auto it=start; it!=end; ++it) {
            ll dis = getDist({it->first.second, it->first.first}, arr[i].first);
            if(mnm>dis){
                mnm = dis;
                a1 = (arr[i].second%100000)+1;
                a2 = (it->second%100000)+1;
                v1 = arr[i].second/100000;
                v2 = it->second/100000;
                v2 = conv[v2];
//                cout<<it->first.second<<" "<<it->first.first<<" "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
            }
//            cout<<it->first.second<<" "<<it->first.first<<" "<<arr[i].first.first<<" "<<arr[i].first.second<<endl;
        }
        s.insert({{arr[i].first.second, arr[i].first.first},arr[i].second});
    }
    cout<<a1<<" "<<v1 <<" " <<a2<<" "<<v2<<endl;
}
