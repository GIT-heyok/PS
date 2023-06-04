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
const int MAX = 100001;
const int MAX_DEPTH = 16;
const ll INF = 1e12;
const int inf = (1 << 29);
const ll MOD = 1e9 + 7;

/*
LCS with DP
*/
int main()
{
    FAST
        string s1,
        s2;
    cin >> s1 >> s2;
    int arr[s1.size() + 1][s2.size() + 1];
    int ans = 0;
    memset(arr, 0,sizeof(arr));
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if(s1[i-1]==s2[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
                ans = max(arr[i][j], ans);
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    cout<<ans<<endl;
}
