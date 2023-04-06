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
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;

int main(){
	FAST
    int n;
    cin >> n;
    vector<pLL> vec(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;

       if(a==0||b==0){
    
        if(a==0){
            if(b>0){
                b = 1;
            }
            else{
                b=-1;
            }
        }
        if(b==0){
            if(a<0){
                a=-1;
            }
            else{
                a=1;
            }
        }}
        else{
        ll gcd = __gcd(abs(a), abs(b));
        a/=gcd;
        b/=gcd;
        }
        vec[i] = {a, b};
    }
    sort(all(vec));
    int ans = 1;
    pLL cur = vec[0];
    int curMax = 1;
    for (int i = 1; i < n; i++)
    {
        if(cur.first==vec[i].first&&cur.second==vec[i].second){
            curMax++;
        }
        else{
            ans = max(curMax, ans);
            curMax = 1;
            cur = vec[i];
            
        }
    }
    cout<<ans<<endl;
    
    
}


