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
const int MAX = 51;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e4 + 7;

int main()
{
    FAST
    int n, m;
    cin >> n >> m;
    int memo[m+1][n+1];
    int arr[m+1][n+1];
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int i2 = 0; i2 <= m; i2++)
        {
            arr[i2][0] = 0;
            cin >> arr[i2][i1];
        }
    }
    memset(memo, 0, sizeof(memo));

    for (int i1 = 1; i1 <= m; i1++)
    {
        for (int i2 = 0; i2 <= n; i2++)
        {
            for (int i3 = 0; i2+i3 <= n; i3++)
            {
                memo[i1][i2+i3] = max(memo[i1][i2+i3],memo[i1-1][i2]+arr[i1][i3]);
            }
        }
    }
    int mxm = 0;
    int curVal = 0;
    for (int i = 0; i <= n; i++)
    {
        if(memo[m][i]>mxm){
            mxm = memo[m][i];
            curVal = i;
        }
    }
    
    cout<<memo[m][curVal]<<endl;
    vector<int> ans(m+1);
    for (int i1 = m; i1 > 0; i1--)
    {
        for (int i2 = 0; i2 <= curVal; i2++)
        {
            if(memo[i1-1][curVal-i2]+arr[i1][i2]==memo[i1][curVal]){
                curVal -=i2;
                ans[i1] = i2;
                break;
            }
        }
        
    }
    for (int i = 1; i <= m; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
     

}