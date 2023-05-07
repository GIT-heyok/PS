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
const int MAX = 50001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1000;
ll n, k;
/*basic parametric search
    set an arbitrary value of mid,
    and checking how many numbers are less than
    mid can be done in O(n).
    therefore, O(nlogn)
*/
ll parametric(){
    ll start = 1;
    ll end = n*n;
    ll ans = end;
    while(start<=end){
        ll mid = (start+end)/2;
        ll val = 0;
        for (ll i = 1; i <= n; i++)
        {
            val += min(n, mid/i);   
        }
        if(val>=k){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main()
{
    FAST
    cin >> n >> k;
    cout<<parametric()<<endl;;
    
}

