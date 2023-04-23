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

const int MAX = 1001;
const ll INF = 1e12;
const int inf = 1e6;
const ll MOD = 10007;
/*
conterexample: n=1 -> in my algorithm: it is inf
else, dp[i] += min(dp[nxt], line) for all nxt 
*/
int memo[MAX];
bool visited[MAX];
int arr[MAX][MAX];
int N;
int dfs(int n)
{
    if (memo[n] != -1)
        return memo[n];
    if (visited[n])
        return inf;
    visited[n] = true;
    int &temp = memo[n];
    temp = 0;
    for (int i = 1; i <= N; i++)
    {
        if (n == i)
            continue;
        if (arr[n][i] < inf)
        {

            int nxtCost = arr[n][i];
            if (!visited[i])
                temp += min(nxtCost, dfs(i));
        }
    }
    if (temp == 0)
        return inf;
    return temp;
}

int main()
{
    FAST;
    int T;
    cin >> T;
    while (T--)
    {
        int m;
        cin >> N >> m;
        for (int i = 0; i <= N; i++)
        {
            memo[i] = -1;
            visited[i] = false;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                arr[i][j] = inf;
            }
        }

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            arr[a][b] = min(arr[a][b], c);
            arr[b][a] = min(arr[b][a], c);
        }
        if(n==1){
            cout<<0<<endl;
        }
        else
        cout << dfs(1) << endl;
    }
}