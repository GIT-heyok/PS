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

const int MAX = 1000001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 9901;


int main(){
    FAST
    ll pow[10000];
    pow[0]=1;
    for (int i = 1; i < 10000; i++)
    {
        pow[i] = pow[i-1]*2;
        pow[i]%=MOD;
    }
    
    
    int n;
    cin>>n;
        ll ans = 0;
        int cnt = 0;
        int rcnt = 0;
        while(n>0){
            if(rcnt==0){
                rcnt=cnt+1;
                cnt++;
            }
            ans+=pow[cnt-1];
            ans%=MOD;
            rcnt--;
            n--;
        }
     cout<<ans<<endl;
}