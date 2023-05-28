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

int main() {
    FAST
    int T;
    cin >> T;
    while(T--){
        int k, n;
        cin >> n >> k;
        vll arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vll prefix(n+1), suffix(n+1);
        auto check = [&](ll x){
            for (int i = 0; i < 2; ++i) {
                priority_queue<ll> cur;
                prefix[0] = 0;
                ll curSum = 0;
                for (int j = 0; j < n; ++j) {
                    cur.push(arr[j]);
                    curSum+=arr[j];
                    while(curSum>x){
                        curSum-=cur.top();
                        cur.pop();
                    }
                    prefix[j+1] = cur.size();
                }
                reverse(all(arr));
                swap(prefix, suffix);
            }
            reverse(all(suffix));
            for (int i = 0; i < n + 1; ++i) {
                if(prefix[i]+suffix[i]>=k)return true;
            }
            return false;
        };
        ll l=1, r = accumulate(all(arr), 0ll);
//        cout<<r<<endl;
        ll res = 0;
        while(l<=r){
            ll mid = (l+r)/2;
            if(check(mid)){
                res = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        cout<<res<<endl;

    }
}
