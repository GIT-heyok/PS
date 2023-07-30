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
// #define endl '\n'
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
const ll MOD = 1e4 + 7;
int main()
{
    FAST int n, k;
    cin >> n >> k;
    if (n >= k)
        cout << n - k << endl;
    else
    {

        int memo[150001];
        fill(memo, memo + 150001, inf);
        memo[n] = 0;
        priority_queue<pI> q;
        q.push({0, n});
        while (!q.empty())
        {
            int val = -q.top().first;
            int node = q.top().second;
            q.pop();
            // cout<<val<<node<<endl;
            if (node == k)
                break;
            if (node * 2 <= 150000)
            {
                if (memo[node * 2] > val)
                {
                    q.push({-val, node * 2});
                    memo[node * 2] = val;
                }
            }
            if (node + 1 <= 150000)
            {
                if (memo[node + 1] > val + 1)
                {
                    memo[node + 1] = val + 1;
                    q.push({-val - 1, node + 1});
                }
            }
            if (node - 1 >= 0)
            {
                if (memo[node - 1] > val + 1)
                {
                    memo[node - 1] = val + 1;
                    q.push({-val - 1, node - 1});
                }
            }
        }
        cout << memo[k] << endl;
    }
}