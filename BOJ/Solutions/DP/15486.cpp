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
const ll MOD = 1e6;

/*
going backwards!
dp[i] = max(dp[i+1], p[i]+dp[i+t[i]])
*/
int main(){
    FAST
    int n;
    cin >> n;
    int t[n], p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> t[i]>>p[i];
    }
    int memo[n+1];
    fill(memo, memo+n+1, 0);
    for (int i = n-1; i >= 0; i--)
    {
        if(i+t[i]<=n){
            memo[i] = max(memo[i+1], p[i]+memo[i+t[i]]);
        }
        else{
            memo[i] = memo[i+1];
        }
    }
    cout<<memo[0]<<endl;
     
    
} 