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
const int MAX = 4000001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9+7;
ll factorial[MAX];

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

ll modInverse(ll A, ll M)
{
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return 0;
    else {
 
        // m is added to handle negative x
        ll res = (x % M + M) % M;
        return res;
    }
}
 
int main()
{
    FAST
    factorial[0]=1;
    for (int i = 1; i < MAX; i++)
    {
        factorial[i]=i*factorial[i-1];
        factorial[i]%=MOD;
    }
    int M;
    cin >> M;
    while(M--){
    ll n, k;
    cin >> n >> k;
     cout<<factorial[n]*modInverse(factorial[k],MOD)%MOD*modInverse(factorial[n-k],MOD)%MOD<<endl;
    }
} 