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
memo[i][j] means in i-th attempt, there are j things that came from front
and memo[i][j] contains maximum of those
1. i>=j for all times.
2. j cannot be below zero.

          
*/
int main(){
    FAST
    int n;
    cin >> n;
    ll memo[n+1][n+1]; // from front, from back
    int arr[n+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            memo[i][j]=0;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i+1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j<i)
                memo[i][j] = memo[i-1][j]+arr[n-(i-j-1)]*(i);     
            if(j>=1)
                memo[i][j] = max(memo[i][j],memo[i-1][j-1]+arr[j]*i);
            
        }
        
    }
    ll ans = 0;
        for (int j = 0; j < n+1; j++)
        {
            ans = max(ans, memo[n][j]);
        }
        cout<<ans<<endl;
    
    
    
    
}