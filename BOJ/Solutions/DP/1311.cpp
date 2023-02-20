#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
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
const int MAX = 500001;
const ll INF = 12345670;



int main()
{
    FAST
    // n people and n works
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vi> memo(n, vi(1<<n, INF));
    
    for (int i = 0; i < n; i++)
    {
        memo[0][1<<i] = arr[i][0]; //memo is work, counted bits
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < (1<<n); j++)
        {
            if(__builtin_popcount(j)==i){
                for (int k = 0; k < n; k++)
                {
                    if(!(j&(1<<k))){ //not yet
                    memo[i][j+(1<<k)] = min(memo[i][j+(1<<k)], memo[i-1][j]+arr[k][i]);
                    }
                }
            }
            
            
        }
        
    }
    
    cout<<memo[n-1][(1<<n)-1]<<endl;
    
    
    
}