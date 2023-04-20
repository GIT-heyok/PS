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

const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 987654321;

/*
let N/2=n: meaningful pair,
drawing a line: making two different areas.
and different area = same problem.

1. dp[n+1] and dp[0], dp[1]=1;
dp[i+1] = dp[0]*dp[i]+dp[1]*dp[i-1]+...+dp[i]*dp[0];
2. optimization by cutting indices in half
3. print dp[n]
*/
int main(){
    FAST
    int n;
    cin >> n;
    n/=2;
    ll dp[n+1];
    dp[0]=1, dp[1]=1;
    for (int i = 2; i <= n; i++)
    {
        ll& temp = dp[i];
        temp = 0;
        for (int j = 0; j < i/2; j++)
        {
            temp+=2*dp[j]*dp[i-j-1];
            temp%=MOD;
        }
        if(i%2==1){
            temp+=dp[i/2]*dp[i/2];
            temp%=MOD;
        }

    }
    cout<<dp[n]<<endl;
    

}