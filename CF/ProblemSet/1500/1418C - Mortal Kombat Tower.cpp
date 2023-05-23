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

 
int main()
{
    FAST
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int memo[n+1][2][2];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    memo[i][j][k] = inf;
                }
            }
            
        }
        memo[0][0][0] = arr[0];
        for (int i = 0; i < n-1; i++)
        {
            memo[i+1][0][0] = arr[i+1]+min(memo[i][1][0],memo[i][1][1]);
            memo[i+1][1][0] = min(memo[i][0][0],memo[i][0][1]);
            memo[i+1][0][1] = arr[i+1]+memo[i][0][0];
            memo[i+1][1][1] = memo[i][1][0];
        }
        int ans = inf;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                ans = min(ans, memo[n-1][i][j]);
            }   
        }
        cout<<ans<<endl;
        
        
        
    }
} 