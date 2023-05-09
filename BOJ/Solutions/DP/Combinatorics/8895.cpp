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
const int MAX = 10001;
const ll INF = 1e12;
const int inf = 1234567890;
const ll MOD = 1e9 + 7;

/*
memo[n][l][r]: cases l left and r right from n sticks
order: select longest stick first -> it makes every other
sticks smaller.
therefore, placing in leftmost: l++, 1 case
rightmost: r++, 1 case
in the middle: no change, n-1 case

*/
int main()
{
    FAST 
    int T;
    cin >> T;
    ll memo[21][21][21];
    memset(memo, 0, sizeof(memo));
    memo[1][1][1] = 1;
    for (int i = 1; i < 20; i++)
    {
        for (int a = 0; a < 20; a++)
        {
            for (int b = 0; b < 20; b++)
            {
                memo[i + 1][a + 1][b] += memo[i][a][b];
                memo[i + 1][a][b + 1] += memo[i][a][b];
                memo[i + 1][a][b] += memo[i][a][b] * (i - 1);
            }
        }
    }
    while(T--){
        int n, l, r;
        cin >> n >> l >> r;
        cout<<memo[n][l][r]<<endl;
    }
}
