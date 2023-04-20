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
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 1e7 + 3;

/*
check:
https://nicotina04.tistory.com/47
*/
int seq[100];
int dp[100][100001];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
    FAST;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> seq[i];
        dp[i][seq[i]] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= 100000; ++j)
        {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;

            int cop = gcd(seq[i], j);
            dp[i][cop] += dp[i - 1][j];
            dp[i][cop] %= MOD;
        }
    }

    cout << dp[n - 1][1];
}
