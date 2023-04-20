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

//dfs + dp
int main()
{
    FAST;
    int n;
    cin >> n;
    char cards[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cards[i];
    }

    int m, k;
    cin >> m >> k;
    vector<pair<int, char>> trees[m + 1];
    for (int i = 0; i < k; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        trees[a].push_back({b, c});
        trees[b].push_back({a, c});
    }
    int memo[n + 1][m + 1];
    fill(&memo[0][0], &memo[n][m + 1], -inf);
    for (auto temp : trees[1])
    {
        if (temp.second == cards[1])
        {
            memo[1][temp.first] = 10;
        }
        else
        {
            memo[1][temp.first] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (memo[i][j] >= 0)
            {
                for (auto temp : trees[j])
                {
                    if (temp.second == cards[i + 1])
                    {
                        memo[i + 1][temp.first] = max(memo[i + 1][temp.first], memo[i][j] + 10);
                    }
                    else
                    {
                        memo[i + 1][temp.first] = max(memo[i + 1][temp.first], memo[i][j]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, memo[n][i]);
    }
    cout << ans << endl;
}