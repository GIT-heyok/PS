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
const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
const double PI = 3.14159265358979;

int main(){
	FAST
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int n, k;
        cin >> n >> k;
        
        pair<double, int> r[n], h[n], hs[n];
        
        for (int i = 0; i < n; i++)
        {
            cin >> r[i].first >> h[i].first;
            h[i].first*=2*PI*r[i].first;
            r[i].second = i;
            h[i].second = i;
            hs[i].first = h[i].first;
            hs[i].second = h[i].second;
        }
        sort(&hs[0], &hs[n]);
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<hs[i].first<<endl;
        // }
        
        double op1 = 0;
        bool chk[n];
        for (int i = 0; i < n; i++)
        {
            chk[i] = false;
       }
        for (int i = 0; i <k-1; i++)
        {
            op1+=hs[n-1-i].first;
            chk[hs[n-1-i].second] = true;
        }
        double ans = 0;
        // cout<<op1<<endl;
        for (int i = 0; i < n; i++)
        {
            if(chk[i]){
                op1+=hs[n-k].first;
                // cout<<i<<" "<<op1<<" "<<PI*r[i].first*r[i].first<<endl;
                ans=max(ans,op1+PI*r[i].first*r[i].first);
                op1-=hs[n-k].first;
            }
            else{
                op1+=h[i].first;
                // cout<<i<<" "<<op1<<" "<<PI*r[i].first*r[i].first<<endl;
                ans=max(ans,op1+PI*r[i].first*r[i].first);
                op1-=h[i].first;
            }
        }
        cout << fixed;
        cout.precision(10);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    
}


