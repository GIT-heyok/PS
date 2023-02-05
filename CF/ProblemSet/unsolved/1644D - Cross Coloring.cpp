#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
 
#define FAST ios::sync_with_stdio(false);\
cin.tie(nullptr);\
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
const int INF = 1234567890;

int main(){
    FAST
    int T;
    cin >> T;
    while(T--){
        int n, m, q;
        ll k;
        cin >> n >> m >> k >> q;
        vi rows(q), columns(q);
        for(int i=0; i<q; i++){
            int x, y;
            cin >> x >> y;
            rows.push_back(x);
            columns.push_back(y);
        }
        int columnSweep, rowSweep;
        rowSweep = *min_element(all(rows));
        columnSweep = *min_element(all(columns));
        // cout<< rowSweep<<" "<<columnSweep<<endl;
        vi cnt(q+1, 0);
            for(int i=1; i<=n; i++){
                if(rows[i]>=columnSweep&&rows[i]!=0){
                    cnt[rows[i]] = 1;
                }
            }
             for(int i=1; i<=m; i++){
                // cout<<columns[i]<<" ";
                if(columns[i]>=rowSweep&&columns[i]!=0){
                    cnt[columns[i]]=1;
                }
            }
            // cout<<endl;
        int pow = accumulate(all(cnt),0);
        const ll mod = 998244353;
        ll ans = 1;
        for(int i=0; i<pow; i++){
            ans *= k;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
}