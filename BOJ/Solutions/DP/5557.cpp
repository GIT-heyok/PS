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
first number is always positive
and last number is equal!
*/
int main(){
    FAST 
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 1; i < n+1; i++)
    {
        cin >> arr[i];
    }
    ll memo[n+1][21];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            memo[i][j] = 0;
        }
    }
    memo[1][arr[1]]=1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
           
            if(j-arr[i]>=0){
                memo[i][j-arr[i]] += memo[i-1][j];
            }
            if(j+arr[i]<=20){
                memo[i][j+arr[i]]+=memo[i-1][j];
            }
        }
    }
    ll ans = 0;
        ans+=memo[n-1][arr[n]];
    cout<<ans<<endl;
    
    
    
    
} 
