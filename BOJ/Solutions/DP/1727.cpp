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

const ll INF = 1e12;
const int inf = 1e9;
const ll MOD = 1e6 + 7;
const int MAX = 1001;
int n, m, temp;
vector<int> men;
vector<int> women;
int dp[MAX][MAX];


int main()
{
	FAST
	cin >> n >> m;
	int dp[n+1][m+1];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        men.push_back(temp);
    }
    for (int j = 0; j < m; j++) {
        cin >> temp;
        women.push_back(temp);
    }
	memset(dp, 0, sizeof(dp));   dp[0][0]=0;
    sort(men.begin(), men.end());
    sort(women.begin(), women.end());
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                dp[i][j] = dp[i-1][j-1] + abs(men[i-1] - women[j-1]);
            }
            else if (i > j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(men[i-1] - women[j-1]));
            }
            else if (j > i) {
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + abs(men[i-1] - women[j-1]));
            }
        }
    }
    
    cout << dp[n][m];
    return 0;
}