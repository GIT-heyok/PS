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
const int MAX = 10001;
const ll INF = 1e9;
int main()
{
    FAST
        /*  1. only needs to divide it into 4 different parts = find 3 possible breakpoints!
            2. index i, j, k -> [0,i) [i, j), [j,k), [k,n)
            3. 4 parts -> two and two.
        */
    int n;
    cin >> n;
    ll arr[n+1];
    fill(arr, arr+n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i]+=arr[i-1];
    }
    // for (int i = 1; i < n+1; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    if(arr[n]%4!=0)
        cout<<0<<endl;
    else{
        vll lq(n,0), uq(n,0);
        for (int i = 0; i < n; i++)
        {
            if(i)
            lq[i] = lq[i-1];
            if(arr[i+1]==arr[n]/4) lq[i]++;  
        }
        for (int i = n-2; i >=0; i--)
        {
            if(i<n-1)
            uq[i] = uq[i+1];
            if(arr[i+1]==arr[n]/4+arr[n]/2) uq[i]++;  
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<lq[i]<<" ";
        // }
        // cout<<endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<uq[i]<<" ";
        // }
        // cout<<endl;
        ll ans = 0;
        for (int i = 1; i < n-2; i++)
        {
            if(arr[i+1]==arr[n]/2){
                ans += lq[i-1]*uq[i+1];
            }
        }
        cout<<ans<<endl;
         
    }
    
    
}
